## Problem
Gleb is running the "free-meter" hurdles. There are $N$ hurdles given as points $(x_{i},y_{i})$ in the Cartesian plane such that $|x|,|y|<10^{9}$ and no two points $(x_{1},y_{1}),(x_{2},y_{2})$ are co-linear with the origin $(0,0)$. Gleb starts at $(1,0)$ and must cross each hurdle exactly once in any particular order before returning to the starting point to finish the race. There is no hurdle at the starting point. If Gleb runs at $\pi e$ meters per second, what is the floor of the minimum time to finish the race so that Gleb can smoke the competition? 

## Input
Input starts with one line containing the integer $1<N<10^{8}$. The next $N$ lines contain two comma separated integers $x,y$. Ex:
```
3
1,1
-1,0
0,-1
```

## Output
Output should consist of one integer, the floor of the minimum time. For this example, the total distance is $1+\sqrt{5}+2\sqrt{2}\approx6.06\rightarrow 6$. Ex:
```
6
```