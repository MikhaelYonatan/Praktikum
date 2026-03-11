#include "LandVehicle.hpp"

LandVehicle::LandVehicle(string vehicleId, string brand, int maxSpeed, int numWheels)
            : Vehicle(vehicleId, brand, maxSpeed), numWheels(numWheels) {
    cout << "[CREATE] LandVehicle " << brand << " with " << numWheels << " wheels ready\n";
}

LandVehicle::~LandVehicle() {
    cout << "[DELETE] LandVehicle " << brand << " destroyed\n";
}

void LandVehicle::drive(string dest) const {
    cout << "[DRIVE] " << brand << " (" << numWheels << " wheels) " << "driving to " << dest << endl;
}