#include <iostream>
using namespace std;

//Forward Declaration
class complex; // tells compiler that complex class is there after calculator
               // so that calculator can use it

class Calculator{
    public:
        int add(int a, int b){
            return (a+b);
        }

        int sumREALcomplex(complex o1, complex o2);
        int sumCOMPcomplex(complex o1, complex o2);

        
};

class complex{
    int a,b;


    // INDIVIDUALLY DECLARING FUNCTIONS AS FRIENDS

    // friend int Calculator :: sumREALcomplex(complex o1, complex o2);
    // friend int Calculator :: sumCOMPcomplex(complex o1, complex o2);

    // THIS TELLS COMPILER THAT CALCULATOR CAN ACCESS PRIVATE MEMBERS OF COMPLEX

    // Alternate : Declaring the entire calculator class as friend

    friend class Calculator;

    public:
        void setnumber(int n1, int n2){
            a = n1;
            b = n2;
        }

        void printnumber(void){
            cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
        }
};

int Calculator :: sumREALcomplex(complex o1, complex o2){
            return (o1.a + o2.a);
        }
int Calculator :: sumCOMPcomplex(complex o1, complex o2){
            return (o1.b + o2.b);
        }

int main(){

    complex o1,o2;

    o1.setnumber(1,4);
    o2.setnumber(5,7);

    Calculator calc;

    int res = calc.sumREALcomplex(o1,o2);
    cout<<"SUM OF REAL PART IS "<<res<<endl;
    int resc = calc.sumCOMPcomplex(o1,o2);
    cout<<"SUM OF COMPLEX PART IS "<<resc<<endl;

    return 0;
}