#include <iostream>

using namespace std;

class Car {
	enum {
		off = 0,
		left = 1,
		right = 2
	};
	bool isStarted;
	int speed;
	short turn;
public:
	Car() {
		isStarted = false;
		speed = 0;
		turn = off;
	}
	
	void startEngine() {
		isStarted = true;
	}

	void stopEngine() {
		isStarted = false;
	}

	void accelerate(int speed) {
		this->speed = speed;
	}

	void brake() {
		this->speed = 0;
	}

	void turnLeft() {
		this->turn = left;
	}

	void turnRight() {
		this->turn = right;
	}

	void turnOff() {
		this->turn = off;
	}
};

class CarFacade {
	Car car;
public:
	void startCar() {
		car.startEngine();
		cout << "Car started" << endl;
	}

	void stopcar() {
		car.brake();
		car.stopEngine();
		cout << "Car stoped" << endl;
	}

	void drive(int speed) {
		car.startEngine();
		car.accelerate(speed);
		cout << "Car accelerated to " << speed << endl;
	}

	void turn(string direction) {
		if(direction == "left") {
			car.turnLeft();
			cout << "Car turned left" << endl;
			car.turnOff();
		}
		else if (direction == "right") {
			car.turnRight();
			cout << "Car turned right" << endl;
			car.turnOff();
		}
		else { return; }
	}
};

void main() {
	CarFacade car;
	car.startCar();
	car.drive(20);
	car.turn("right");
	car.drive(50);
	car.turn("left");
	car.stopcar();
	cout << "\n###################################################################\n\n";
}