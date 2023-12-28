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

//! Component
class FileSystemComponent
{
public:
    virtual void display() = 0; // HELP pure virtual function
};

//! Leaf
class File : public FileSystemComponent
{
private:
    string name;
    int size;

public:
    File(const string name, int size) : name(name), size(size) {}

    void display()
    {
        cout << "File: " << name << " (" << size << " bytes)" << endl;
    }
};

//! Composite
class Folder : public FileSystemComponent
{
private:
    string name;
    vector<FileSystemComponent *> components;

public:
    Folder(string name) : name(name) {}

    void display()
    {
        cout << "Folder: " << name << endl;
        for (int i = 0; i < components.size(); i++)
        {
            components[i]->display();
        }
    }

    void addComponent(FileSystemComponent *component)
    {
        components.push_back(component);
    }
};

int main()
{
    cout << "\n";
    // Create leaf objects (files)
    File *file1 = new File("document.txt", 1024);
    File *file2 = new File("image.jpg", 2048);

    // Create a composite object (Folder)
    Folder *macOS = new Folder("macOS");

    // Add leaf objects to the macOS directory
    macOS->addComponent(file1);
    macOS->addComponent(file2);

    // Display the directory (including its contents)
    macOS->display();

    //! add another folder to macOS that has a file
    Folder *affan = new Folder("affan");
    File *file3 = new File("meTalks.txt", 1024);
    affan->addComponent(file3);
    macOS->addComponent(affan);

    cout << "\nAffan Folder: " << endl;
    affan->display();
    cout << endl;

    cout << "macOS Folder: " << endl;
    macOS->display();
    cout << endl;
}
