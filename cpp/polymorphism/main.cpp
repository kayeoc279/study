#include <iostream>

using namespace std;

/*! \class father
 *  \brief Brief class description
 *
 *  Detailed description
 */
class father {
public:
    father(){};
    int go()
    {
        return 0;
    }
    virtual int vgo()
    {
        // int vgo(){
        return 2;
    }

protected:
    int i; /*!< Member description */
};

/*! \class child
 *  \brief Brief class description
 *
 *  Detailed description
 */
class child : public father {
public:
    child(){};
    int go()
    {
        return 1;
    }
    int vgo()
    {
        return 3;
    }
};

int my_test(father f)
{
    return f.go();
}
int my_vgo(father* f)
{ // trigger polynorphism
    return f->vgo();
}
int my_vgo_ref(father& f)
{
    return f.vgo();
}

int main()
{
    father f;
    child c;
    cout << "hello" << endl;
    cout << f.go() << endl;        // 0
    cout << c.go() << endl;        // 1
    cout << my_test(f) << endl;    // 0
    cout << my_test(c) << endl;    // 0
    cout << my_vgo(&f) << endl;    // 2
    cout << my_vgo(&c) << endl;    // 2    ans:3
    cout << my_vgo_ref(f) << endl; // 2
    cout << my_vgo_ref(c) << endl; // 2  ans:3
}
