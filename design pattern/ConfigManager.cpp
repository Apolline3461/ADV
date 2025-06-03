//
// Created by Apoll on 26/05/2025.
//

#include "ConfigManager.hpp"

ConfigManager *ConfigManager::getInstance() {
    if (instance == nullptr) {
        instance = new ConfigManager();
    }
    return instance;
}

void ConfigManager::setSettings(const std::string name, const int value) {
    settings[name] = value;
}

std::map<std::string, int> ConfigManager::getSettings() {
    return settings;
}
