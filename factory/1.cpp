#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void printVehicle() = 0;
};

class TwoWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am two wheeler" << endl;
    }
};

class FourWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am four wheeler" << endl;
    }
};

class ThreeWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am 3 wheeler" << endl;
    }
};

int main()
{
    int type = 2;
    Vehicle *v1;

    if (type == 2)
    {
        v1 = new TwoWheeler();
    }
    else if (type == 4)
    {
        v1 = new FourWheeler();
    }
    else if (type==3)
    {
        v1 =new ThreeWheeler();
    }
    else
        v1 = NULL;

    v1->printVehicle();
}

// class Client
// {
// private:
//     Vehicle *pVehicle;

// public:
//     Client(int type)
//     {
//         if (type == 1)
//             pVehicle = new TwoWheeler();
//         else if (type == 2)
//             pVehicle = new FourWheeler();
//         else
//             pVehicle = NULL;
//     }

//     ~Client()
//     {
//         if (pVehicle)
//         {
//             delete pVehicle;
//             pVehicle = NULL;
//         }
//     }

//     Vehicle *getVehicle() { return pVehicle; }
// };

// int main()
// {
//     Client *pClient = new Client(1);
//     Vehicle *pVehicle = pClient->getVehicle();
//     pVehicle->printVehicle();
//     return 0;
// }
