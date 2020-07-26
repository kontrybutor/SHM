#include "Cargo.hpp"
#include "Player.hpp"

enum class Response { Done, LackOfMoney, LackOfCargo, LackOfSpace };

class Store {
public:
    Store() {}
    ~Store() {}
    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
};
