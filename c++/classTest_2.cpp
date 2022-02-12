#include <iostream>

using namespace std;

int member_list[100] = {100, 200, 300, 400, 500, 600}; // 각 요소는 id

class Retrieve { // 레코드 검색
    public:
        int search(int member_number);
        virtual void print_error(void);
        virtual void print_success(void);
};

class Add : public Retrieve { // 레코드 추가
    public:
        void add_member(int member_number);
        void print_error(void);
};

class Modify : public Retrieve { // 레코드 수정
    public:
        void modify_info(int member_number, int new_number);
};

class Del : public Retrieve { // 레코드 삭제
    public:
        void delete_member(int memebr_number);
};

/* Retrieve:: */
int Retrieve::search(int member_number)
{
    int i;
    for(i = 0; i < 6; i ++) {
        if(member_list[i] == member_number) {
            print_success();
            return i;
        }
    }
    return -1;
}

void Retrieve::print_error(void)
{
    cout << "찾는 정보가 없습니다." << endl;
}

void Retrieve::print_success(void)
{
    cout << "함수가 정상적으로 수행되었습니다." << endl;
}
/* Retrieve:: */

/* Add:: */
void Add::add_member(int member_number)
{
    int idx = search(member_number);
    if(idx != -1) {
        print_error();
        return;
    }
    print_success();
}

void Add::print_error(void)
{
    cout << "이미 존재하는 정보입니다." << endl;
}
/* Add:: */

/* Modify:: */
void Modify::modify_info(int member_number, int new_number) 
{
    int idx = search(member_number);
    if(idx == -1) {
        print_error();
        return;
    }
    member_list[idx] = new_number;
    print_success();
}
/* Modify:: */

/* Del:: */
void Del::delete_member(int memebr_number)
{
    int idx = search(memebr_number);
    if(idx == -1) {
        print_error();
        return;
    }
    member_list[idx] = -1;
    print_success();
}
/* Del:: */

int main() {
    Retrieve *ptr;
    Retrieve retrieve;
    Add add;
    Modify modify;
    Del del;

    add.add_member(700);

    for(int i = 0; i < 6; i ++) {
        cout << "memeber_list[" << i << "] is " << member_list[retrieve.search(member_list[i])] << endl;
    }

    modify.modify_info(300, 900);
    cout << member_list[retrieve.search(900)] << endl;

    del.delete_member(900);
    for(int i = 0; i < 6; i ++) {
        cout << "memeber_list[" << i << "] is " << member_list[retrieve.search(member_list[i])] << endl;
    }

}