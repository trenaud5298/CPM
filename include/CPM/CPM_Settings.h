#ifndef CPM_SETTINGS_H
#define CPM_SETTINGS_H

#include <string>
#include <unordered_map>
#include <variant>
#include <stdexcept>

namespace CPM {


//These Allow Settings<CPM> and Settings<Project> To Function
struct CPM {};
struct Project {};


using SettingValue = std::variant<int, double, bool, std::string>;


template <typename Tag>
class Settings {

public:
    
    template <typename T>
    static void Set(const std::string& key, T value) {
        settings()[key] = value;
    }

    static bool Exists(const std::string& key) {
        std::unordered_map<std::string, SettingValue>& mapRef = settings();
        return mapRef.find(key) != mapRef.end();
    }

    template <typename T>
    static T Get(const std::string& key) {
        std::unordered_map<std::string, SettingValue>& mapRef = settings();
        std::unordered_map<std::string, SettingValue>::iterator it = mapRef.find(key);

        if (it == mapRef.end()) {
            throw std::runtime_error("Settings::Get - Key not found: " + key);
        }

        if (!std::holds_alternative<T>(it->second)) {
            throw std::runtime_error("Settings::Get - Type mismatch for key: " + key);
        }

        return std::get<T>(it->second);
    }
    

private:
    static std::unordered_map<std::string, SettingValue>& settings() {
        static std::unordered_map<std::string, SettingValue> instance;
        return instance;
    }

};// class Settings


};// namespace CPM


#endif












// Idea For Settings:

// Settings Class,

// Allows for registering of settings, saving to and from a file.
// Think of something like:

// Settings::Register<T>(string key, T default value);

// example
// Settings::Register<int>("test setting", 100);

// Also needs to have a way to pre-register settings that will always be there, and there
// values if not detected from a file or something.


// (Alternative is to have Settings class have a way to split settings similar to the 
//  current registry class does. I.E. Settings<CPM> or something) <--- Kind of liking this more
// Then have a Settings_CPM child class that inherits all functionality but seperates to specify
// CPM Settings


// Could look something like:
// Settings_CPM::Register<boolean>("force", true)

// Or:

// Settings<CPM>::Register<boolean>("force", true)


// This way we can also have Settings_Project (Settings<Project>) without having them overlap.