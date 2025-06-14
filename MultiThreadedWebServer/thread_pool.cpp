//
// Created by Apoll on 14/06/2025.
//
#include "thread_pool.hpp"

std::atomic<int> ThreadPool::active_clients = 0;
std::atomic<int> ThreadPool::queued_tasks = 0;

ThreadPool::ThreadPool(size_t thread_count) : stop(false) {
    for (size_t i = 0; i < thread_count; i++)
        workers.emplace_back([this]() {worker_loop();});
}

void ThreadPool::worker_loop() {
    while (!stop) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            condition.wait(lock, [this]() { return stop || !tasks.empty();});

            if (stop && tasks.empty()) return;

            task = std::move(tasks.front());
            tasks.pop();
        }
        task();
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        queued_tasks++;
        tasks.emplace([task]() {
            queued_tasks--;
            active_clients++;
            task();

            active_clients --;
        });
    }
    condition.notify_one();
}

ThreadPool::~ThreadPool() {
    stop = true;
    condition.notify_all();
    for (auto &worker : workers) {
        if (worker.joinable())
            worker.join();
    }
}

