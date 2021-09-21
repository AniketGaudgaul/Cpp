#include <iostream>
using namespace std;

class complex{
    int a,b;
    public:
        void setnumber(int n1, int n2){
            a = n1;
            b = n2;
        }

        // friend means sumcomplex can access private variable outside class of complex

        friend complex sumcomplex(complex o1, complex o2);

        void printnumber(void){
            cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
        }
};

complex sumcomplex(complex o1, complex o2){
    complex o3;
    o3.setnumber((o1.a + o2.a), (o1.b + o2.b)); // You cannot access private a, b of class complex
    return o3;
};

int main(){

    complex c1, c2, sum;

    c1.setnumber(1,4);
    c1.printnumber();
    
    c2.setnumber(5,8); 
    c2.printnumber(); 

    sum = sumcomplex(c1,c2);
    sum.printnumber();

    return 0;
}

/* Proporties of friend function

    1. Not in the scope of class.
    2. Since it is not in the scope of the class it cannot be called from the 
       object of the class. c1.sumcomplex() == Invalid
    3. Can be invoked without the help of any object.
    4. Usually contains objects as arguments.   
    5. Can be declared inside public or private section of the part.
    6. It cannot access the members directly by their names and need object_name.member_name.

*/