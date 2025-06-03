//
// Created by Apoll on 03/06/2025.
//

#ifndef DESIGN_PATTERN_BUBBLESORT_HPP
#define DESIGN_PATTERN_BUBBLESORT_HPP

#include "ISortStrategy.hpp"

class BubbleSort : public ISortStrategy {
public:
    void sort(std::vector<int> &data) override;
};


#endif //DESIGN_PATTERN_BUBBLESORT_HPP
