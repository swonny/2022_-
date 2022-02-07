#include <iostream>
using namespace std;

int function_1(int a);

int main() {
    int a = 10;
    int &b = a;

    a = function_1(b);

    cout<<"after function_1() b is "<<b<<"\n";
    cout<<"after function_1() a is "<<a<<"\n";
}

int function_1(int a)
{
    a = a+10;
    return a;
}