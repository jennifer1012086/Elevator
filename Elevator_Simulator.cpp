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
        int current_floor_1;
        int current_floor_2;
    public:
        int get_floor(int elevator) // define a new method to get the current floor
        { 
            if(elevator == 1)
                return current_floor_1;
            else
                return current_floor_2; 
        } 
        void set_floor(int elevator, int new_floor) // define a new method to set the current floor
        { 
            if(elevator == 1)
                current_floor_1 = new_floor;
            else
                current_floor_2 = new_floor;
                 
        } 
        void display_floor() // display the current floor
        {
            cout << "elevator1 :" << endl;
            for(int i=1; i<=10; i++)
            {
                if( i == get_floor(1) )
                {
                    cout << "[" << i << "] " ;
                    continue;
                }
                cout << i << " ";
            }
            cout << endl;
            cout << "elevator2 :" << endl;
            for(int i=1; i<=10; i++)
            {
                if( i == get_floor(2) )
                {
                    cout << "[" << i << "] " ;
                    continue;
                }
                cout << i << " ";
            }
            cout << endl << endl;;
        } 
        void move(int current, int floor, int elevator) // move the elevator to the destination and show every floor it visited
        {
            if(current > floor) // if the elevator need to go down
            {
                //cout << "elevator down" << endl; //*************************
                while(get_floor(elevator) > floor) 
                {
                    display_floor(); //******************************
                    sleep(1);
                    set_floor(elevator, get_floor(elevator)-1);
                }

                display_floor(); // display the final floor //**************************
                //cout << "elevator arrived" << endl; //******************************
            }
            else // if the elevator need to go up
            {
                //cout << "elevator up" << endl;
                while(get_floor(elevator) < floor)
                {
                    display_floor(); //*********************************
                    sleep(1);
                    set_floor(elevator, get_floor(elevator)+1);
                }

                display_floor(); // display the final floor //*****************************
                //cout << "elevator arrived" << endl; //**********************************
            }
        }
};

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
    Elevator elevator;

    elevator.set_floor(1,1); //initialize the elevator at first floor
    elevator.set_floor(2,1); //initialize the elevator at first floor

    string current_s, floor_s;
    int current, floor;
    int elevator1_origin, elevator2_origin;
    int choice;
    string user_mode = argv[1]; // 0: test mode, 1: user mode

    srand( time(NULL) );

    for(int i=1; i<=2; i++)
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
        if(user_mode != "0")
        {
            cin >> current_s;  // user input
            current = stoi(current_s);
        } 
        else 
        {
            current = rand()%10+1; //test mode
            cout << current <<endl;
            current_s = "1";
        }        

        cout << "Please input the destination: ";
        if(user_mode != "0")
        {
            cin >> floor_s;  // user input
            floor = stoi(floor_s);
        } 
        else 
        {
            floor = rand()%10+1; //test mode
            cout << floor <<endl;
            floor_s = "1";
        }
        
        if( !input_check(current_s, floor_s) ) // invalid input
        {
            cout << "invalid input" << endl;
            continue;
        }

        elevator1_origin = elevator.get_floor(1);
        elevator2_origin = elevator.get_floor(2);
        
        if (abs(elevator1_origin-current) <= abs(elevator2_origin-current)) //elevator1 is closer
        {
            cout << "call elevator1" << endl;
            choice = 1;
            
            elevator.move(elevator.get_floor(1), current, 1); //move the elevator to the current floor
            elevator.move(elevator.get_floor(1), floor, 1); // move the elevator to the destination floor
            
            elevator.display_floor();
        }
        else //elevator2 is closer
        {
            cout << "call elevator2" << endl;
            choice = 2;

            elevator.move(elevator.get_floor(2), current, 2); //move the elevator to the current floor
            elevator.move(elevator.get_floor(2), floor, 2); // move the elevator to the destination floor
            
            elevator.display_floor();
        }

        if( user_mode == "1" ) //test mode
        {
            if(elevator_simulator_test(current, floor, elevator1_origin, elevator2_origin, choice))
            {
                continue;
            }
            else
            {
                cout << "current / floor / elevator1_origin / elevator2_origin / choice" << endl;
                cout << current << floor << elevator1_origin << elevator2_origin << choice << endl;
                break;
            }
        }

    }

    return 0;
}
