#include <iostream>

using namespace std;

class TimeCounter{
    private:
        int seconds = 0;
    public: 
        TimeCounter();
        TimeCounter(int time){ time = seconds; };
        void setSecondsCount(int time){ time = seconds; };
        int getSecondsCount(){ return seconds; };
        void getTimeCount();
        //string to_string(int time);
};

void TimeCounter::getTimeCount(){
    //to_string()
    int min;
    int sec;

    min = seconds/ 60;
    sec = seconds % 60;

    cout << min << "m " << sec << "s" << endl;
}

class Playable{
    protected: 
        string title;
        TimeCounter duration;
    public: 
        Playable();
        Playable(string T, TimeCounter& time(int t)){ T = title; TimeCounter time = duration;};
        virtual void getSummary() = 0;
};

class Song : public Playable{
    private: 
        string artist;
        int year;
    public: 
        Song();
        Song(string ttl, TimeCounter& du(int t), string art, int y);
        void getSummary(Song& name);
};

Song::Song(string ttl, TimeCounter& du(int t), string art, int y){
    ttl = title;
    TimeCounter du = duration;
    art = artist;
    y = year;
}

void Song::getSummary(Song& name){
    cout << title << " (" << name.duration.getTimeCount << ")"<< endl;
    cout << "By: " << artist << ", " << year << endl;
}

class Audiobook : public Playable{
    private: 
        string author;
        string narrator;
    public: 
        Audiobook();
        Audiobook(string ttl, TimeCounter& du(int t), string auth, string narr);
        void getSummary(Audiobook& name);
};

Audiobook::Audiobook(string ttl, TimeCounter& du(int t), string auth, string narr){
    ttl = title;
    TimeCounter du = duration;
    auth = author;
    narr = narrator;
}

void Audiobook::getSummary(Audiobook& name){
    cout << title << "(Audiobook)" << endl;
    cout << "By: " << author;
    cout << "Narrated by: " << narrator << endl;
    cout << "Length: " << name.duration.getTimeCount << endl;
}

int main(){







    return 0;

}