#include <iostream>
using namespace std;

class Employee{

    private: 
        int a,b,c; //only be used in functions within the class;
    public: 
        int d,e;
    void setData(int a1, int b1, int c1); // Declaration
    void getData(){ // Or you can declare here also
        cout<<"The value of a is "<<a<<endl;
        cout<<"The value of b is "<<b<<endl;
        cout<<"The value of c is "<<c<<endl;
        cout<<"The value of d is "<<d<<endl;
        cout<<"The value of e is "<<e<<endl;
    }    
};

void Employee :: setData(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
};

int main(){

    Employee e1;

    // e1.a == 42; // THIS WILL THROW AN ERROR AS A IS PRIVATE
    e1.d = 45;
    e1.e =53;
    e1.setData(1,34,5);
    e1.getData();

    return 0;
}