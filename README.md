# Elevator

The program shows how to dispatch the elevators to different user requests.
It will choose the closest elevator for the user.
The ouput of the program shows the simulator of the specified elevator.
The elevators are initialized at the first floor.

For example, 
If the user input 3 10, the output will be :

```call elevator1
elevator up
1
2
3
elevator arrived
elevator up
3
4
5
6
7
8
9
10
elevator arrived
```

It means the elevator is at the first floor first.
The user call the elevator from the third floor, then the elevator will go to third floor first and go to the tenth next.

Then we input 3 8, the out put will be :
```call elevator2
elevator up
1
2
3
elevator arrived
elevator up
3
2
elevator arrived
```
It means the elevator is at the first floor first.
The user call the elevator from the third floor, then the elevator will go to third floor first and go to the eighth next.

However if we input 8 2 in the second input, the output will be:
```call elevator1
elevator down
10
9
8
elevator arrived
elevator down
8
7
6
5
4
3
2
```
It means the elevator will choose the nearest elevator to satisfy the user request.
