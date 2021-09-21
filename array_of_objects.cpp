#include <iostream>
using namespace std;

class Employee{
    int id ;
    int salary;
    public:
        void setid(void){
            salary = 122;
            cout<<"Enter id of employee "<<endl;
            cin>>id;
        }

        void getid(void){
            cout<<"The id of this employee is "<<id<<endl;
        }
};

int main(){

    // Employee Aniket, Bigbro, Undir, Maya;
    // Aniket.setid();
    // Aniket.getid();

    Employee Facebook[4];
    for (int i = 0; i < 4; i++)
    {
        Facebook[i].setid();
        Facebook[i].getid();
    }
    

    return 0;
}