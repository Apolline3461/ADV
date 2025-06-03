//
// Created by Apoll on 03/06/2025.
//

#ifndef DESIGN_PATTERN_DIRECTORY_HPP
#define DESIGN_PATTERN_DIRECTORY_HPP

#include <utility>
#include <vector>
#include "IFileSystemItem.hpp"

class Directory : public IFileSystemItem {
private:
    std::string _name;
    std::vector<IFileSystemItem*> items;
public:
    explicit Directory(std::string name) : _name(std::move(name)) {};
    void add(IFileSystemItem *item);
    void remove(IFileSystemItem *item);
    [[nodiscard]] std::string getName() const override;
    int getSize() const override;
    void display(int indent) const override;
    ~Directory() override;
};


#endif //DESIGN_PATTERN_DIRECTORY_HPP
