#include <iostream>
using namespace std;

class Manager
{
public:
    static int counter;

private:
    Manager()
    {
        counter++;
    }

public:
    Manager *getInstance()
    {
        return new Manager();
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
    Manager *m = NULL;
    m = m->getInstance();
    m->printTotalManagers(); 

    m = m->getInstance();
    m->printTotalManagers();

    // There should be only one manager!
    // After making constructor private, we still have more than 1 managers;
}