#include "Printer.h"
#include <iostream>
using namespace Engine;
void Printer::printDefault() {
	std::cout << "Default print message\n";
}

void Printer::showTypeVeh(){
	for (const auto el : _vehicle) {
		el->printType();
	}
}

void Printer::AddVeh(std::shared_ptr < IVehicle> veh){
	_vehicle.push_back(veh);
}
