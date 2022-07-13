#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
    std::multimap<int,int> mm;
    multimap<int, int> m;

    mm.insert(std::make_pair(18,1234));
    // m.insert(pair<int, int>(18, 27));

    cout << m.find(18)->first << ", " << m.find(18)->second; 
}

// #include <iostream>
// #include <map>

// int main ()
// {
//   std::multimap<int,int> mymm;

//   mymm.insert (std::make_pair(,10));
//   mymm.insert (std::make_pair(,20));
//   mymm.insert (std::make_pair(,30));
//   mymm.insert (std::make_pair(,40));

//   std::multimap<char,int>::iterator it = mymm.find('x');
//   mymm.erase (it);
//   mymm.erase (mymm.find('z'));

//   // print content:
//   std::cout << "elements in mymm:" << '\n';
//   std::cout << "y => " << mymm.find('y')->second << '\n';
//   std::cout << "z => " << mymm.find('z')->second << '\n';

//   return 0;
// }