#include <iostream>
#include <fstream>

using namespace std;

//Question 1(a)
class Trip{
    private: 
        float km[15];
        int passenger[15];
        float mileage;
        string driver_name;
        bool load;

    public:
        Trip();
        Trip(string);
        ~Trip();
        int LoadData(string);
        string GetName();
        float CalcFare(int);
        void DisplayData();
        float CalcProfit();
};

Trip::Trip(){
    float km[15] = {};
    int passenger[15] = {};
    mileage = 0.65;
    load = false;
}

Trip::Trip(string FileName){
    mileage = 0.65;
    load = false;

    LoadData(FileName);
    if(load == true){
        DisplayData();
    }
    else{
        cout << "Unable to open file." << endl;
        cout << "Please correct check for the correct file name and reload." << endl;
    }
}

Trip::~Trip(){
    delete []km;
    delete []passenger;
}

int Trip::LoadData(string filename){
    string line;
    string fname, lname;
    ifstream readFile;

    readFile.open(filename);
    if (readFile.is_open())
    {
       while(!readFile.eof()){
           readFile >> fname;
           readFile >> lname;
           driver_name =  fname + " " + lname;
           while(int i = 0; i<15; i++){
               readFile >> km[i];
               readFile >> passenger[i];
           }
       }
       readFile.close();

       load = true;
       cout << "'" << filename << ": Data loaded successfully." << endl;
       return load;
    }
    else{
        cout << "'" << filename << ": Data not loaded successfully." << endl;
        return load;
    } 
}

string Trip::GetName(){
    return driver_name;
}

float Trip::CalcFare(int i){
    float Fare = 0;
    Fare = mileage * km[i];

    if(passenger[i] == 2){
        Fare += 5;
    }

    else if(passenger[i] == 3){
        Fare *= 1.15;
    }

    return Fare;
}

void Trip::DisplayData(){
    if(load == false){
        cout << "No data loaded yet." << endl;
    }
    else{
        cout << "Driver Name: " << GetName() << endl;
        for (int i=0; i<15; i++){
            cout << "Trip " << i+1 << ": " << km[i] << " km Number of Passengers: " << passenger[i] << " Earnings: RM" << CalcFare(i) << endl;
        }
    }
}

float Trip::CalcProfit(){
    float Profit = 0;
    for(int i=0; i<15; i++){
        Profit += CalcFare(i);
    }
    return Profit;
}

int main(){

    Trip driver1;
    Trip driver1("John.txt");
    driver1.CalcProfit();

    Trip driver2;
    string filename;
    cout << "Enter file name to load: " << endl;
    cin >> filename;
    int flag = driver2.LoadData(filename);

    try{
        if(flag == 0){
            throw(flag);
            }
        else
            driver2.DisplayData();
        }
    }

    catch(int flag){
        cout << filename << ": Data not loaded successfully" << endl;
    }

    cout << "Press any key to continue..." << endl;
    getwchar();
    return 0;

}