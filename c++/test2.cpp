#include <iostream>
#define MAX 100

using namespace std;

class Client_l1 { // 고객 등급 1
    public:
        int number;
        int point;
        int level; // static ?
        int discount; // static ?
        Client_l1(int _number, int point = 0, int level = 2, int discount = 0); // 생성자
        void buy(void);
        void get_discount(void);
};

Client_l1::Client_l1(int _number, int _point, int _level, int _discount)
{
    number = _number;
    point = _point;
    level = _level;
    discount = _discount;
}

class Client_l2 : public Client_l1 { // 고객 등급 2
    public:
        Client_l2(int number);
};

Client_l2::Client_l2(int number) : Client_l1 (number, 0, 2, 10)
{
}

class Client_l3 : public Client_l1 { // 고객 등급 3
    public:
        Client_l3(int number);
};

Client_l3::Client_l3(int number) : Client_l1 (number, 0, 2, 10)
{
}

class Retrieve { // 검색
    public:
        void search_num(void);
        void is_member(void);
};

Client_l1 *member_list[10];

int main() {
    Client_l1 l1(1);
    Client_l2 l2(2);
    Client_l3 l3(3);
    member_list[0] = &l1;
    member_list[1] = &l2;
    member_list[2] = &l3;

    for(int i = 0; i < 3; i ++) {
        cout << "member_" << i << " : " <<  member_list[i]->number << endl;
    }
}