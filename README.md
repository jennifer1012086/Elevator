# Elevator

```
(g++ version 9.2.0)
$ g++ ./Elevator_Simulator.cpp -o elevator
$./elevator
```

The program shows how to dispatch the elevators to different user requests.
It will choose the closest elevator for the user.
The ouput of the program shows which of the elevator is chosed and the final result.
The program is set to be a non-stop loop, so the users can keep sending the requests.
The elevators are initialized at the first floor.

For example, 
If the user input 3 10, the output will be :

```
call elevator1
elevator 1: 1 2 3 4 5 6 7 8 9 [10]
elevator 2: [1] 2 3 4 5 6 7 8 9 10
```

It means the elevator is at the first floor first.
The user call the elevator from the third floor, then the elevator will go to third floor first and go to the tenth next.

Then we input 3 8, the out put will be :
```
call elevator2
elevator 1: 1 2 3 4 5 6 7 8 9 [10] 
elevator 2: 1 2 3 4 5 6 7 [8] 9 10 
```
It means the elevator is at the first floor first.
The user call the elevator from the third floor, then the elevator will go to third floor first and go to the eighth next.

However if we input 8 2 in the second input, the output will be:
```
call elevator2
elevator 1: 1 2 3 4 5 6 7 8 9 [10] 
elevator 2: 1 [2] 3 4 5 6 7 8 9 10
```
It means the elevator will choose the nearest elevator to satisfy the user request.
