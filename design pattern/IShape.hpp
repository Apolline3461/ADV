//
// Created by Apoll on 26/05/2025.
//

#ifndef DESIGN_PATTERN_ISHAPE_HPP
#define DESIGN_PATTERN_ISHAPE_HPP

class IShape {
public:
    virtual void draw() = 0;
    virtual ~IShape() = default;
};
#endif //DESIGN_PATTERN_ISHAPE_HPP
