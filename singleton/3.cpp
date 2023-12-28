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
    //! LAZY INTIALIZATION
    static Manager *getInstance()
    {
        //! critical section
        if (instance == NULL)
        {
            instance = new Manager();
        }
        return instance;
    }
    void printTotalManagers()
    {
        cout << "Total Managers: " << counter << "!\n";
    }
};

int Manager::counter = 0;
Manager *Manager::instance = NULL;
// Syntax to initialize static variable

int main()
{
    Manager *m = nullptr;
    Manager *s = nullptr;

    m = m->getInstance();
    m->printTotalManagers();

    s = s->getInstance();
    s->printTotalManagers();

    //! Now there is only 1 manager!
    //! Lazy initialization implementation with no thread safety
}