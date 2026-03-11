#pragma once
#include "Vehicle.hpp"

class WaterVehicle: public Vehicle {
protected:
    int displacement;

public:
    WaterVehicle(string vehicleId, string brand, int maxSpeed, int displacement);
    ~WaterVehicle();

    void sail(string dest) const;
    string showSpec() const;
};