//
// Created by Apoll on 27/05/2025.
//

#ifndef DESIGN_PATTERN_CONCRETEOBSERVER_HPP
#define DESIGN_PATTERN_CONCRETEOBSERVER_HPP

#include <iostream>
#include <utility>
#include "IObserver.hpp"

class ConcreteObserver : public IObserver {
private:
    std::string name;
public:
    explicit ConcreteObserver(std::string observerName) : name(std::move(observerName)) {};

    void update(const Event &evt) override {
        std::cout << "[" << name << "] received event: " << evt.message << std::endl;
    }
};
#endif //DESIGN_PATTERN_CONCRETEOBSERVER_HPP
