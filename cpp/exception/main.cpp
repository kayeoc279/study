#include <iostream>
#include <string>

using namespace std;

class Tmp {
public:
    string myname;
    Tmp()
    {
        cout << "tmp is create" << endl;
        myname = "string 123";
    }
};

void do_except(int i)
{
    if (i == 0)
        // This line will new a Tmp class object
        throw Tmp();
    else {
        cout << "before  i = " << i << endl;
        do_except(i - 1);
        // This will not execute Due to throw in previos line.
        cout << "after   i = " << i << endl;
    }
}

int main()
{
    try {
        do_except(5);
    }
    catch (int e) {
        cout << "error catch " << e << endl;
    }
    catch (Tmp e) {
        cout << "error catch Tmp " << e.myname << endl;
    }
}
