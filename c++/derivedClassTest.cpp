
/* 파생클래스 */

#include <iostream>

using namespace std;

/* 1. car */
/* 
    private : 차라면 기본적으로 갖추고 있어야하는 요소들
    protected : 차가 갖춰야하지만 차의 종류에 따라 달라질 수 있는 요소들
    public : 외부 사용자(차를 타는 사람)이라면 접근할 수 있는 요소들
 */
class Car {
    private:
        void use_of_engine(int hours);
    protected:
        int engine;
        int handle;
        int chair;
        void init_origin(void);
    public:
        void drive(int hours);
        void stop(void);
        void show_engine(void);
};

void Car::use_of_engine(int hours)
{
    if(hours < 2) {
        engine -= 2;
    } else if (hours >=2 && hours <= 4) {
        engine -= 4;
    } else {
        engine -= 6;
    }
}

void Car::init_origin(void)
{
    engine = 10;
    handle = 1;
    chair = 2;
}

void Car::show_engine(void)
{
    cout << "남은 엔진량 : " << engine << endl;
}

void Car::drive(int hours)
{
    use_of_engine(hours);
}

void Car::stop(void)
{
    engine += 1;
}

/* Bus */
class Bus:public Car {
    public:
        void init(void);
        void customer_in(int n);
};

void Bus::init(void)
{
    init_origin();
    engine = 20;
    chair = 30;
}

void Bus::customer_in(int n)
{
    cout << "승객 " << n << "명이 탑승했습니다." << endl;
}

/* Truck */
class Truck:public Car{
    private:
        int trunk;
    public:
        void init(void);
};

void Truck::init(void)
{
    init_origin();
    engine = 30;  
    trunk = 2;
}

/* 포크레인 */
class ForkCrane:public Car{
    private:
        int fork;
    public:
        void init(void);
        void use_fork(char *something);
};

void ForkCrane::init(void)
{
    init_origin();
    fork = 1;
}

void ForkCrane::use_fork(char *something)
{
    cout << "포크레인이 " << something << "을(를) 운반하고 있습니다." << endl;
}
/* 1. Car */

/* 2. Game */
class BasicCharacter {
    private:
        int level;
        int energy;
    protected:
        void level_up(void);
        void init_origin(int l);
    public:
        void play_rock_scissors_paper(int user);
        void buy_items(int amount);
        void sleep(int hours);
        void eat(void);
        void show_state();
};

void BasicCharacter::init_origin(int l)
{
    level = l;
    energy = 0;
}

void BasicCharacter::level_up(void)
{
    level ++;
    cout << "레벨 Up 되었습니다! (현재 레벨 " << level << ")";
}

void BasicCharacter::play_rock_scissors_paper(int user)
{
    int computer = rand() % 3;
    if(user == computer) {
        cout << "사용자가 이겼습니다." << endl
            << "에너지 +5!" << endl;
        
        energy += 5;
    } else {
        cout << "컴퓨터가 이겼습니다." << endl;
    }
    if(level >= 10) {
        level_up();
    }
}

void BasicCharacter::sleep(int hours) {
    if(hours <= 3) {
        energy +=5;
    } else {
        energy += 7;
    }
    if(level >= 10) {
        level_up();
    }
}

void BasicCharacter::eat(void)
{
    energy += 5;
    if(level >= 10) {
        level_up();
    }
}

void BasicCharacter::show_state(void)
{
    cout << "현재 레벨 : " << level
        << "에너지 : " << energy;
}

/* Upgrade_1 */
class Upgrade_1:public BasicCharacter {
    public:
        void init(void);
        void play_print_stars(void);
};

void Upgrade_1::init(void)
{
    init_origin(2);
}

/* Upgrade_2 */
class Upgrade_2:public Upgrade_1 {
    public:
        void init(void);
        void play_text_game(void);
};

void Upgrade_2::init(void)
{
    init_origin(3);
}

/* Upgrade_3 */
class Upgrade_3:public Upgrade_2 {
    public:
        void init(void);
        void create_another_character(char *name);
};

void Upgrade_3::init(void)
{
    init_origin(4);
}

void Upgrade_3::create_another_character(char *name)
{
    cout << "캐릭터 " << name << "이(가) 생성되었습니다!" << endl;
}
/* 2. Game */

/* 3. Stores */
/* 
    가게 기본클래스는 판매 기능, 매출을 관리하는 기능을 가지고 있음.
    음료 가게라면 음료를 만드는 기능 추가
    옷가게라면 옷을 정리하는 기능 추가
 */
class Stores{
    protected:
        int income;
        void add_income(int amount);
        void sub_income(int amount);
    public:
        void init_origin(void);
        void sell(int amount);
        void show_sales(void);
};

void Stores::init_origin(void)
{
    income = 0;
}

void Stores::sell(int amount)
{
    add_income(amount);
}

void Stores::add_income(int amount)
{
    income += amount;
}

