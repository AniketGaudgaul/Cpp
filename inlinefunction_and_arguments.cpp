#include <iostream>
using namespace std;

// Inline function basically replaces function call by direct the function instead of 
// passing the values and then returning it
// It just saves the time
// It should only be used for small blocks of code
// If big functions are made inline it will take lot of memory

inline int product(int a, int b=3){ //default argument b
                                    // Default args should be written at last

    static int c = 0; // this line will run only once
    return a*b+c;   // static variables retain their identity, so if the function is called again then 
                    // c will be incremented and not set to zero again 
}

int main(){

    int a=6,b=5;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;

    return 0;
}