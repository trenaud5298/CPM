#ifndef CPM_REGISTRY_H
#define CPM_REGISTRY_H



namespace CPM {

    template <typename T>
    class Registry {
    public:
        static bool add(const std::string& reference, std::function<std::unique_ptr<T>()> ctor) {
            get()[reference] = ctor;
            return true;
        }
        
        static std::unique_ptr<T> create(const std::string& reference) {
            auto& reg = get();
            auto it = reg.find(reference);
            return (it != reg.end()) ? it->second() : nullptr;
        }

        static std::vector<std::string> keys() {
            std::vector<std::string> keys;
            for (auto& [key, _] : get()) {
                keys.push_back(key);
            }
            return keys;
        }
        
    private:
        static std::map<std::string, std::function<std::unique_ptr<T>()>>& get() {
            static std::map<std::string, std::function<std::unique_ptr<T>()>> instance;
            return instance;
        }
    };

}

#define REGISTER_TYPE(Base, Derived, Name) \
    inline static bool _reg_##Derived = Registry<Base>::add( \
        Name, []() { return std::make_unique<Derived>(); } \
    )


#endif