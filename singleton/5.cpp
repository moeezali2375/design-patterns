#include <iostream>
using namespace std;

class Manager
{
private:
    static Manager *instance;

public:
    static int counter;

private:
    Manager()
    {
        counter++;
    }

public:
    static Manager *getInstance()
    {
        return instance;
    }
    void printTotalManagers()
    {
        cout << "Total Managers: " << counter << "!\n";
    }
};

int Manager::counter = 0;
//! EAGER INTIALIZATION
Manager *Manager::instance = new Manager();
// Syntax to initialize static variable

int main()
{
    Manager *m = nullptr;
    Manager *s = nullptr;

    m = m->getInstance();
    m->printTotalManagers();

    s = Manager::getInstance();
    s->printTotalManagers();

    //! Now there is only 1 manager!
    //! Eager initialization implementationa
}