//
// Created by Apoll on 26/05/2025.
//

#ifndef DESIGN_PATTERN_SUBJECT_HPP
#define DESIGN_PATTERN_SUBJECT_HPP


#include <vector>
#include <algorithm>
#include "IObserver.hpp"

class Subject {
private:
    std::vector<IObserver*> observers;
public:
    void registerObserver(IObserver *observer) {
        observers.push_back(observer);
    }

    void removeObserver(IObserver* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(const Event &evt) {
        for (auto observer : observers) {
            observer->update(evt);
        }
    }
};


#endif //DESIGN_PATTERN_SUBJECT_HPP
