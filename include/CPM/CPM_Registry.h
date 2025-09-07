#ifndef CPM_REGISTRY_H
#define CPM_REGISTRY_H

#include <string>
#include <unordered_map>
#include <memory>

namespace CPM {

template <typename T>
class Registry {
public:
    static bool Register(const std::string& reference, std::function<std::unique_ptr<T>()> ctor) {
        registry()[reference] = ctor;
        return true;
    }
    
    static std::unique_ptr<T> Create(const std::string& reference) {
        std::map<std::string, std::function<std::unique_ptr<T>()>>& reg = registry();
        std::map<std::string, std::function<std::unique_ptr<T>()>>::iterator it = reg.find(reference);
        return (it != reg.end()) ? it->second() : nullptr;
    }

    static std::vector<std::string> Keys() {
        std::vector<std::string> keys;
        for (auto& [key, _] : registry()) { //Ignore Function And Only Focus On Key
            keys.push_back(key);
        }
        return keys;
    }
    
private:
    static std::map<std::string, std::function<std::unique_ptr<T>()>>& registry() {
        static std::map<std::string, std::function<std::unique_ptr<T>()>> instance;
        return instance;
    }

}; //class Registry

} //namespace CPM

#define REGISTER_TYPE(Base, Derived, Name) \
    inline static bool _reg_##Derived = Registry<Base>::Register( \
        Name, []() { return std::make_unique<Derived>(); } \
    )


#endif