#include <iostream>
#include <string.h>

using namespace std;

/* Phone */

class Phone{
    private:
        int point;
        int pwd;
    public:
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
/* Phone */

/* tama */

class tama {
    private:
        int energy;
    public:
        void init(void);
        void play(void);
        void sleep(void);
        void eat(void);
        void print_energy(void);
};

void tama::init(void)
{
    energy = 10;
}

void tama::print_energy(void)
{
    cout << "에너지 : " << energy << endl;
}

void tama::play(void)
{
    energy -= 3;

    cout << "체력이 3 감소되었습니다." << endl;
    print_energy();
}

void tama::eat(void)
{
    energy += 3;

    cout << "체력이 3 증가되었습니다." << endl;
    print_energy();
}

void tama::sleep(void)
{
    energy += 5;

    cout << "체력이 5 증가되었습니다." << endl;
    print_energy();    
}
/* tama */

/* car */
class Car {
    private:
        int engine;
        char *species;
    public:
        void init(char *species);
        void run(int min);
        void output(void);
};

void Car::init(char *name)
{
    species = name;
    engine = 100;
}

void Car::run(int min) 
{
    if(min > 50) {
        engine -= 20;
    } else if (min < 50) {
        engine -= 10;
    }
    output();
}

void Car::output(void)
{
    cout << "engine : " << engine << endl;
}
/* car */


/* Student */
class Student {
    private:
        char *name;
        int age;
        int grade;
        int smart;
    public:
        void init(char name[], int age);
        void study(int hours);
        void exam(void);
};

void Student::init(char n[], int a)
{
    name = n;
    age = a;
    smart = 0;
    grade = 0;
}

void Student::study(int hours)
{  
    if(hours < 3) {
        smart += 10;
    } else {
        smart += 20;
    }
}

void Student::exam(void)
{
    if(smart >= 20) {
        grade = 100;
    } else {
        grade = 50;
    }
    cout << "시험 결과는 " << grade << "점입니다" << endl;
}

/* Student */

/* Account */
class Account {
    private:
        int cash;
        int pwd;
    public:
        void init(int password);
        int withdrawl(int amount);
        void deposit(int amount);
        void output(void);
};

void Account::output(void)
{
    cout << "잔액 : " << cash << endl;
}

void Account::init(int password)
{
    pwd = password;
    cash = 0;
}

int Account::withdrawl(int amount)
{
    if(cash-amount <= 0) {
        cout << "잔액이 부족합니다." << endl;
        return 0;
    }
    cash -= amount;
    output();

    return 1;
}

void Account::deposit(int amount)
{
    cash += amount;
    output();
}
/* Account */

/* Family */
class Family {
    private:
        char *daughter;
        char *son;
        char *wife;
        char *husband;
        int happiness;
    public:
        void init(char *d, char *s, char *w, char *h);
        void eat_together(void);
        void family_bond(void);
};

void Family::init(char *d, char *s, char *w, char *h)
{
    daughter  = d;
    son = s;
    wife = w;
    husband = h;
    happiness = 0;
}

void Family::eat_together(void)
{
    happiness += 10;
    cout << "happiness + 10" << endl;
    cout << "happiness" << happiness << endl;
}

void Family::family_bond(void)
{
    happiness += 20;
    cout << "happiness + 20" << endl;
    cout << "happiness" << happiness << endl;
}
/* Family */

/* Singer */
class Singer{
    private:
        int debut;
        int salary;
        char *name;
    public:
        void init(char *n);
        void sing(int hours);
        void greet(int anoother);
};

void Singer::init(char *n)
{
    name = n;
    salary = 0;
    debut = 2022;
}

void Singer::sing(int hours)
{
    if(hours < 2) {
        salary += 100000;
    } else {
        salary += 10000000;
    }
}

void Singer::greet(int another)
{
    if(another < debut) {
        cout << "안녕하세요" << endl;
    } else {
        cout << "안녕" << endl;
    }
}
/* Singer */

/* Employee */
class Employee {
    private:
        int skill;
        char *name;
        int salary;
    public:
        void init(char n[]);
        void work(int hours);
        void break_t(int days);
};

void Employee::init(char n[])
{
    skill = 0;
    name = n;
    salary = 0;
}

void Employee::work(int hours)
{
    if(hours > 60) {
        salary += 1000000;
    } 
    cout << "salary : " << salary << endl;
}

void Employee::break_t(int days)
{
    if(days >= 10) {
        salary = 0;
    } else {
        salary -= 20;
    }

    cout << "salary : " << salary << endl;
}
/* Employee */

/* cafe */
class Cafe {
    private:
        int orangeJuice;
        int tea;
        int coffee;
        int income;
    public:
        void init(void);
        void sell(int drink);
        void count_drinks(void);
};

viod Cafe::init(void)
{
    orangeJuice = 10;
    tea = 5;
    coffee = 10;
    income = 0;    
}

void Cafe::sell(int drink)
{
    switch(drink){
        case 1:
            orangeJuice -= 1;
            income += 10;
            break;
        case 2:
            tea -= 1;
            income += 10;
        case 3:
            coffee -= 1;
            income += 15;
    }
}

void Cafe::count_drinks(void)
{
    cout << "orange juice : " << orangeJuice << endl
        << "tea : " << tea << endl
        << "coffee : " << coffee << endl;
}
/* cafe */

/* Dog */
class Dog {
    private:
        int age;
        int energy;
        char *name;
    public:
        void init(char *n);
        void bark(void);
        void play(void);
        void eat(void);
};

void Dog::init(char *n)
{
    name = n;
    energy = 100;
    age = 1;
}

void Dog::bark(void)
{
    cout << "멍멍" < endl;
    energy -= 1;
}

void Dog::play(void)
{
    energy += 5;
    cout << "energy : " << energy << endl;
}

void Dog::eat(void) 
{
    energy += 10;
    cout << "energy : " << energy << endl;
}
/* Dog */


int main() {
    /* tama */
    tama myTama;
    myTama.init();
    myTama.eat();
    myTama.play();
    myTama.sleep();
    /* tama */

    /* car */
    Car myCar;
    myCar.init("Benz");
    myCar.run(30);
    myCar.run(90);
    /* car */

    /* Account */
    Account myAccount;
    myAccount.init(1234);
    myAccount.withdrawl(10);
    myAccount.deposit(100);
    myAccount.withdrawl(20);
    /* Account */

    /* Family */
    Family myFamily;
    myFamily.init("mary", "henry", "lena", "micheal");
    myFamily.eat_together();
    myFamily.family_bond();
    /* Family */

    /* Employee */
    Employee wonny;
    wonny.init("wonny");
    wonny.work(100);
    wonny.break_t(30);
    /* Employee */

    /* cafe */
    Cafe myCafe;
    myCafe.init();
    myCafe.sell(1);
    /* cafe */


}