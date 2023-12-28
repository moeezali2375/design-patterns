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

class Subscriber
{
public:
    virtual void update() = 0;
};

class SubscriberTypeA : public Subscriber
{
public:
    void update()
    {
        //! Logic to update Subscriber, may be through email
        cout << "Email sent to Observer/Subscriber type A: " << this << endl;
    }
};

class SubscriberTypeB : public Subscriber
{
public:
    void update()
    {
        //! Logic to update Subscriber, may be through email
        cout << "Email sent to Observer/Subscriber type B: " << this << endl;
    }
};

class Publisher
{
private:
    vector<Subscriber *> subscribers;

public:
    void registerSubscriber(Subscriber *obj)
    {
        subscribers.push_back(obj);
    }
    void deleteSubscriber(Subscriber *obj)
    {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), obj), subscribers.end());
    }
    void notifySubscribers()
    {
        for (int i = 0; i < subscribers.size(); i++)
        {
            subscribers[i]->update();
        }
    }
};

int main()
{
    Publisher publisher;

    SubscriberTypeA affan, shaheer;
    SubscriberTypeB moeez;

    publisher.registerSubscriber(&affan);
    publisher.registerSubscriber(&shaheer);
    publisher.registerSubscriber(&moeez);

    //! A data change occured, now a message is broadcasted to the subscribers
    publisher.notifySubscribers();

    //! Moeez wants to stop receiving email updates;
    publisher.deleteSubscriber(&moeez);

    cout << endl;
    publisher.notifySubscribers();
}