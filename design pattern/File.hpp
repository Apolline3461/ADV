//
// Created by Apoll on 03/06/2025.
//

#ifndef DESIGN_PATTERN_FILE_HPP
#define DESIGN_PATTERN_FILE_HPP


#include <utility>

#include "IFileSystemItem.hpp"

class File : public IFileSystemItem {
private:
    std::string _name;
    int _size;
public:
    File(std::string name, int size): _name(std::move(name)), _size(size) {};
    [[nodiscard]] std::string getName() const override;
    [[nodiscard]] int getSize() const override;
    void display(int indent) const override;
};


#endif //DESIGN_PATTERN_FILE_HPP
