#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <list>
#include <cstring>
using namespace std;
class Abstract
{
public:
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3()
    {
        cout << "Default implementation of step3. This step may or may not be overriden\n";
    }
    void step4()
    {
        cout << "This step (4) is default and can not be overriden\n";
    }
    void templateMethod()
    {
        step1();
        step2();
        step3();
        step4();
    }
};

class Client1 : public Abstract
{
public:
    void step1()
    {
        cout << "Step 1 overriden by client1!\n";
    }
    void step2()
    {
        cout << "Step 2 overriden by client1!\n";
    }
};

class Client2 : public Abstract
{
public:
    void step1()
    {
        cout << "Step 1 overriden by client2!\n";
    }
    void step2()
    {
        cout << "Step 2 overriden by client2!\n";
    }
    void step3()
    {
        cout << "Step 3 overriden by client2!\n";
    }
};

int main()
{
    cout << "\n";
    Client1 pubg;
    pubg.templateMethod();

    cout << "\n";
    Client2 counterstrike;
    counterstrike.templateMethod();
}