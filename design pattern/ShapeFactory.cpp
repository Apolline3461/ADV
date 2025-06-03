//
// Created by Apoll on 26/05/2025.
//

#include "ShapeFactory.hpp"
#include "Circle.hpp"
#include "Square.hpp"

IShape *ShapeFactory::createShape(const std::string type) {
    if (type == "circle")
        return new Circle();
    if (type == "square")
        return new Square();
    return nullptr;
}
