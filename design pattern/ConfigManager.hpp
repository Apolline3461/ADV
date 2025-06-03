//
// Created by Apoll on 26/05/2025.
//

#ifndef DESIGN_PATTERN_CONFIGMANAGER_HPP
#define DESIGN_PATTERN_CONFIGMANAGER_HPP


#include <map>
#include <string>

class ConfigManager {
private:
    static ConfigManager *instance;
    ConfigManager() {};

    std::map<std::string, int> settings;

public:
    static ConfigManager *getInstance();
    void setSettings(std::string name,int value);
    std::map<std::string, int> getSettings();
};


#endif //DESIGN_PATTERN_CONFIGMANAGER_HPP
