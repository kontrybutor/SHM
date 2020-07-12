#include <string>

class Cargo {
public:
    Cargo();
    Cargo(size_t amount, std::string name, size_t basePrice);
    ~Cargo();

    bool operator==(const Cargo& cargo);
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

    void print() const;
    size_t getAmount() const;
    std::string getName() const;
    size_t getPrice() const;

private:
    size_t amount_;
    std::string name_;
    size_t basePrice_;
};