#include <iostream>
#include <string>
using namespace std;

struct carType {
    int year;
    string model;
    string plateNumber;
    carType* link;
};

class carlinkedListType {
public:
    carlinkedListType();
    bool isEmptyList() const;
    void printPlateNumber() const;
    int length() const;
    void insertCar(int year, string model, string plateNumber);

protected:
    int count;
    carType* first;
    carType* last;
};

carlinkedListType::carlinkedListType() {
    first = NULL;
    last = NULL;
    count = 0;
}

bool carlinkedListType::isEmptyList() const {
    return (first == NULL);
}

void carlinkedListType::printPlateNumber() const {
    carType* current = first;
    while (current != NULL) {
        cout << current->plateNumber << " ";
        current = current->link;
    }
    cout << endl;
}

int carlinkedListType::length() const {
    return count;
}

void carlinkedListType::insertCar(int year, string model, string plateNumber) {
    carType* newCar = new carType;
    newCar->year = year;
    newCar->model = model;
    newCar->plateNumber = plateNumber;
    newCar->link = NULL;

    if (isEmptyList()) {
        first = newCar;
        last = newCar;
    } else {
        last->link = newCar;
        last = newCar;
    }
    count++;
}

int main() {
    carlinkedListType carList;

    carList.insertCar(2021, "Tesla Model S", "ABC1234");
    carList.insertCar(2019, "Ford Mustang", "XYZ5678");

    cout << "Car Plate Numbers: ";
    carList.printPlateNumber();

    cout << "Total Cars: " << carList.length() << endl;

    return 0;
}