#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex myMutex;

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
    //! LAZY INTIALIZATION with thread safety and double checked locking
    static Manager *getInstance()
    {
        if (instance == NULL)
        {
            unique_lock<mutex> lock(myMutex);
            //! Critical Section
            if (instance == NULL)
            {
                instance = new Manager();
            }
            lock.unlock();
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

//! Now there is only 1 manager!
//! Lazy initialization implementation with thread safety

int main()
{
    Manager *m = nullptr;
    Manager *s = nullptr;

    m = m->getInstance();
    m->printTotalManagers();

    s = Manager::getInstance();
    s->printTotalManagers();
}
