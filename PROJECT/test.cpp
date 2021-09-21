#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void setdata();
string rentCar();

class DateandTime{
  private:
      string dnt;
  public:
      void setDnt(){
        time_t rawtime;
        struct tm * timeinfo;

        time (&rawtime);
        timeinfo = localtime (&rawtime);
        dnt = asctime(timeinfo);
      }
      string getDnt(){
        return dnt;
      }  
};

int main(){

    time_t now = time(0);

    cout<<now;

    return 0;
}