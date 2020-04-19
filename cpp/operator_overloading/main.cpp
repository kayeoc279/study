#include <iostream>

using namespace std;

class Test {
    string name;
    int id;

public:
    Test() : id(0), name("")
    {
    }
    Test(int id, string name) : id(id), name(name)
    {
    }
    void print()
    {
        cout << id << " " << name << endl;
    }
    const Test& operator=(const Test& other)
    {
        cout << "Assignment operator" << endl;
        id = other.id;
        name = other.name + "_assign";

        return *this;
    }
};

int main()
{
    Test test1(12, "bob");
    Test test2(15, "cat");

    test1.print();
    test2.print();

    test2 = test1;

    test1.print();
    test2.print();

    // copy constructor not assignment operator
    Test test3 = test2;
    test3.print();
}
