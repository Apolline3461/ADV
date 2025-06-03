//
// Created by Apoll on 26/05/2025.
//

#ifndef DESIGN_PATTERN_SHAPEFACTORY_HPP
#define DESIGN_PATTERN_SHAPEFACTORY_HPP

#include <string>
#include "IShape.hpp"

class ShapeFactory {
public:
    static IShape *createShape(std::string type);
};


#endif //DESIGN_PATTERN_SHAPEFACTORY_HPP
