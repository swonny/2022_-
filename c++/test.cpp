#include <iostream>

using namespace std;

class group_1  {
    private:
        int a;
    protected:
        int b;
    public:
        void output1(void);
};

class group_2 {
    private:
        int c;
    public:4
        void output2(void);
};

group_1 everyone;
group_2 select_few;

void group_1::output(void)
{
    c = 15;
    b += 10;
    cout << "c is" << c << " b is " << b << endl;
}

void group_2::output2(void)
{

}


int main() {
    char string[2], option = '\0';
    int i, *intptr;
    char  password[3], *charptr;
    cout << "Please enter password" << endl;
    charptr = gets(password);
    while(option != 'q') {
        cout << "Please enter option "
            << "<a>dd, <f>ind, <m>odify, <d>elete or <q>uit : ";
        cin >> option;
        switch(option){
            case 'a':
                if(i == 10 || i == 20)  {
                    select_few.add();
                } else if(i == 99) {
                    health.add();
                } else {
                    cout << "Permission denied" << endl;
                }
            case 'f':
                everyone.find();
                break;
            case 'm':
                if(i == 10 || i == 20) {
                    select_few.modify();
                } else if(i == 99) {
                    health.modify();
                } else {
                    cout << "Permission denied!" << endl;
                }
                break;
            case 'd':
                if(i == 99) {
                    health.remove();
                } else {
                    cout << "Permission denied!" << endl;
                } 
                break;
            case 'q':
                break;
            default:
                cout << "Invalid option entered!" << endl;
        }
    }
}