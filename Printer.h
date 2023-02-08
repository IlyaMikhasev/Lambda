#pragma once
#include <vector>
#include "IVehicle.h"
#include <memory>
namespace Engine {
	class Printer
	{
	public:
		void printDefault();
		void showTypeVeh();
		void AddVeh(std::shared_ptr < IVehicle> veh);
	private:
		std::vector<std::shared_ptr<IVehicle>> _vehicle;
	};
}
