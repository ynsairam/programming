// C++ program to demonstrate private
// access modifier
 
#include<iostream>
using namespace std;

/* // Public
class Circle
{   
    // private data member
    private: 
        double radius;
      
    // public member function    
    public:    
        double  compute_area()
        {   // member function can access private 
            // data member radius
            return 3.14*radius*radius;
        }
     
};
 
// main function
int main()
{   
    // creating object of the class
    Circle obj;
     
    // trying to access private data member
    // directly outside the class
    obj.radius = 1.5;
     
    cout << "Area is:" << obj.compute_area();
    return 0;
}
*/ 
/*
// private
class Circle
{   
    // private data member
    private: 
        double radius;
      
    // public member function    
    public:    
        double  compute_area(double r)
        {   // member function can access private 
            // data member radius
            radius = r;
             
            double area = 3.14*radius*radius;
             
            cout << "Radius is:" << radius << endl;
            cout << "Area is: " << area << endl;
        }
     
};
 
// main function
int main()
{   
    // creating object of the class
    Circle obj;
     
    // trying to access private data member
    // directly outside the class
    obj.compute_area(1.5);
     
     
    return 0;
}
*/

//Protected
// base class
class Parent
{   
    // protected data members
    protected:
    int id_protected;
    
};
 
// sub class or derived class
class Child : public Parent
{
    
     
    public:
    void setId(int id)
    {
         
        // Child class is able to access the inherited 
        // protected data members of base class
         
        id_protected = id;
         
    }
     
    void displayId()
    {
        cout << "id_protected is:" << id_protected << endl;
    }
};
 
// main function
int main() {
     
    Child obj1;
     
    // member function of derived class can
    // access the protected data members of base class
     
    obj1.setId(81);
    obj1.displayId();
    return 0;
}
