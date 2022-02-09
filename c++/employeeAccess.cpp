#include <iostream>

using namespace std;

class group_1  {
    public:
        void find(void);
};

class group_2 {
    public:
        void add(void);
        void modify(void);
};

class group_3:public group_2 {
    public:
        void remove(void);
};

group_1 everyone;
group_2 select_few;
group_3 health;

void group_1::find(void)
{
    cout << "Inside group_1 find()" << endl;
}

void group_2::add(void)
{
    cout << "Inside group_2 add()" << endl;
}

void group_2::modify(void)
{
        cout << "Inside group_2 modify()" << endl;
}

void group_3::remove(void)
{
        cout << "Inside group_3 remove()" << endl;
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