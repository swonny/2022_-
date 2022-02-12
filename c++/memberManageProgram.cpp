#include <iostream>
#define MAX 100

using namespace std;

class Client_l1 { // 고객 등급 1
    public:
        int number;
        int point;
        int level; // static ?
        int discount; // static ?
        Client_l1(int _number, int point = 0, int level = 1, int discount = 0); // 생성자
        void buy(void);
        void get_discount(void);
        void output(void);
};

/* 전역변수 - 클라이언트 포인터 리스트 */
Client_l1 *client_list[MAX];

class Client_l2 : public Client_l1 { // 고객 등급 2
    public:
        Client_l2(int number);
};

class Client_l3 : public Client_l1 { // 고객 등급 3
    public:
        Client_l3(int number);
};

class Retrieve { // 검색
    public:
        int search_num(Client_l1 *member);
        void is_member(void);
        int find_last(void);
        void print_error(void);
};

class Modify : public Retrieve { // 수정
    public:
        void modify_info(void);
};

class Add : public Retrieve { // 추가
    public:
        void add_member(Client_l1 *new_member);
        void print_error(void);
};

class Del : public Retrieve { // 삭제
    public:
        void del_member(Client_l1 *del_member);
};

class LevelManager : public Retrieve { // 레벨 관리
    public:
        void level_manage(int idx);
        void level_up(int idx);
        void print_error(void);
};

Retrieve retrieve;
Add add;
Modify modify;
Del del;
LevelManager levelManager;

/* 고객_l1 클래스 메소드 */
void Client_l1::buy(void)
{
    cout << "Inside buy()" << endl;
    point ++;
    get_discount();
    levelManager.level_manage(retrieve.search_num(this));
}

Client_l1::Client_l1(int _number, int _point, int _level, int _discount) // l1 생성자
{
    number = _number;
    point = _point;
    level = _level;
    discount = _discount;
}

void Client_l1::get_discount(void)
{
    cout << discount << "% 할인되어 적용됩니다!" << endl;
}

/* 검색 클래스 메소드 */
void Retrieve::print_error(void)
{
    cout << "일치하는 정보가 없습니다." << endl;
}

int Retrieve::find_last(void)
{
    int i = 0;
    while(client_list[i] != NULL && i < MAX) {
        i++;
    }
    return i;
}

int Retrieve::search_num(Client_l1 *member)
{
    cout << "Inside search_num()" << endl;
    int i = 0;
    while(client_list[i] != NULL && client_list[i] != member) {
        i++;
    }
    if(client_list[i] == NULL) {
        print_error();
        return -1;
    }
    return i;
}

/* 추가 클래스 메소드 */
void Add::print_error(void)
{
    cout << "이미 등록되어있는 회원입니다." << endl;
}

void Add::add_member(Client_l1 *new_member)
{
    cout << " Inside add_member()" << endl;
    int idx = search_num(new_member); // return값 변경하기
    if(idx != -1) {
        print_error();
        return;
    }
    client_list[find_last()] = new_member;
}

/* 삭제 클래스 메소드 */
void Del::del_member(Client_l1 *del_member)
{
    cout << "Inside del_member()" << endl;
    int idx = search_num(del_member);
    if(idx == -1) {
        print_error();
        return;
    }
    client_list[idx] = NULL;
}

/* 레벨관리 클래스 메소드 */
void LevelManager::print_error()
{
    cout << "현재 최고 레벨입니다." << endl;
}

void LevelManager::level_up(int idx)
{
    Client_l1 *temp = client_list[idx];
    if(temp->level != 3) {
        (temp->level) ++;
        (temp->point) = 0;
        (temp->discount) += 10;
    } 
}

void LevelManager::level_manage(int idx)
{
    cout << "Inside get_point()" << endl;
    if(client_list[idx]->point >= 10) {
        level_up(idx);
        cout << "레벨업 되었습니다." << endl;
    }
}

int main() {
    Client_l1 clientL1(1);
    // Client_l2 clientL2(2);
    // Client_l3 clientL3(3);

    add.add_member(&clientL1);
    // add.add_member(&clientL2);
    // add.add_member(&clientL3);

    // del.del_member(&clientL2);
    // retrieve.search_num(&clientL2);

    for(int i = 0; i < 10; i ++) {
        clientL1.buy();
    }

    cout << client_list[retrieve.search_num(&clientL1)]->number << endl; // 정보 print 함수 추가 필요
    cout << client_list[retrieve.search_num(&clientL1)]->level << endl; // 정보 print 함수 추가 필요
    cout << client_list[retrieve.search_num(&clientL1)]->discount << endl; // 정보 print 함수 추가 필요


    for(int i = 0; i < 10; i ++) {
        clientL1.buy();
    }


    cout << client_list[retrieve.search_num(&clientL1)]->number << endl; // 정보 print 함수 추가 필요
    cout << client_list[retrieve.search_num(&clientL1)]->level << endl; // 정보 print 함수 추가 필요
    cout << client_list[retrieve.search_num(&clientL1)]->discount << endl; // 정보 print 함수 추가 필요
}