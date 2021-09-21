#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){

    map<string, int> marksMap;
    marksMap["Aniket"] = 9.89;
    marksMap["Pige"] = 9.81;
    marksMap["Bade"] = 9.86;

    marksMap.insert({{"Buck", 9.70},{"Eshan", 9.86}});

    map<string, int> :: iterator iter;
    for (iter=marksMap.begin(); iter!=marksMap.end(); iter++)
    {
        cout<<(*iter).first<<" "<<(*iter).second<<"\n";
    }

    cout<<"The size is "<<marksMap.size()<<endl;    
    cout<<"The max size is "<<marksMap.max_size()<<endl;    
   

    return 0;
}