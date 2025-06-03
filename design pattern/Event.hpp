//
// Created by Apoll on 26/05/2025.
//

#ifndef DESIGN_PATTERN_EVENT_HPP
#define DESIGN_PATTERN_EVENT_HPP


#include <string>
#include <utility>

class Event {
public:
    std::string message;

    explicit Event(std::string msg) : message(std::move(msg)) {};
};


#endif //DESIGN_PATTERN_EVENT_HPP
