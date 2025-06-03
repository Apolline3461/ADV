//
// Created by Apoll on 03/06/2025.
//

#ifndef DESIGN_PATTERN_SORTCONTEXT_HPP
#define DESIGN_PATTERN_SORTCONTEXT_HPP

#include <vector>
#include "ISortStrategy.hpp"

class SortContext {
    ISortStrategy *strategy;
public:
    void setStrat(ISortStrategy *strat) {strategy = strat;}
    void sortData(std::vector<int> &data) {
        strategy->sort(data);
    }
};

#endif //DESIGN_PATTERN_SORTCONTEXT_HPP
