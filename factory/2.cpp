#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void printVehicleInfo() = 0;
    virtual ~Vehicle() {}
};

class TwoWheeler : public Vehicle
{
public:
    void printVehicleInfo()
    {
        cout << "I am two wheeler" << endl;
    }
};

class ThreeWheeler : public Vehicle
{
public:
    void printVehicleInfo()
    {
        cout << "I am three wheeler" << endl;
    }
};

class FourWheeler : public Vehicle
{
public:
    void printVehicleInfo()
    {
        cout << "I am four wheeler" << endl;
    }
};

class VehicleFactory
{
public:
    Vehicle *build(int vehicleType)
    {
        if (vehicleType == 2)
            return new TwoWheeler();
        else if (vehicleType == 3)
            return new ThreeWheeler();
        else if (vehicleType == 4)
            return new FourWheeler();
        else
            return nullptr;
    }
};

int main()
{
    VehicleFactory factory;
    Vehicle *v1;

    v1 = factory.build(2);
    v1->printVehicleInfo();

    v1 = factory.build(3);
    v1->printVehicleInfo();

    v1 = factory.build(4);
    v1->printVehicleInfo();
}
// class Client
// {
// public:
//     Client() { pVehicle = nullptr; }

//     void BuildVehicle(VehicleType vehicleType)
//     {
//         VehicleFactory *vf = new VehicleFactory();
//         pVehicle = vf->build(vehicleType);

//         delete vf;
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

// private:
//     Vehicle *pVehicle;
// };

// // Driver program
// int main()
// {
//     Client *pClient = new Client();

//     pClient->BuildVehicle(VT_TwoWheeler);
//     pClient->getVehicle()->printVehicleInfo();

//     pClient->BuildVehicle(VT_ThreeWheeler);
//     pClient->getVehicle()->printVehicleInfo();

//     pClient->BuildVehicle(VT_FourWheeler);
//     pClient->getVehicle()->printVehicleInfo();

//     delete pClient;
//     return 0;
// }
