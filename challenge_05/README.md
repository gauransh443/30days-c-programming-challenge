Challenge - 05

Problem Statement :-
Create a menu-driven C program that lets a user choose a mathematical operation. After each operation, display the menu again. The program must stop only when the user selects Exit.

Condition :-
1) Linear: if a is not 0, x = -b/a. If a and b are both 0, infinitely many solutions. If only a is 0, no solution.
2) Factorial: only 0 to 12 is allowed, and 0! is 1.
3) Quadratic: a cannot be 0. Discriminant above 0 means two different roots, equal to 0 means two equal roots, below 0 means no real roots.
4) Any other menu choice is invalid and the menu is shown again.

Algorithm :-
1) Start
2) Declare and initialize int variable of choice ,a,b,n,c,i,fact,discriminant and float variable of x,root1,roo2.
3) Start the do while loop.
4) Print the menu , 1 - Solve linear equation,2 - Solve factorial , 3- solve quadratic equation,4 - exit
5) Read choice .
6) If choice == 1.
7) Read a and b 
8) If a == 0 and b == 0 , display infinitely many solutions
9) Else is a != 0 , calculate x =  -b/a and display x .
10) Else display “No solution”.
11) Else if choice == 2.
12) Read n 
13) If n<0 or n>12 , display invalid number.
14) Else , set fact = 1 , run for loop with starting point i=1 to n with i++ .
15) fact = fact*i.
16) Display fact.
17) Else if choice == 3.
18) Read a,b,c
19) If a == 0 ,display “No quadratic equation”
20) Else , calculate discriminant = b*b - 4*a*c
21) If discriminant > 0,then root 1 = (-b + sqrt(discriminant)) / (2a) and root2 = (-b - sqrt(discriminant)) / (2a) .
22) Display root1,root2.
23) Else if discriminant = 0,calculate root1 = root1 = -b / (2a) and display “Both root are equal”.
24) Else display “No real roots”.
25) Else if choice == 4 ,display “You have exited successfully”.
26) Else print invalid number.
27) Stop.
