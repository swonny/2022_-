/*
    클래스 만들기
*/
#include <iostream>
#define MAX 20
using namespace std;

class Phone{
    private:
        // char num[12];
        int point;
        int pwd;
    public:
        // char num[12];
        int num;
        void init();
        int call(void);
        int text(void);
        int checkPoint(void);
        int unlock_phone(void);
};

int main() {
    Phone seungwon;
    seungwon.init();

    cout << seungwon.checkPoint() << endl;
    cout << seungwon.num << endl;
    cout << endl;
    seungwon.call();
    seungwon.text();
}

void Phone::init()
{
    num = rand()%10;
    point = 20;
    
    cout << "비밀번호 네 자리를 입력하세요 : ";
    cin >> pwd;
}

int Phone::checkPoint(void)
{
    return point;
}

int Phone::unlock_phone(void)
{
    int t;
    cout << "비밀번호를 입력하세요 : ";
    cin >> t;
    if(pwd == t) {
        cout << "잠금이 해제되었습니다." << endl;

        return 1;
    } else {
        cout << "비밀번호가 일치하지 않습니다." << endl;

        return -1;
    }
}

int Phone::call(void)
{
    int is_locked = unlock_phone();
    if(is_locked) {
        if(checkPoint()-5 <= 0) {
            cout << "포인트가 부족합니다." << endl
                << "사용 가능 포인트 : " << checkPoint() << endl;

            return -1;
        }
        point -= 5;
        cout << "포인트가 -5 차감되었습니다." << endl;

        return 1;
    }
    return -1;
}

int Phone::text(void)
{
    int is_locked = unlock_phone();
    if(is_locked) {
        if(checkPoint()-3 <= 0) {
            cout << "포인트가 부족합니다." << endl;

            return -1;
        }
        point -= 3;
        cout << "포인트가 -3 차감되었습니다." << endl;
        
        return 1;
    }

    return -1;
}