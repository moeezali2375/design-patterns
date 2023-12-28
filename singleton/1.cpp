#include <iostream>
using namespace std;

class Manager
{
public:
    static int counter;

    Manager()
    {
        counter++;
    }
    void printTotalManagers()
    {
        cout << "Total Managers: " << counter << "!\n";
    }
};

int Manager::counter = 0;
// Syntax to initialize static variable

int main()
{
    Manager *m;

    m = new Manager();//! 1
    m->printTotalManagers();

    m = new Manager();//! 2
    m->printTotalManagers();

    // There should be only one manager!
}