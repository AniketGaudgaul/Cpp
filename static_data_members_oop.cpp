#include <iostream>
using namespace std;

class Employee{

    int id; 
    static int count;
    // int count; IF YOU WANT TO COUNT ALL THE EMPLOYEE USING A VARIABLE INSIDE A CLASS,
    // ITS NOT POSSIBLE AS COUNT IS A VARIABLE FOR EACH OBJECT HENCE STORES VALUES FOR EACH EMPLOYEE SEPARATLY
    // HENCE INSTEAD DEFINE A STATIC VARIABLE OUT SIDE THE CLASS

    public:
        void setdata(void){
            cout<<"Enter the id "<<endl;
            cin>>id;
            count++;
        }
        void getdata(void){
            cout<<"THE ID OF THIS EMPLOYEE IS "<<id<<" and this is employee number"<<count<<endl;
        }

        static void getcount(void){ // THIS IS A STATIC FUCNTION WHICH ONLY CAN ACCESS STATIC VARIABLES
            cout<<"The value of count is "<<count<<endl;
        }

};

int Employee::count; //STATIC, its memory is memory of class hence common to all objects
                    //and default value is 0
int main(){

    Employee Aniket,Roonak,Pige;
    Aniket.setdata();
    Aniket.getdata();
    Employee::getcount();

    Roonak.setdata();
    Roonak.getdata();
    Employee::getcount();

    Pige.setdata();
    Pige.getdata();
    Employee::getcount();
    return 0;
}