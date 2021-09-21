#include <iostream>
using namespace std;

int sum(int a, int b){
    int c = a + b;
    return c;
}

// Call by value
void swap(int a , int b){
    int temp = a;
    a = b;
    b = temp;
}
//Call by reference
void swappointer(int* a ,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int a = 4, b = 5;
    // cout<<sum(a,b);

    // Call by value
    cout<<a<<","<<b<<endl;
    swap(a,b);
    cout<<a<<","<<b<<endl;

    //Call by reference
    swappointer(&a,&b);
    cout<<a<<","<<b<<endl;    
    return 0;
}