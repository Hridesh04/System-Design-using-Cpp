#include<iostream>
#include<string>

using namespace std;

class Car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    // common methods for all cars.
    void startEngine(){
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << ": Engine turned off." << endl;
    }


    virtual void accelerate()=0; //Abstract method for Dynamic Polymorphism
    virtual void brake()=0;      //Abstract method for Dynamic Polymorphism
    virtual ~Car() {}            // Virtual Destructor

};


class ManualCar : public Car{
private:
    int currentGear; //specific to manual

public:
    ManualCar(string b, string m) : Car(b,m){
        currentGear = 0;
    }

    //Specialized method for manual car
    void shiftGear(int gear) {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear" << currentGear << endl;
    }

    //Overriding Accelerate - Dynamic Polymorphism
    void accelerate(){
        if (!isEngineOn){
            cout << brand << " " << model << " engine is not on. Please start the engine first." << endl;
            return;
        }

        currentSpeed += 20;
        cout << brand << " " << model << " accelerated to " << currentSpeed << " km/h" << endl;

    }

    //Overriding Brake - Dynamic Polymorphism
    void brake(){
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " slowed down to " << currentSpeed << " km/h" << endl;

    }

};

class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b,m) {
        batteryLevel = 100;
    }
    //specialized method for electric car
    void chargeBattery(){
        batteryLevel = 100;
        cout<<brand<<" "<<model<<" : Battery fully Charged"<<endl;
    }

    // Overriding Accelerate - Dynamic Polymorphism
    void accelerate(){
        if (!isEngineOn)
        {
            cout<<brand<<" "<< model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }

        if (batteryLevel == 0)
        {
            cout<<brand<<" "<< model<< " : battery Dead! cannot accelerate. "<<endl;
            return;
        }

        batteryLevel -= 10;
        currentSpeed += 15;
        cout << brand << " " << model << " : Accelerateing to " <<currentSpeed<< "Km/h. Battery at" << batteryLevel<< "%" << endl;
    }

    //Overriding Brake - Dynamic Polymorphism
    void brake(){
        currentSpeed -= 15;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " slowed down to " << currentSpeed << " km/h" << endl;

    }

};

// Main Method

int main() {
    ManualCar * myManualCar = new ManualCar("Suzuki" , "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;


    cout<<"--------------------------"<<endl;

    ElectricCar * myElectricCar = new ElectricCar("Tesla", "Model 5");
    myElectricCar->chargeBattery();
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    delete myElectricCar;

    return 0;

}