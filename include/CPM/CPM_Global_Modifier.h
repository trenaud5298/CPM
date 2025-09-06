#ifndef CPM_MODIFIER_H
#define CPM_MODIFIER_H

//CPM Includes:

//C++ Includes:
#include <string>
#include <functional>
#include <map>
#include <memory>

namespace CPM {
    class GlobalModifier {
    public:
        virtual ~GlobalModifier() = default;

        virtual std::string reference() const = 0;

        virtual void apply() const = 0;
    
    protected:
        static bool registerModifier(const std::string& ref,
            std::function<std::unique_ptr<GlobalModifier>()> ctor);

    private:
        static std::map<std::string, std::function<std::unique_ptr<GlobalModifier>()>>& registry();


    //Registrar:
    public:
        template <typename T>
        class Registrar {
        public:
            Registrar() {
                GlobalModifier::registerModifier(T().reference(), [] {
                    return std::make_unique<T>();
                });
            }
        };

    };
}


#endif