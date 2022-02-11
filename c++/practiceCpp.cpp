#include <iostream>

using namespace std;

int customer_numbers[6] = {102, 255, 300, 400, 500, 0};

class Retrieve
{
    private:
        int modify(int);
    public:
        int search(int number);
        friend void modify_record(int number);
        virtual void print(void);
};

class Display : public Retrieve
{
    public:
        void display_info(int temp);
        void print(void);
};

class Add : public Retrieve
{
    public:
        void add_info(int number);
        void print(void);
};

class Del : public Retrieve
{
    public:
        void delete_info(int);
        void print(void);
};

int Retrieve::modify(int number)
{
    cout << "Inside modify()" << endl;
    number = number+55;
    cout << "Record modified" << endl;

    return number;
}

int Retrieve::search(int number)
{
    int i = 0;
    cout << "Inside search \n";
    while(customer_numbers[i] != 0) {
        if (number != customer_numbers[i]) {
            i ++;
        } else {
            print();
            number = customer_numbers[i];
            return number;
        }
    }
    Retrieve::print();
    return 0;
}

void Retrieve::print(void)
{
    cout << "Record not found" << endl;
}

void Display::display_info(int temp)
{
    cout << "Inside display_info() \n"
        << "Customer number is " << temp << endl;
}

void Display::print(void)
{
    cout << "Here is a copy of the record! " << endl;
}

void Add::add_info(int temp)
{
    cout << "Inside add_info" << endl;
    int i = 0;
    while(search(customer_numbers[i]) != 0) {
        i++;
    }
    customer_numbers[i] = temp;
}

void Add::print(void)
{
    cout << "Attempt to add duplicate record" << endl
        << "Transaction disallowed" << endl;
}

void Del::print(void)
{
    cout << "Record ready to be deleted!" << endl;
};

Retrieve retrieve_customer;

void modify_record(int number)
{
    int i = 0;
    cout << "Inside modify_record" << endl;
    while(customer_numbers[i] != 0) {
        if(number != customer_numbers[i]) {
            i ++;
        } else {
            customer_numbers[i] = retrieve_customer.modify(customer_numbers[i]);
        }
        return;
    }
    cout << "Record not found" << endl;
}

void Del::delete_info(int temp)
{
    cout << "Inside delete_info " << endl;
    int i = 0;
    while(customer_numbers[i] != 0) {
        if(temp != customer_numbers[i]) {
            i ++;
        } else {
            customer_numbers[i] = 0;
            while(customer_numbers[i+1] != 0) {
                customer_numbers[i] = customer_numbers[i+1];
                i++;
            }
            customer_numbers[i] = 0;
            return;
        }
    }
}


int main() {
    int temp, number, i;
    Retrieve retrieve_customer;
    Display display_customer;
    Add add_customer;
    Del delete_customer;

    number = 200;
    temp = display_customer.search(number);
    if(temp > 0) {
        display_customer.display_info(temp);
    }
    modify_record(number);
    temp = delete_customer.search(350);
    if(temp >0) {
        delete_customer.search(300);
    }
    for(i = 0; i < 6; i ++){
        cout << "Customer_numbers[" << i << "] is " << customer_numbers[i] << endl;
    }
    temp = add_customer.search(600);
    if(temp == 0) {
        add_customer.add_info(600);
    }
}