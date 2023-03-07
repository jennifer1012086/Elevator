#include<iostream>
#include<stdbool.h>
#include<math.h>
#include<string>
#include <cstdlib>
#include <ctime>

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

// check the input floor is valid or not
bool input_check(string current, string floor)
{
    if(current != "1" && current != "2" && current != "3" && current != "4" && current != "5"
    && current != "6" && current != "7" && current != "8" && current != "9" && current != "10")
    {
        return false;
    }
    if(floor != "1" && floor != "2" && floor != "3" && floor != "4" && floor != "5"
    && floor != "6" && floor != "7" && floor != "8" && floor != "9" && floor != "10")
    {
        return false;
    }
    return true;
}

// recompute the result to ensure the elevator move the smallest distance
bool elevator_simulator_test(int current, int floor, int elevator1_origin, int elevator2_origin, int choice)
{
    int move_distance1 = 0;
    int move_distance2 = 0;

    move_distance1 = abs(current-elevator1_origin) + abs(current-floor);
    move_distance2 = abs(current-elevator2_origin) + abs(current-floor);

    if( choice == 1 && move_distance1 <= move_distance2 ) return true;
    else if( choice == 2 && move_distance2 <= move_distance1 ) return true;
    else return false;

}


int main(int argc, char **argv)
{
    Elevator elevator1;
    Elevator elevator2;

    elevator1.set_floor(1); //initialize the elevator at first floor
    elevator2.set_floor(1); //initialize the elevator at first floor

    string current_s, floor_s;
    int current, floor;
    int elevator1_origin, elevator2_origin;
    int choice;
    string user_mode = argv[1]; // 0: test mode, 1: user mode

    srand( time(NULL) ); //random seed

    for(int i=1; i<=2; i++) // print the initial elevator floor
    {
        cout << "elevator " << i << ": " << "[" << 1 << "]";
        for(int j=2; j<=10; j++)
        {
            cout << j  << " ";
        }
        cout << endl;
    }      

    while(true)
    {
        cout << endl << "Please input the current floor: ";
        if(user_mode != "0") // user input
        {
            cin >> current_s;  
            current = stoi(current_s);
        } 
        else //test mode (random choose a number from 1-10)
        {
            current = rand()%10+1; 
            cout << current <<endl;
            current_s = "1";
        }        

        cout << "Please input the destination: ";
        if(user_mode != "0")// user input
        {
            cin >> floor_s;  
            floor = stoi(floor_s);
        } 
        else //test mode (random choose a number from 1-10)
        {
            floor = rand()%10+1; 
            cout << floor <<endl;
            floor_s = "1";
        }
        
        if( !input_check(current_s, floor_s) ) // invalid input
        {
            cout << "invalid input" << endl;
            continue;
        }

        elevator1_origin = elevator1.get_floor();
        elevator2_origin = elevator2.get_floor();
        
        if (abs(elevator1_origin-current) <= abs(elevator2_origin-current)) //elevator1 is closer
        {
            cout << "call elevator1" << endl; //choose elevator1
            choice = 1;
            
            elevator1.move(elevator1.get_floor(), current); //move the elevator to the current floor
            elevator1.move(elevator1.get_floor(), floor); // move the elevator to the destination floor
            
            cout << "elevator 1: " ;
            elevator1.display_floor();
            cout << "elevator 2: ";
            elevator2.display_floor();
        }
        else //elevator2 is closer
        {
            cout << "call elevator2" << endl; //choose elevator2
            choice = 2;

            elevator2.move(elevator2.get_floor(), current); //move the elevator to the current floor
            elevator2.move(elevator2.get_floor(), floor); // move the elevator to the destination floor
            
            cout << "elevator 1: " ;
            elevator1.display_floor();
            cout << "elevator 2: ";
            elevator2.display_floor();
        }

        if( user_mode == "1" ) //test mode
        {
            if(elevator_simulator_test(current, floor, elevator1_origin, elevator2_origin, choice))
            {
                continue;
            }
            else //the program will not stop if the recompute result is correct
            {
                cout << "current / floor / elevator1_origin / elevator2_origin / choice" << endl;
                cout << current << floor << elevator1_origin << elevator2_origin << choice << endl;
                break;
            }
        }

    }

    return 0;
}
