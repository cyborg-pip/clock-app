#include<iostream>
#include<ctime> //
#include<iomanip> // Used to manipulate output
using namespace std;

// Class initialize variables
class time_sim   {
public:
    int hour;
    int minute;
    int seconds;
};

// class hours_12_format (12 hrs) that inherits time_sim class
class hours_12_format:public time_sim   {
public:
    string meridian; //init string that outputs AM / PM
    hours_12_format()
    {
        time_t now = time(0); // uses ctime library
        tm *ltm = localtime(&now); // converts time_t to local time
        hour=ltm->tm_hour;
        minute=ltm->tm_min;
        seconds=ltm->tm_sec;
        if(hour>=12) // In the case of less than 12 hrs
        {
            meridian = "P M"; // time is PM
            hour-=12;
        }
        else
            meridian = "A M"; // Else AM

    }

// Method to add one hour to the clock

    void add_hour(int h)
    {
        hour+=h;
        if(hour>12)
        {
            hour-=12;
        }
        else if(hour>=12)
        {
            if(meridian == "A M")
            {
                meridian = "P M";
            }
            else if(meridian == "P M")
            {
                meridian = "A M";
            }
        }

    }

// Method to add one minute to clock

    void add_minute(int min)
    {
        minute+=min;
        if(minute>=60)
        {
            int h = minute/60;
            minute -= 60*h;
            add_hour(h);
        }
    }

// Method to add once second

    void add_seconds(int sec)
    {
        seconds+=sec;
        if(seconds>=60)
        {
            int m = seconds/60;
            seconds-=60*m;
            add_minute(m);
        }
    }
};

// class hours_24_format (12 hrs) that inherits time_sim class

class hours_24_format:public time_sim   {
public:
    int hour;
    int minute;
    int seconds;
    hours_24_format()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        hour=ltm->tm_hour;
        minute=ltm->tm_min;
        seconds=ltm->tm_sec;
    }

//Method that add an hour to clock

    void add_hour(int h)
    {
        hour+=h;
        if(hour>=24)
        {
            hour -= 24;
        }
    }

//Method that add an minute to clock

    void add_minute(int min)
    {
        minute+=min;
        if(minute>=60)
        {
            int h = minute/60;
            minute -= 60*h;
            add_hour(h);
        }
    }

//Method that add an sec to clock

    void add_seconds(int sec)
    {
        seconds+=sec;
        if(seconds>=60)
        {
            int m = seconds/60;
            seconds-=60*m;
            add_minute(m);
        }
    }
};

// display outputs the proper format as outlined by CHADA Tech
void display(hours_12_format h1,hours_24_format h2)
{
    cout<<"\t\t*************************\t\t";
    cout<<"*************************\n";
    cout<<"\t\t*\t12-Hour Clock\t*\t\t";
    cout<<"*\t24-Hour Clock\t*\n";
    cout<<"\t\t*\t"<<setw(2) << setfill('0')<<h1.hour<<":"<<setw(2) << setfill('0')<<h1.minute<<":"<<setw(2) << setfill('0')<<h1.seconds<<" "<<h1.meridian<<"\t*\t\t";
    cout<<"*\t"<<setw(2) << setfill('0')<<h2.hour<<":"<<setw(2) << setfill('0')<<h2.minute<<":"<<setw(2) << setfill('0')<<h2.seconds<<"\t*\n";
    cout<<"\t\t*************************\t\t";
    cout<<"*************************\n";
}

int main()
{
    hours_12_format h1;
    hours_24_format h2;
    display(h1,h2);
    int choice = 0; // init user 'choice'
    while(choice!=4)
    {
        cout<<"\n\n*************************\n";
        cout<<"* 1 - Add One Hour\t*\n";
        cout<<"* 2 - Add One Minute\t*\n";
        cout<<"* 3 - Add One Second\t*\n";
        cout<<"* 4 - Exit Program\t*\n";
        cout<<"*************************\n";
        cin>>choice;
/*
       In this switch statement, the user choice when is 1-4
       results in modification of both time formats.
       Choices that are not 1-4 will return string that indicates
       valid choice
*/
        switch (choice)
        {
            case 1: h1.add_hour(1);
                h2.add_hour(1);
                break;
            case 2: h1.add_minute(1);
                h2.add_minute(1);
                break;
            case 3: h1.add_seconds(1);
                h2.add_seconds(1);
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"Enter Correct Choice!!\n";
        }
        system("cls");
        display(h1,h2);
    }
}