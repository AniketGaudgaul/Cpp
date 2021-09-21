#include<iostream>
#include<math.h>
using namespace std;

class Point{
    int x, y;
    friend float distance(Point,Point);
    public:
        Point(int a, int b){
            x = a;
            y = b;
        }

        void displayPoint(){
            cout<<"The point is ("<<x<<", "<<y<<")"<<endl;
        }

};

float distance(Point p1, Point p2){
    float a = sqrt(pow(p2.x-p1.x , 2)+pow(p2.y-p1.y , 2));
    return a;
}

int main(){
    Point p(1, 1);
    p.displayPoint();

    Point q(4, 6);
    q.displayPoint();

    float dist = distance(p,q);
    cout<<"The distance between the two points is : "<<dist<<endl;

    return 0;
}