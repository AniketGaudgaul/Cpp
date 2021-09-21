#include <iostream>
using namespace std;

int main(){

    int marks[4] = {6,8,11,46};

    int* p = marks;
    
    cout<<*p<<endl;
    cout<<*(p+1)<<endl;
    cout<<*(p+2)<<endl;

    return 0;
}