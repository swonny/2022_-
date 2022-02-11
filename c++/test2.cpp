#include <iostream>

using namespace std;

class Parent{
    public:
        virtual void output(void)
        {
            cout << "Inside Parent" << endl;
        }
};

class Child : public Parent
{
    public:
        // void output(void)
        // {
        //     cout << "Inside Child" << endl;
        // }
        void output2(void)
        {
            cout << "Inside Child output2()" << endl;
        }
};

int main() {
    Child c;
    // c.output();
    Parent *p;
    p = &c;
    p->output();
}