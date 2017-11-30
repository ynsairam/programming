// C++ program to demonstrate constructors
 
#include <bits/stdc++.h>
using namespace std;
class Geeks
{
    public:
    int id;
     
    //Default Constructor
    Geeks()
    {
        cout << "Default Constructor called" << endl; 
        id=-1;
    }
     
    //Parametrized Constructor
    Geeks(int x)
    {
        cout << "Parametrized Constructor called" << endl;
        id=x;
    }
};
int main() {
     
    // obj1 will call Default Constructor
    Geeks obj1;
    cout << "Geek id is: " <<obj1.id << endl;
     
    // obj1 will call Parametrized Constructor
    Geeks obj2(21);
    cout << "Geek id is: " <<obj2.id << endl;
    return 0;
}
