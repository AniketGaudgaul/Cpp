#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

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
      int getCtime(){
        time_t rawtime = time(0);
        return rawtime;
      }  
};

class carModel{
    protected:
        string company;
        int rateperHour;
        float deposit;   
};
class carUnit : public carModel{
    protected:
        float milage;
        string carID;
        string condition;
    public:
        // string availability;
        float getMilage(){
            
        }
        void setMilage(){
            ofstream write;
            write.open("carData.csv",std::ios_base::app);
            write<<",";
            write<<condition;
            write.close();
        }
        string getCondition(){

        }
        void setCondition(){
          
        }    
        string getcarID(){

        }
        void setId(string noplate){
            this->carID = noplate;
        }    
        void availability(string av){
            // this->availability = av;

            regex reg(carID);

            ifstream read("carData.csv",ios::in);

            while(read.eof()==0){
                
                vector<string> column;
                string record;
                string info;
                
                getline(read,record);

                stringstream s(record);

                while (getline(s,info,','))
                {
                    column.push_back(info);
                }   
                if(regex_match(column[0],reg)){
                    
                    column[5] = av;

                }
                else if(read.eof()){

                }
            }  
            read.close();
        }
};

// FUNCTIONS

void menu(){
    
    cout<<endl;
    cout<<"What would you like to do?"<<endl;
    cout<<endl;
    cout<<"PRESS 1 : View Car Rental Tariff"<<endl;
    cout<<"PRESS 2 : Rent a Car"<<endl;
    cout<<"PRESS 3 : Return rental car"<<endl;
    cout<<"PRESS 4 : Get car info"<<endl;
    cout<<"PRESS 5 : Exit"<<endl;
}

void rentalTarrif(){

    cout<<"*** CARS AND MODELS AT SERVICE ***"<<endl<<endl;
    cout<<"Select option to get information and check availability"<<endl<<endl;
    cout<<" 1 : Elantra"<<endl;
    cout<<" 2 : Santa_Cruz"<<endl;
    cout<<" 3 : Q60"<<endl;
    cout<<" 4 : F150"<<endl;
    cout<<" 5 : Ram_1500"<<endl;
    cout<<" 6 : Series_3"<<endl<<endl;

    int option;
    cout<<"Enter your Choice : ";
    cin>>option;
    cout<<endl<<endl;
    string expression="";

    switch (option)
    {
    case 1:
        expression = "^E[1-10]*.";
        break;
    case 2:
        expression = "^S[1-10]*.";
        break;
    case 3:
        expression = "^Q[1-10]*.";
        break;
    case 4:
        expression = "^F[1-10]*.";
        break;
    case 5:
        expression = "^R[1-10]*.";
        break;
    case 6:
        expression = "^B[1-10]*.";
        break;
    
    default:
        break;
    }

    regex reg(expression);

    cout<<"*** CAR DETAILS AND AVAILABILITY *** "<<endl<<endl;
    ifstream read("carData.csv",ios::in);

    int counter=0;
    int cost=0;

    while(read.eof()==0){
        
        vector<string> column;
        string record;
        string info;
        

        getline(read,record);

        stringstream s(record);

        while (getline(s,info,','))
        {
            column.push_back(info);
        }   
        if(regex_match(column[0],reg)){
            if(column[5]=="available"){
                 counter++;
            }
            cost = stoi(column[6]);
            cout<<"Car ID : "<<column[0]<<" ";
            cout<<"Car Model : "<<column[1]<<" ";
            cout<<"Car Company : "<<column[2]<<" ";
            cout<<"Car Condition : "<<column[3]<<" ";
            cout<<"Car Milage : "<<column[4]<<" ";
            cout<<"Car Availability : "<<column[5]<<" "<<endl<<endl;
             
                // break;
            }
        else if(read.eof()){

        }
    }  
    read.close();
    cout<<"The number of available vehicals for this model are : "<<counter<<endl;
    cout<<"The price per Hour for this model is :"<<cost<<endl;
}

