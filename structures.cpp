#include <iostream>
using namespace std;

struct employee
{
    int ID;
    char favchar;
    float salary;
};

typedef struct student{
    int ID;
    char favchar;
    float score;
}st;

int main(){

    struct employee harry;
    harry.ID = 1;
    harry.favchar = 'c';
    harry.salary = 1200000;

    cout<<harry.salary<<endl;
    cout<<harry.favchar<<endl;
    cout<<harry.ID<<endl;

    st Aniket;
    Aniket.favchar = 'A';
    Aniket.score = 88;
    Aniket.ID = 7;

    cout<<Aniket.score<<endl;
    cout<<Aniket.favchar<<endl;
    cout<<Aniket.ID<<endl;

    return 0;
}