#include "AirVehicle.hpp"

AirVehicle::AirVehicle(string vehicleId, string brand, int maxSpeed, int maxAltitude)
           :Vehicle(vehicleId, brand, maxSpeed), maxAltitude(maxAltitude) {
    cout << "[CREATE] AirVehicle " << brand << " at max altitude " << maxAltitude << "m ready\n";
}

AirVehicle::~AirVehicle() {
    cout << "[DELETE] AirVehicle " << brand << " destroyed\n";
}

string AirVehicle::getBrandName() const {
    return brand;
}

void AirVehicle::fly(string dest) const{
    cout << "[FLY] " << brand << " (max " << maxAltitude << "m) " << "flying to " << dest << endl;
}

string AirVehicle::showSpec() const{
    return getVehicleId() + " | " + getBrandName() + " | " + "MaxSpeed: " + to_string(maxSpeed);
}