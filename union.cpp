#include <iostream>
using namespace std;

// UNIONS ARE BETTER WHERE YOU WANT TO USE ANY ONE PROPERTY OUT OF ALL

union money{    
    // UNION PROVIDES BETTER MEMORY MANAGEMENT

    int rice;
    char car;
    float pounds;

};

int main(){

    union money m1;
    m1.rice = 34;       // You can use only one, if you assign values to 2 properties
                        // then only the one which is defined later is correct
                        // earlier one shows any garbage value as memory is 
                        // shared between properties
                        // hence its used where only one prop is req at a time
    m1.car = 'c';
    cout<<m1.rice;

    return 0;
}