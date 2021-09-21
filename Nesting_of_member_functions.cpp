#include <iostream>
#include <string>
using namespace std;

class binary
{   
    // BY DEFAULT ALL MEMBERS ARE PRIVATE
    string s;

    public:
        void read(void);
        void chk_bin(void);
        void onescomp(void);
        void display(void);
};

void binary :: read(void){
    cout<<"Enter a binary number"<<endl;
    cin>>s;
}

void binary :: chk_bin(void){
    for (int i = 0; i < s.length(); i++){
        if(s.at(i)!='0' && s.at(i)!='1'){
            cout<<"Incorrect binary format"<<endl;
            exit(0);
        }
    }
}

void binary :: onescomp(void){

    chk_bin();      // NESTING OF MEMBER FUNCTIONS
                    // IT WILL AUTOMATICALLY RUN THE METHOD FOR THE OBJECT WHICH CALLS THIS METHOD
    for (int i = 0; i < s.length(); i++){
        if(s.at(i)=='0'){
            s.at(i)='1';
        }
        else if(s.at(i)=='1'){
            s.at(i)='0';
        }
    }
}
void binary :: display(void){
    cout<<"You binary's one's complement"<<endl;
    for (int i = 0; i < s.length(); i++){
        cout<<s.at(i);
    }
    cout<<endl;
}

int main(){

    binary b;
    b.read();
    // b.chk_bin(); Instead of writing all methods here you can simply put this inside other method
    b.onescomp();
    b.display();
    return 0;
}