#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> // для работы std::abs()-возвращает значение по модулю
//функтор - обьект у которого перегружен  оператор круглые скобки ()
#include "Printer.h"
#include <memory>
#include "IVehicle.h"
using namespace Engine;
class Incrementer {
public:
	Incrementer(int x):_x(x) {}
	int operator()(int y) { 
		return _x + y;
	}
	int myfunc(int y) {
		const auto add = [this,y](int a) {//для захвата приватных полей прокидываем [this]-по ссылке
			return _x + y + a;
		};//;- после лямбда выражения
		return add(6);
	}
private:
	int _x;
};
class Car :public IVehicle {
public:
	Car(int speed) :_speed(speed) {}
	int GetSpeed()const override {
		return _speed;
	}
	void printType()const override {
		std::cout << "Car\n";
	}
private:
	int _speed;

};
class Bus :public IVehicle {
	Bus(int speed) :_speed(speed) {}
	int GetSpeed()const override {
		return _speed;
	}
	void printType()const override {
		std::cout << "Bus\n";
	}
private:
	int _speed;

};
class Motorcycle :public IVehicle {
	Motorcycle(int speed) :_speed(speed) {}
	int GetSpeed()const override {
		return _speed;
	}
	void printType()const override {
		std::cout << "Motorcycle\n";
	}
private:
	int _speed;

};
int main() {
	std::shared_ptr<IVehicle> v = std::make_shared<Car>(50);
	std::cout << "Vehickle speed: " << v->GetSpeed() << std::endl;
	v->printType();
	std::cout << "+++++++++++\n";
	setlocale(LC_ALL, "Russian");
	Incrementer inc(50);
	int a =	inc(4);
	std::cout << a << '\n';
	//lambda
	const auto myinc = [a](int num){//можно определить захват по умолчанию < [=,&а]- захватить все , только 'а' по ссылке.[&,a]-все по ссылке, a -копируем>
		return num + a;
	};
	std::cout << myinc(7) << '\n';
	std::cout << inc.myfunc(8) << '\n';
	std::cout << "___________________________\n";
	std::vector<int> vec{ 1 , -4 , 3 , -2 };
	for (const auto el : vec) {
		std::cout << el << ", ";
	}
	std::cout << std::endl;
	std::sort(vec.begin(), vec.end());//сортировка вектора
	for (const auto el : vec) {
		std::cout << el << ", ";
	}
	std::cout << std::endl;
	std::sort(vec.begin(), vec.end(), [](int a, int b) {
		return	std::abs(a) < std::abs(b);
		});
	for (const auto el : vec) {
		std::cout << el << ", ";
	}
	std::cout << std::endl;
	//namespace
	Printer p;
	p.printDefault();
	std::cout << "+++++++++++++++\n";
	std::shared_ptr<IVehicle> car = std::make_shared<Car>(90);
	std::shared_ptr<IVehicle> bus = std::make_shared<Bus>(60);
	std::shared_ptr<IVehicle> moto = std::make_shared<Motorcycle>(120);
	Printer Veh;
	Veh.AddVeh(car);
	Veh.AddVeh(bus);
	Veh.AddVeh(moto);

	return 0;
}