//
// Created by Apoll on 14/06/2025.
//

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory>

struct Node {
    int x, y;
    double g, h;
    std::shared_ptr<Node> parent; // is better to use smart pointer instead of a *
    Node(int x, int y, double g, double h, std::shared_ptr<Node> parent) : x(x), y(y), g(g), h(h), parent(std::move(parent)) {}
    double f() const { return g + h; }
    bool operator>(const Node& other) const { return f() > other.f();}
};

struct CompareNode {
    bool operator()(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) const {
        return a->f() > b->f();
    }
}; // Greater is not able to compare correctly the shared_ptr, so it's better to have a dedicate function

double heuristic(int x1, int y1, int x2, int y2) {
    return  std::abs(x2 - x1) + std::abs(y2 - y1); // this methode is better than sqrt
}

bool isValid(int x, int y, int rows, int cols, const std::vector<std::vector<bool>>& obstacles) {
    return x >= 0 && x < rows && y >= 0 && y < cols && !obstacles[x][y];
}

std::vector<std::pair<int, int>> aStar(int startX, int startY, int goalX, int goalY, int rows, int cols, const std::vector<std::vector<bool>>& obstacles) {
    std::priority_queue<std::shared_ptr<Node> , std::vector<std::shared_ptr<Node> >, CompareNode> openSet;
    std::vector<std::vector<uint8_t>> closedSet(rows, std::vector<uint8_t> (cols, 0)); //is better to use an uint than a bool because it needs fewer operations

    auto startNode = std::make_shared<Node>(startX, startY, 0, heuristic(startX,startY, goalX, goalY), nullptr);

    openSet.push(startNode);
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    while (!openSet.empty()) {
        auto current = openSet.top();
        openSet.pop();
        if (closedSet[current->x][current->y]) continue; // to avoid checking 2 times the same Node
        if (current->x == goalX && current->y == goalY) {
            std::vector<std::pair<int, int>> path;
            while (current) {
                path.emplace_back(current->x, current->y);
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }
        closedSet[current->x][current->y] = true;

        for (int i = 0; i < 4; i++) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];
            if (isValid(newX, newY, rows, cols, obstacles) && !closedSet[newX][newY]) {
                double newG = current->g + 1;
                auto neighbor = std::make_shared<Node>(newX, newY, newG,heuristic(newX, newY, goalX, goalY), current);
                openSet.push(neighbor);
            }
        }
    }
    return {};
}

int main() {
    int rows = 15, cols = 15;
    std::vector<std::vector<bool>> obstacles(rows, std::vector<bool>
            (cols, false));
    obstacles[2][2] = true;
    int startX = 0, startY = 0;
    int goalX = 14, goalY = 14;
    std::vector<std::pair<int, int>> path = aStar(startX, startY,
                                                  goalX, goalY, rows, cols, obstacles);
    for (const auto& p : path) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << std::endl;
    return 0;
}