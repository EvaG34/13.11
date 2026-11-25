#include <iostream>
using namespace std;

/* Дополняем предыдущее дз(транспортные средства)

1. 1. После ввода пользователя создается объект потомка.
   Объект создать через указатель на базовый класс!!!
 Инициализировать .
 Вызвать метод Print()  созданного объекта!(virtual)

Абстрактные классы
2.В базовом классе создаем следующие чисто виртуальные методы,которые переопределяются в классах-потомках!! :

 Вывод максимальной скорости
 Вывод расхода топлива
 Количество колёс
 Количество пассажиров

В функции main вызвать методы. */

class Transport
{
public:
    virtual void Print() = 0;
    virtual void MaxSpeed() = 0;
    virtual void Fuel() = 0;
    virtual void Wheels() = 0;
    virtual void Passengers() = 0;

    virtual ~Transport() {}
};

class Car : public Transport
{
public:
    string model;

    Car(string m)
    {
        model = m;
    }
    void Print()
    {
        cout << "Car: " << model << endl;
    }
    void MaxSpeed()
    {
        cout << "Max speed: 200 km/h" << endl;
    }
    void Fuel()
    {
        cout << "Fuel: 8 l" << endl;
    }
    void Wheels()
    {
        cout << "Wheels: 4" << endl;
    }
    void Passengers()
    {
        cout << "Passengers: 5" << endl;
    }
};

class Bus : public Transport
{
public:
    string model;

    Bus(string m)
    {
        model = m;
    }
    void Print()
    {
        cout << "Bus: " << model << endl;
    }
    void MaxSpeed()
    {
        cout << "Max speed: 100 km/h" << endl;
    }
    void Fuel()
    {
        cout << "Fuel: 20 l" << endl;
    }
    void Wheels()
    {
        cout << "Wheels: 6" << endl;
    }
    void Passengers()
    {
        cout << "Passengers: 50" << endl;
    }
};

int main()
{
    Transport* transport;

    int choice;
    string model;

    cout << "1 - Car" << endl;
    cout << "2 - Bus" << endl;
    cout << "Choose: ";
    cin >> choice;
    cout << "Enter model: ";
    cin >> model;

    if (choice == 1)
    {
        transport = new Car(model);
    }
    else if (choice == 2)
    {
        transport = new Bus(model);
    }
    else
    {
        cout << "Wrong choice!";
        return 0;
    }

    transport->Print();
    transport->MaxSpeed();
    transport->Fuel();
    transport->Wheels();
    transport->Passengers();

    delete transport;

    return 0;
}
