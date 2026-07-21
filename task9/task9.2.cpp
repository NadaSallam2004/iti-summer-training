#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed, wheels;
public:
    Vehicle(string b, int s, int w) : brand(b), speed(s), wheels(w) {}
    virtual string getType() const { return "Vehicle"; }
    virtual void displayInfo() const {
        cout << getType() << " | Brand: " << brand
            << " | Speed: " << speed << " km/h"
            << " | Wheels: " << wheels << endl;
    }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(string b, int s) : Vehicle(b, s, 4) {}
    string getType() const override { return "Car"; }
};

class Truck : public Vehicle {
    double capacity;
public:
    Truck(string b, int s, double c) : Vehicle(b, s, 6), capacity(c) {}
    string getType() const override { return "Truck"; }
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Capacity: " << capacity << " tons\n";
    }
};

class Plane : public Vehicle {
    int altitude;
public:
    Plane(string b, int s, int a) : Vehicle(b, s, 3), altitude(a) {}
    string getType() const override { return "Plane"; }
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Altitude: " << altitude << " m\n";
    }
};

class Motor : public Vehicle {
public:
    Motor(string b, int s) : Vehicle(b, s, 2) {}
    string getType() const override { return "Motorcycle"; }
};

class Bicycle : public Vehicle {
public:
    Bicycle(string b, int s) : Vehicle(b, s, 2) {}
    string getType() const override { return "Bicycle"; }
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Power: Human\n";
    }
};

// Grandchildren
class BMW : public Car {
    string model;
public:
    BMW(int s, string m) : Car("BMW", s), model(m) {}
    string getType() const override { return "BMW " + model; }
};

class Toyota : public Car {
    string model;
public:
    Toyota(int s, string m) : Car("Toyota", s), model(m) {}
    string getType() const override { return "Toyota " + model; }
};

class Boeing : public Plane {
    string model;
public:
    Boeing(int s, int a, string m) : Plane("Boeing", s, a), model(m) {}
    string getType() const override { return "Boeing " + model; }
};

class Mercedes : public Truck {
    string model;
public:
    Mercedes(int s, double c, string m) : Truck("Mercedes", s, c), model(m) {}
    string getType() const override { return "Mercedes " + model; }
};

class Honda : public Motor {
    string model;
public:
    Honda(int s, string m) : Motor("Honda", s), model(m) {}
    string getType() const override { return "Honda " + model; }
};

int main() {
    Vehicle* fleet[] = {
        new BMW(250, "M3"),
        new Toyota(180, "Corolla"),
        new Mercedes(120, 18.5, "Actros"),
        new Boeing(900, 11000, "747"),
        new Honda(200, "CBR600RR"),
        new Bicycle("Trek", 30)
    };

    for (auto v : fleet) {
        v->displayInfo();
        cout << "---------------------\n";
        delete v;
    }
    return 0;
}
