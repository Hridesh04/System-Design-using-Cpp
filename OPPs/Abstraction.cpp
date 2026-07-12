#include <iostream>
#include <string>

using namespace std;

//Real life car

class Car{

public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;    
    virtual ~Car() {} 

};

class SportsCar : public Car {
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentGear;
    int currentSpeed;

    SportsCar(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }

    void shiftGear(int gear){
        if (!isEngineOn){
            cout << brand << " " << model << " engine is not on. Please start the engine first." << endl;
            return;
        }
        currentGear=gear;
        cout << "Gear shifted to " << currentGear << " for " << brand << " " << model << endl;
    }

    void accelerate(){
        if (!isEngineOn){
            cout << brand << " " << model << " engine is not on. Please start the engine first." << endl;
            return;
        }

        currentSpeed += 20;
        cout << brand << " " << model << " accelerated to " << currentSpeed << " km/h" << endl;

    }

    void brake(){
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " slowed down to " << currentSpeed << " km/h" << endl;

    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << "Engine stopped for " << brand << " " << model << endl;
    }
};

// main Method

int main(){

    SportsCar * mySportsCar = new SportsCar("Ferrari", "488 Spider");

    mySportsCar->startEngine();
    mySportsCar->shiftGear(1);
    mySportsCar->accelerate();
    mySportsCar->shiftGear(2);
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->stopEngine();

    

    return 0;

}