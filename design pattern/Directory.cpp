//
// Created by Apoll on 03/06/2025.
//

#include <algorithm>
#include <iostream>
#include "Directory.hpp"

void Directory::add(IFileSystemItem *item) {
    items.push_back(item);
}

void Directory::remove(IFileSystemItem *item) {
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

std::string Directory::getName() const {
    return _name;
}

int Directory::getSize() const {
    int size = 0;

    for (auto &item : items)
        size += item->getSize();
    return size;
}

Directory::~Directory() {
    for (auto item: items)
        delete item;
}

void Directory::display(int indent) const {
    std::string indentation(indent, ' ');
    std::cout << indentation << _name << "/" << std::endl;

    for (const auto& item : items) {
        item->display(indent + 2); // indent augmente à chaque niveau
    }
}
