// C++ standard libraries
#include <iostream>

// Own libraries
#include "bismuth/registry.hpp"

struct PositionComponent{
    int x;
    int y;
};

struct other{
    int a;
    int b;
};
struct other2{
    int a;
    int b;
};
struct foo{
    int a;
    int b;
};
struct bools{
    bool a;
    bool b;
};

int main() {
    bismuth::Registry registry;

    const size_t entity = registry.createEntity();
    const size_t entity2 = registry.createEntity();
    const size_t entity3 = registry.createEntity();

    registry.emplaceComponent<PositionComponent>(entity, 4, 2);
    registry.emplaceComponent<foo>(entity2, 1,2);

    std::cout << registry.hasComponent<PositionComponent>(entity)   << std::endl;
    std::cout << registry.hasComponent<bools>(entity) << std::endl;
    std::cout << registry.hasComponent<foo>(entity3)  << std::endl;

    std::cout << std::endl;

    auto boolPool = registry.getView<other, other2, PositionComponent>();
    
    for(auto [entity, a, b, c] : boolPool) {
        std::cout << entity << std::endl;
    }
}