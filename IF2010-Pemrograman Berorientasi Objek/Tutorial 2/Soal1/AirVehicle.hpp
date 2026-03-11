#pragma once
#include "Vehicle.hpp"

class AirVehicle : public Vehicle {
protected:
    int maxAltitude;

public:
    AirVehicle(string vehicleId, string brand, int maxSpeed, int maxAltitude);
    ~AirVehicle();

    string getBrandName() const;
    void fly(string dest) const;
    string showSpec() const;
};