void Stores::sub_income(int amount)
{
    income -= amount;
}

void Stores::show_sales(void)
{
    cout << "매출 : " << income  << endl;
}

class Cafe:public Stores {
    private:
        int made_drink;
        int made_bread;
        void make_drinks(int n);
        void make_bread(int n);
};

void Cafe::make_drinks(int n)
{
    income += (n*1000);
    made_drink += n;
    cout << "매출 " << n*1000 << "원 증가!" << endl;
}

void Cafe::make_bread(int n)
{
    income += (n*2000);
    made_bread += n;
    cout << "매출 " << n*1000 << "원 증가!" << endl;
}

class ClothingShop:public Stores{
    private:
        int jacket_stock;
        int skirt_stock;
        int pants_stock;
        void folding_clothes(int n);
    public:
        void show_state(void);
};

void ClothingShop::folding_clothes(int n)
{
    if(n >= 20) {
        sub_income(10000);
        cout << "아르바이트생 월급으로 10000원이 매출에서 차감되었습니다. " << endl;
    } else {
        sub_income(5000);
        cout << "아르바이트생 월급으로 5000원이 매출에서 차감되었습니다. " << endl;
    }
}

void ClothingShop::show_state(void)
{
    cout << "자켓 재고 : " << jacket_stock << endl
        << "치마 재고 : " << skirt_stock << endl
        << "바지 재고 : " << pants_stock << endl;
}
/* 3. Stores */

/* 4. Employee */
/*
    직원의 하는 일에 따라 사이트 접근 권한이 달라짐
    일반 직원 - 
*/
class Employee {
    public:
        char *name;
        int age;
        int id;
        int salary;
        int site_access;
        int home_access;
        int notice_access;
        void init(char *n, int a, int i);
        void access_company_site(void);
        void access_home(void);
        void access_notice(void);
};

void Employee::init(char *n, int a, int i)
{
    name = n;
    age = a;
    id = i;
    salary = 0;
    site_access = 1;
    home_access = 1;
    notice_access = 1;
}

void Employee::access_company_site(void)
{
    int option;
    while(option == 4){
        cout << "어느 페이지를 방문하시겠습니까?" << endl
            << "<1> Home" << endl
            << "<2> Notice" << endl
            << "<4> quit";
        cin >> option;

        switch(option){
            case 1:
                access_home();
                break;
            case 2:
                access_notice();
                break;
        }
    }
}

void Employee::access_home(void)
{
    cout << "홈페이지를 방문했습니다." << endl;
}

void Employee::access_notice(void)  {
    cout << "공지사항 페이지를 방문했습니다." << endl;
}

class Designer:public Employee{
    public:
        int designer_access;
        void init(void);
        void designer_page_access(void);
};

void Designer::init(void)
{
    designer_access = 1;
}

void Designer::designer_page_access(void)
{
    cout << "디자이너 전용 페이지에 접근했습니다." << endl;
}

class Engineer:public Employee {
    public:
        int admin_page_access;
        void init(void);
        void access_admin(void);
        void add_page(void);
};

void Engineer::init(void)
{
    admin_page_access = 1;
}

void Engineer::access_admin(void)
{
    cout << "관리자 전용 페이지에 방문하였습니다." << endl;
}

void Engineer::add_page(void)
{
    cout << "새로운 페이지를 만들었습니다." << endl;
}
/* 4. Employee */

/* 5. Phone */
class Phone {
    public:
        int available_calls;
        int available_text;
        int available_memory;
        void init_origin(void);
        void call(void);
        void text(void);
        void camera(void);
};

void Phone::init_origin(void)
{
    available_calls = 10;
    available_text = 20;
    available_memory = 30;
}

void Phone::call(void)
{
    available_calls -= 1;
    cout << "통화기능을 이용하였습니다." << endl
}

void Phone::text(void)
{
    available_text -= 1;
    cout << "문자기능을 이용하였습니다." << endl;
}

void Phone::camera(void)
{
    available_memory -= 1;
    cout << "저장공간을 이용하셨습니다." << endl;
}

class Smartphone:public Phone{
    public:
        int available_data;
        void init(void);
        void internet(void);
};

void Smartphone::init(void)
{
    init_origin();
    data = 30;
}

void Smartphone::internet(void)
{
    available_data -= 1;
    cout << "데이터를 이용하셨습니다." << endl;
}
/* 5. Phone */


/*  */


int main() {
    /* Car Class */
    Bus myBus;
    myBus.init();
    myBus.show_engine();
    myBus.drive(3);
    myBus.show_engine();
    myBus.customer_in(3);

    Truck myTruck;
    myTruck.init();
    myTruck.show_engine();

    ForkCrane myForkCrane;
    myForkCrane.init();
    myForkCrane.show_engine();
    myForkCrane.use_fork("흙");
    /* Car Class */

    /* Stores Class */
    Stores stores;
    stores.init_origin();
    stores.sell(100);
    stores.show_sales();
    /* Stores Class */

}