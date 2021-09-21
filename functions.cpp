#include <iostream>
using namespace std;

// FUNCTION PROTOTYPE
int sum(int a , int b); // Tells compiler that this function is defined somewhere
                        // If function is defined before int main(), no need to use prototype;
void greet();


int main(){

    int num1 , num2; // num1 ,num2 are actual parameters
    num1 = 5;
    num2 = 6;

    cout<<"sum is "<<sum(num1 ,num2);

    greet();

    return 0;
}

int sum(int a , int b){ // a and b are formal parameters
    int c = a + b;
    return c;
}

void greet(){
    cout<<"Good Morning";
}