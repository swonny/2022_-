#include <iostream>

using namespace std;

class Caribbean_Isles
{
    public:
        virtual void other_attractions(void){
            cout << "!! COME VISIT THE CARIBBEAN ISLANDS !! \n"
                << "White sand beaches" << endl
                << "Crystal clear water" << endl
                << "No hassless - No worries\n\n";
        }
};

class Bahamas : public Caribbean_Isles
{
    public:
        void other_attractions(void)
        {
            cout << " !! BAHAMAS !!" << endl
                << "Fun-filled casinos" << endl
                << "Action-packed water sports" << endl
                << "Great rum peaches\n\n";
        }
};

class Grand_Cayman : public Caribbean_Isles
{
    public:
        void othre_attraction(void)
        {
            cout << "!! GRAND CAYMAN!! \n"
                << "Incredible scuba diving \n"
                << "Big time game fishing \n"
                << "Duty free shopping\n\n";
        }
};

class St_thomas : public Caribbean_Isles
{
    public:
        void other_attraction(void)
        {
            cout << "!! ST THOMAS !! \n"
                << "Excellent shopping\n\n";
        }
};

int main() {
    Caribbean_Isles islands, *ptr;
    Bahamas package_1;
    Grand_Cayman package_2;
    St_thomas package_3;
    ptr = &islands;
    ptr->other_attractions();
    ptr = &package_1;
    ptr->other_attractions();
    ptr = &package_2;
    ptr->other_attractions();
    ptr = &package_3;
    ptr->other_attractions();
}