#pragma once

#include <string>
#include <vector>

#include "Cargo.hpp"

class Ship {
public:
    Ship()
        : id_(-1) {}
    Ship(int id, std::string name, size_t speed, size_t maxCrew, size_t capacity)
        : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity) {}
    Ship(int id, size_t speed, size_t maxCrew)
        : Ship(id, "defaultName", speed, maxCrew, 0) {}

    Ship& operator+=(size_t crew);
    Ship& operator-=(size_t crew);

    int getId() const { return id_; }
    std::string getName() const { return name_; }
    size_t getSpeed() const { return speed_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getCapacity() const { return capacity_; }
    size_t getAvailableSpace() const {return countAvailableSpace();}
    
    void setName(const std::string& name) { name_ = std::move(name); }

private:
    size_t countAvailableSpace() const;

    const int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
    std::vector<Cargo> cargos_;
};
