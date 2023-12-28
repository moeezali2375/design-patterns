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

//! Adaptee class: This class is not compatible and it wants an adapter
class Device110V
{
public:
    void operateAt110V(int temp)
    {
        cout << "Operating at 110V" << endl;
    }
};

//! Target class
class Target
{
public:
    virtual void operateAt220V(string temp) = 0;
};

//! Adapter class: This class will covert 220V to 110V
class adapter : public Target, Device110V
{
public:
    void operateAt220V(string temp)
    {
        // HELP logic to convert 220V to 110V
        cout << "Converting 220V to 110V" << endl;
        int temp1 = stoi(temp);
        operateAt110V(temp1);
    }
};

int main()
{
    Target *bulbAdapter = new adapter();
    bulbAdapter->operateAt220V("123"); 
}
//! Class Adapter Implementation, it uses double inheritance;