#include <iostream>
#include "ConfigManager.hpp"
#include "ShapeFactory.hpp"
#include "Subject.hpp"
#include "ConcreteObserver.hpp"
#include "SortContext.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "Directory.hpp"
#include "File.hpp"

ConfigManager *ConfigManager::instance = nullptr;

void exercise1() {

    ConfigManager * config = ConfigManager::getInstance();

    config->setSettings("Volume", 40);
    config->setSettings("brightness", 100);

    std::map<std::string, int> settings = config->getSettings();

    std::cout << "Configuration settings = " << std::endl;

    for (const auto &setting : settings) {
        std::cout << setting.first << " : " << setting.second << std::endl;
    }
}

void exercise2() {
    IShape * s1 = ShapeFactory::createShape("circle");
    IShape * s2 = ShapeFactory::createShape("square");

    if (s1) s1->draw();
    if (s2) s2->draw();

    delete s1;
    delete s2;
}

void exercise3() {
    Subject subject;

    ConcreteObserver observer1("Observer A");
    ConcreteObserver observer2("Observer B");

    subject.registerObserver(&observer1);
    subject.registerObserver(&observer2);

    Event event1("Event 1: System started");
    subject.notifyObservers(event1);

    subject.removeObserver(&observer1);

    Event event2("Event 2: Something changed");
    subject.notifyObservers(event2);
}

void exercise4() {
    std::vector<int> data;
    int n, el;

    std::cout << "Enter Number of el to sort: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers" << std::endl;
    for (int i = 0; i < n; i++) {
     std::cin >> el;
     data.push_back(el);
    }

    std::cout << "Choose sorting algorithm:\n1. Bubble Sort\n2. Quick Sort\n: ";
    std::cin >> n;

    SortContext ctx{};
    BubbleSort bubble;
    QuickSort quick;

    if (n == 1) {
        ctx.setStrat(&bubble);
    } else if (n == 2) {
        ctx.setStrat(&quick);
    } else {
        std::cout << "Invalid choice.\n";
        exercise4();
    }

    ctx.sortData(data);
    std::cout << "Sorted data:\n";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void exercise5() {
    Directory* root = new Directory("root");

    File* file1 = new File("file1.txt", 100);
    File* file2 = new File("file2.txt", 200);

    Directory* subDir = new Directory("sub");
    File* file3 = new File("file3.txt", 300);

    subDir->add(file3);
    root->add(file1);
    root->add(file2);
    root->add(subDir);

    root->display(0);

    std::cout << "Total size: " << root->getSize() << " KB" << std::endl;

    delete root;
}

int main() {
    exercise5();
    return 0;
}
