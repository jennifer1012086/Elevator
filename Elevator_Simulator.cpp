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
        void display_floor(){ cout << current_floor << endl; } // display the current floor
        void move(int current, int floor) // move the elevator to the destination and show every floor it visited
        {
            if(current > floor) // if the elevator need to go down
            {
                cout << "elevator down" << endl;
                while(get_floor() > floor) 
                {
                    display_floor();
                    set_floor(get_floor()-1);
                }

                display_floor(); // display the final floor
                cout << "elevator arrived" << endl;
            }
            else // if the elevator need to go up
            {
                cout << "elevator up" << endl;
                while(get_floor() < floor)
                {
                    display_floor();
                    set_floor(get_floor()+1);
                }

                display_floor(); // display the final floor
                cout << "elevator arrived" << endl;
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

    for(int i=0; true; i++)
    {
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
        }
        else //elevator2 is closer
        {
            cout << "call elevator2" << endl;
            elevator2.move(elevator2.get_floor(), current); //move the elevator to the current floor
            elevator2.move(elevator2.get_floor(), floor); // move the elevator to the destination floor
        }

    }

    return 0;
}