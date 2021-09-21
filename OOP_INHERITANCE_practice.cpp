#include <iostream>
#include <math.h>
using namespace std;

class SimpleCalculator{
    protected:
        float a;
        float b;
    public:
        SimpleCalculator(){

        }
        SimpleCalculator(int x, int y){
            a = x;
            b = y;
        }
        SimpleCalculator(int x){
            a = x;
        }
        void add(void){
            cout<<"The addition of the two numbers is : "<<a+b<<endl;
        }    
        void subtract(void){
            cout<<"The subtraction of the two numbers is : "<<a-b<<endl;
        }    
        void multiply(void){
            cout<<"The multiplication of the two numbers is : "<<a*b<<endl;
        }    
        void divide(void){
            cout<<"The division of the two numbers is : "<<a/b<<endl;
        }    
};

class ScientificCalculator : public SimpleCalculator{
    public:
        ScientificCalculator(int x, int y){
            a = x;
            b = y;
        }
        ScientificCalculator(int x){
            a = x;
        }
        void sine(){
            cout<<"The sin of the number is : "<<sin(a)<<endl;
        }
        void cosine(){
            cout<<"The cosine of the number is : "<<cos(a)<<endl;
        }
};

int main(){

    ScientificCalculator calc(30,5);
    calc.add();
    calc.subtract();
    calc.multiply();
    calc.divide();
    calc.sine();
    calc.cosine();

    return 0;
}