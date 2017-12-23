#include <iostream>

class Car {
  public:
    Car(std::string newManufacturer, std::string newModel, int newYear);
    std::string manufacturer();
    void setManufacturer(std::string newManufacturer);
    std::string model();
    void setModel(std::string newModel);
    int year();
    void setYear(int newYear);
    void describe();
    int age();
  private:
    std::string _manufacturer;
    std::string _model;
    int _year;
};

Car::Car(std::string newManufacturer, std::string newModel, int newYear) {
    setManufacturer(newManufacturer);
    setModel(newModel);
    setYear(newYear);
}

std::string Car::manufacturer() {
    return _manufacturer;
}

void Car::setManufacturer(std::string newManufacturer) {
    _manufacturer = newManufacturer;
}

std::string Car::model() {
    return _model;
}

void Car::setModel(std::string newModel) {
    _model = newModel;
}

int Car::year() {
    return _year;
}

void Car::setYear(int newYear) {
    _year = newYear;
}

void Car::describe() {
    std::cout << _year << ' ';
    std::cout << _manufacturer << ' ';
    std::cout << _model << std::endl;
}

int Car::age() {
    return 2017 - _year;
    // TODO: how to get current year?
}

int main() {
    Car myCar("Chevrolet", "Impala", 1957);
    std::cout << myCar.manufacturer() << std::endl;
    std::cout << myCar.model() << std::endl;
    std::cout << myCar.year() << std::endl;
    myCar.describe();
    std::cout << myCar.age() << std::endl;
}
