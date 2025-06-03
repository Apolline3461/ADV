//
// Created by Apoll on 26/05/2025.
//

#ifndef DESIGN_PATTERN_IOBSERVER_HPP
#define DESIGN_PATTERN_IOBSERVER_HPP


#include "Event.hpp"

class IObserver {
public:
    virtual void update(const Event& evt) = 0;
    ~IObserver() = default;
};


#endif //DESIGN_PATTERN_IOBSERVER_HPP
