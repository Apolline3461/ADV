//
// Created by Apoll on 03/06/2025.
//

#include "BubbleSort.hpp"

void BubbleSort::sort(std::vector<int> &data) {
    std::cout << "Bubble sort algo" << std::endl;

    int el = data.size();

    for (int i = 0; i < el - 1; i++) {
        for (int j = 0; j < el - i - 1; j++) {
            if (data[j] > data[j + 1])
                std::swap(data[j], data[j +1]);
        }
    }
}
