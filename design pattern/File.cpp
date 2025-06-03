//
// Created by Apoll on 03/06/2025.
//

#include <iostream>
#include "File.hpp"

std::string File::getName() const {
    return _name;
}

int File::getSize() const {
    return _size;
}

void File::display(int indent) const {
    std::string indentation(indent, ' ');
    std::cout << indentation << _name << " (" << _size << " KB)" << std::endl;
}
