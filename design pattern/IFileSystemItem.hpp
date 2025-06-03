//
// Created by Apoll on 03/06/2025.
//

#ifndef DESIGN_PATTERN_IFILESYSTEMITEM_HPP
#define DESIGN_PATTERN_IFILESYSTEMITEM_HPP

#include <string>

class IFileSystemItem {
public:
    [[nodiscard]] virtual std::string getName() const = 0;
    [[nodiscard]] virtual int getSize() const = 0;
    virtual void display(int indent) const = 0;
    virtual ~IFileSystemItem() = default;
};

#endif //DESIGN_PATTERN_IFILESYSTEMITEM_HPP
