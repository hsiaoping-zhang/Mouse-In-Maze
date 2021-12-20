# Mouse in a Maze 老鼠走迷宮

Time：2017 年 11 月  
Language：C++

## Algorithm
This algorithm is aiming finding the path to the exit. Moreover, the road which was passed before will not be passed again. 
Therefore, this algorithm can find the exit in the end.  
> 此演算法的規則是會記錄走過的路，並且不會再次走死胡同的路，如果遇到死路則會回頭找還沒走過的路當路徑

## Program
#### parameters  
`route_x` / `route_y` (type:stack) : store route the mouse had passed  

`current_x` / `current_y` : store the current position  

`step_found` : every round whether the current position find the possible exit  

`found` : whether the mouse find the exit  

#### process
Firstly, we read the input data and find the started position and ended position. 
Next,we try every posibble direction then push it into the stack(route).
Every time we find the posibble direction, allowing the current position '\*'.
If there is no posibble direction can pass :  
* `step==2` : **return the started position**  
there is no route for the maze, break out the for loop  

* `step!=2` : **just go back the previous step**  
current position='1'(block) ,pop the top data and then continue search the possible direction  

In the end, if `found==true` ,then print out the result.  
