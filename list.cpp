#include <iostream>
#include <list>

using namespace std;

void display(list<int> &lst){
    list<int> :: iterator it;
    for (it=lst.begin() ; it!= lst.end(); it++)
    {
        cout<< *it << " ";
    }
        cout<<endl;
    
}

int main(){

    list<int> list1; // List of zero length

    list1.push_back(5);
    list1.push_back(3);
    list1.push_back(6);
    list1.push_back(12);
    display(list1);

    // REMOVING ELEMENTS FROM A LIST
    // list1.pop_back();
    // display(list1);
    // // list1.pop_front();
    // // display(list1);
    // list1.remove(3);
    // display(list1);

    // //SORTING A LIST
    // list1.sort();
    // display(list1);

    //REVERSING THE LIST
    //list1.reverse();
    //display(list1);

    list<int> list2(3); // Empty list of size 7
    list<int> :: iterator iter;
    iter = list2.begin();
    *iter = 45;
    iter++;
    *iter = 6;
    iter++;
    *iter = 9;
    iter++;
    display(list2);

    // MERGING OF LISTS
    list1.merge(list2);
    cout<<"List 1 after merging ";
    display(list1);

    return 0;
}