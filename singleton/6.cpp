//! 22 last question

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
class Student
{
private:
    static Student *student1; //! Moeez
    static Student *student2; //! Affan
    Student()
    {
        // implementation of constructor;
    }

public:
    Pair getPair()
    {
        Pair p1;
        if (student1 == NULL && student2 == NULL)
        {
            thread_lock();
            if (student1 == NULL && student2 == NULL)
            {
                Student *temp1 = new Student();
                Student *temp2 = new Student();
                this->student1 = temp1;
                this->student2 = temp2;
            }
            thread_unlock();
        }
        p1.x = this->student1;
        p1.y = this->student2;
        return p1;
    }
};

Student *Student::student1 = NULL;
Student *Student::student2 = NULL;

struct Pair
{
    Student *x; //! moeez
    Student *y; //! Affan
};

void foo()
{
    Pair pair1 = Student::getPair();
}

void bar()
{
    Pair pair2 = Student::getPair();
}