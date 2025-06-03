//
// Created by Apoll on 03/06/2025.
//

#ifndef DESIGN_PATTERN_QUICKSORT_HPP
#define DESIGN_PATTERN_QUICKSORT_HPP


#include "ISortStrategy.hpp"

class QuickSort : public ISortStrategy {
public:
    void sort(std::vector<int> &data) override;
    void quickSort(std::vector<int>&data, int l, int h);
    int separation(std::vector<int> &data, int l, int h);
};


#endif //DESIGN_PATTERN_QUICKSORT_HPP
