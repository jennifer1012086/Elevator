#include<iostream>
#include<stdbool.h>
#include<math.h>
using namespace std;

class Elevator
{
    private:
        int current_floor;
    public:
        int get_floor() { return current_floor; } // define a new method to get the current floor
        void set_floor(int new_floor) { current_floor = new_floor; } // define a new method to set the current floor
        void display_floor() // display the current floor
        {
            for(int i=1; i<=10; i++)
            {
                if( i == get_floor() )
                {
                    cout << "[" << i << "] " ;
                    continue;
                }
                cout << i << " ";
            }
            cout << endl;
        } 
        void move(int current, int floor) // move the elevator to the destination and show every floor it visited
        {
            if(current > floor) // if the elevator need to go down
            {
                //cout << "elevator down" << endl; //*************************
                while(get_floor() > floor) 
                {
                    //display_floor(); //******************************
                    set_floor(get_floor()-1);
                }

                //display_floor(); // display the final floor //**************************
                //cout << "elevator arrived" << endl; //******************************
            }
            else // if the elevator need to go up
            {
                //cout << "elevator up" << endl;
                while(get_floor() < floor)
                {
                    //display_floor(); //*********************************
                    set_floor(get_floor()+1);
                }

                //display_floor(); // display the final floor //*****************************
                //cout << "elevator arrived" << endl; //**********************************
            }
        }
};

int main()
{
    Elevator elevator1;
    Elevator elevator2;

    elevator1.set_floor(1); //initialize the elevator at first floor
    elevator2.set_floor(1); //initialize the elevator at first floor

    int current, floor;

    for(int i=1; i<=2; i++)
    {
        cout << "elevator " << i << ": " << "[" << i << "]";
        for(int j=2; j<=10; j++)
        {
            cout << j  << " ";
        }
        cout << endl;
    }
        

    for(int i=0; true; i++)
    {
        cout << endl << "Please input the current floor and the destination:" << endl;
        cin >> current >> floor;  // user input

        if( current<1 || current>10 || floor<1 || current>10 ) // invalid input
        {
            cout << "invalid input" << endl;
            continue;
        }
        
        if (abs(elevator1.get_floor()-current) <= abs(elevator2.get_floor()-current)) //elevator1 is closer
        {
            cout << "call elevator1" << endl;
            elevator1.move(elevator1.get_floor(), current); //move the elevator to the current floor
            elevator1.move(elevator1.get_floor(), floor); // move the elevator to the destination floor
            cout << "elevator 1: " ;
            elevator1.display_floor();
            cout << "elevator 2: ";
            elevator2.display_floor();
        }
        else //elevator2 is closer
        {
            cout << "call elevator2" << endl;
            elevator2.move(elevator2.get_floor(), current); //move the elevator to the current floor
            elevator2.move(elevator2.get_floor(), floor); // move the elevator to the destination floor
            cout << "elevator 1: " ;
            elevator1.display_floor();
            cout << "elevator 2: ";
            elevator2.display_floor();
        }

    }

    return 0;
}