//
// Created by Apoll on 26/05/2025.
//

#ifndef DESIGN_PATTERN_SQUARE_HPP
#define DESIGN_PATTERN_SQUARE_HPP

#include <iostream>
#include "IShape.hpp"

class Square : public IShape {
public:
    void draw() override;
};


#endif //DESIGN_PATTERN_SQUARE_HPP
