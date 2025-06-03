//
// Created by Apoll on 03/06/2025.
//

#ifndef DESIGN_PATTERN_ISORTSTRATEGY_HPP
#define DESIGN_PATTERN_ISORTSTRATEGY_HPP

#include <iostream>
#include <vector>

class ISortStrategy {
public:
    virtual void sort(std::vector<int> &data) = 0;

};
#endif //DESIGN_PATTERN_ISORTSTRATEGY_HPP