string rentCar(){


    string carID, carName, milage, condition;

    cout<<endl;

    cout<<"*** CARS AND MODELS AT SERVICE ***"<<endl<<endl;
    cout<<"Please select the Car you want to rent : "<<endl<<endl;
    cout<<" 1 : Elantra"<<endl;
    cout<<" 2 : Santa_Cruz"<<endl;
    cout<<" 3 : Q60"<<endl;
    cout<<" 4 : F150"<<endl;
    cout<<" 5 : Ram_1500"<<endl;
    cout<<" 6 : Series_3"<<endl<<endl;

    int option;
    cout<<"Enter your Choice : ";
    cin>>option;
    cout<<endl<<endl;
    string expression;

    switch (option)
    {
    case 1:
        expression = "^E[1-10]*.";
        carName = "Elantra";
        break;
    case 2:
        expression = "^S[1-10]*.";
        carName = "Santa_Cruz";
        break;
    case 3:
        expression = "^Q[1-10]*.";
        carName = "Q60";
        break;
    case 4:
        expression = "^F[1-10]*.";
        carName = "F150";
        break;
    case 5:
        expression = "^R[1-10]*.";
        carName = "Ram_1500";
        break;
    case 6:
        expression = "^B[1-10]*.";
        carName = "Series_3";
        break;
    
    default:
        break;
    }

    regex reg(expression);

    cout<<"*** CAR DETAILS AND AVAILABILITY *** "<<endl<<endl;
    ifstream read("carData.csv",ios::in);

    int counter=0;
    int cost=0;


    while(read.eof()==0){
    vector<string> column;
    string record;
    string info;

        getline(read,record);

        stringstream s(record);

        while (getline(s,info,','))
        {
            column.push_back(info);
        }   
        if(regex_match(column[0],reg)){
            if(column[5]=="available"){
                counter++;
                carID = column[0];
                milage = column[4];
                condition = column[3];
            }
            cost = stoi(column[6]);
            cout<<"Car ID : "<<column[0]<<" ";
            cout<<"Car Model : "<<column[1]<<" ";
            cout<<"Car Company : "<<column[2]<<" ";
            cout<<"Car Condition : "<<column[3]<<" ";
            cout<<"Car Milage : "<<column[4]<<" ";
            cout<<"Car Availability : "<<column[5]<<" "<<endl<<endl;
             

            }
        else if(read.eof()){

        }
    }  
    read.close();
    if(counter!=0){
        cout<<"The model Selected by You is Available!!"<<endl<<endl;
        
        string firstName,lastName,ID,number;

        cout<<"Please fill out the necessary details - "<<endl<<endl;
        cout<<"Enter Your First Name - ";
        cin>>firstName;
        cout<<"Enter Your Last Name - ";
        cin>>lastName;
        cout<<"Enter Your Unique Citizen ID - ";
        cin>>ID;
        cout<<"Enter Your Mobile Number - ";
        cin>>number;
        cout<<endl<<endl;


        // TIME 

        DateandTime DntObj;
        DntObj.setDnt();
        string Dnt = DntObj.getDnt();
        int ctime = DntObj.getCtime();

        ofstream write;
        write.open("Register.csv",std::ios_base::app);
        write<<endl;
        write<<firstName<<","<<lastName<<","<<carID<<","<<ID<<","<<number<<",";
        write<<carName<<","<<condition<<","<<milage<<","<<ctime<<","<<Dnt;
        write.close();

        cout<<"!!!!!!!!!  Congratulations : You can now use you rented Vehicle  !!!!!!!!!!"<<endl;
    }
        return carName;
}

void returnCar(){
    string firstName,lastName,carID,condition;
    float milage;
    string uniquetag;
    cout<<"Enter you First Name : ";
    cin>>firstName;
    cout<<"Enter you Last Name : ";
    cin>>lastName;
    cout<<"Enter the car Name : ";
    cin>>uniquetag;
    cout<<"Enter the car ID : ";
    cin>>carID;
    cout<<endl<<endl;
    ifstream read("Register.csv",ios::in);
    while(read.eof()==0){
        
        vector<string> column;
        string record;
        string info;

        getline(read,record);

        stringstream s(record);

        while (getline(s,info,','))
        {
            column.push_back(info);
        }

        if(firstName==column[0] && lastName==column[1] && carID==column[2]){
            cout<<"Information of rented vehicle : "<<endl<<endl;
            cout<<"Car Rented by : "<<column[0]<<" "<<column[1]<<endl;
            cout<<"Car ID : "<<column[2]<<endl;
            cout<<"Car Name : "<<column[5]<<endl;
            cout<<"Car Condition while renting : "<<column[6]<<endl;
            cout<<"Car Milage : "<<column[7]<<endl;
            cout<<"Rented on : "<<column[9]<<endl<<endl<<endl;
            // break;

            

            cout<<"PLEASE ENTER THE CONDITION OF THE VEHICLE AT THE TIME OF RETURNING : (GOOD / BAD) ";
            cin>>condition;
            cout<<endl<<endl;
            cout<<"PLEASE ENTER THE MILAGE AT THE TIME OF RETURNING ";
            cin>>milage;
            
            time_t returnTime = time(0);

            float usagetime = returnTime - stoi(column[8]);
                usagetime = usagetime/3600;

            int costperhour;
            
            if(uniquetag == "Elantra"){
                costperhour = 100;
            }
            else if(column[5]=="Santa_Cruz"){
                costperhour = 8;
            }
            else if(column[5]=="Q60"){
                costperhour = 15;
            }
            else if(column[5]=="F150"){
                costperhour = 18;
            }
            else if(column[5]=="Ram_1500"){
                costperhour = 20;
            }
            else if(column[5]=="Series_3"){
                costperhour = 25;
            }
            else{
                cout<<"wrong";
            }

             float bill = usagetime * costperhour;

                cout<<endl<<endl;
                cout<<"******   Total Bill   ******"<<endl<<endl;    
                cout<<"Rental Time : "<<usagetime<<endl;    
                cout<<"Rental Cost per Hour : "<<costperhour<<endl<<endl;    
                cout<<"Total amount to be paid : "<<bill<<endl;    
               
        }
        else{
            cout<<"Invalid input!!"<<endl;
        }

    } 

}

