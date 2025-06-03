//
// Created by Apoll on 03/06/2025.
//

#include "QuickSort.hpp"

void QuickSort::sort(std::vector<int> &data) {
    std::cout << "Quick sort algo" << std::endl;
    quickSort(data, 0, data.size() - 1);
}

void QuickSort::quickSort(std::vector<int> &data, int l, int h) {
    if (l < h) {
        int pivot = separation(data,l,h);

        quickSort(data, l, pivot -1);
        quickSort(data,pivot + 1, h);
    }

}

int QuickSort::separation(std::vector<int> &data, int l, int h) {
    int point = data[h];

    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (data[j] < point) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i+1], data[h]);
    return i + 1;
}