void carInfo(){
    
    int counter = 0;
    string id;
    cout<<"Enter Unique ID of the Car : ";
    cin>>id;
    ifstream read("carData.csv",ios::in);
    while(read.eof()==0){
        
        vector<string> column;
        string record;
        string info;

        getline(read,record);

        stringstream s(record);

        while (getline(s,info,','))
        {
            column.push_back(info);
        }

        if(id==column[0]){
            cout<<"Car ID : "<<column[0]<<endl;
            cout<<"Car Model : "<<column[1]<<endl;
            cout<<"Car Company : "<<column[2]<<endl;
            cout<<"Car Condition : "<<column[3]<<endl;
            cout<<"Car Milage : "<<column[4]<<endl;
            cout<<"Car Availability : "<<column[5]<<endl;
            counter = 1;
            // break;
        }

    }  
    
    
}

string start(int option){

    cout<<endl<<endl;
    int x = 1;
    while (x!=0)
    {   
        

        switch (option)
        {
        case 1:
            rentalTarrif();
            if(x!=0){
                menu();
            }
            cout<<endl;
            cout<<"Enter you Choice : ";
            cin>>option;
            break;
        case 2:
            rentCar();
            if(x!=0){
                menu();
            }
            cout<<endl;
            cout<<"Enter you Choice : ";
            cin>>option;
            break;
        case 3:
            returnCar();
            if(x!=0){
                menu();
            }
            cout<<endl;
            cout<<"Enter you Choice : ";
            cin>>option;
            break;
        case 4:
            carInfo();
            if(x!=0){
                menu();
            }
            cout<<endl;
            cout<<"Enter you Choice : ";
            cin>>option;
            break;
        case 5:
            x=0;
            break;
        
        default:
            break;
        }   
    }    
}

void setData(){
    carUnit Elantra[5];
    carUnit Santa_Cruz[5];
    carUnit Q60[4];
    carUnit F150[8];
    carUnit Ram_1500[4];
    carUnit Series_3[5];

    for (int i = 1; i < 6; i++)
    {
        Elantra[i].setId("E"+i);
        Elantra[i].setMilage();
        Elantra[i].setCondition();
    }
    for (int i = 1; i < 6; i++)
    {
        Santa_Cruz[i].setId("S"+i);
        Santa_Cruz[i].setMilage();
        Santa_Cruz[i].setCondition();
    }
    for (int i = 1; i < 5; i++)
    {
        Q60[i].setId("Q"+i);
        Q60[i].setMilage();
        Q60[i].setCondition();
    }
    for (int i = 1; i < 9; i++)
    {
        F150[i].setId("F"+i);
        F150[i].setMilage();
        F150[i].setCondition();
    }
    for (int i = 1; i < 5; i++)
    {
        Ram_1500[i].setId("R"+i);
        Ram_1500[i].setMilage();
        Ram_1500[i].setCondition();
    }
    for (int i = 1; i < 6; i++)
    {
        Series_3[i].setId("B"+i);
        Series_3[i].setMilage();
        Series_3[i].setCondition();
    }
    
    // Elantra[1].availability("unavailable");

}



int main(){

    //Objects

    //setData();
    string carName;
    int option;

    cout<<endl<<"**Welcome To Car Rental Service**"<<endl;
    menu();
    cout<<"Enter you Choice : ";
    cin>>option;

    carName = start(option);



  return 0;
}