LOOPLAB - Expense Manager in C
Problem Statement

Create a C program called LOOPLAB to analyse daily expenses. Keep reading expense amounts until the user enters 0. For each positive amount, classify it, update counts and totals, and finally display a summary. Use only loops, conditions, arithmetic operators and variables (no arrays, functions or strings).

Conditions
Below 100 is Small
100 to below 500 is Medium
500 or more is Large
0 stops the program and is not counted
Negative amount is invalid and is not counted
If no valid expenses are entered, show a message instead of dividing by zero


Algorithm

1. Start
2. Declare and initialize variables: price, small_count = 0, medium_count = 0, large_count = 0,small_total=0,      medium_total = 0, large_total = 0, total, valid_count, avg
3. Start a while loop with condition 1 (true)
4. Display "Enter price" and read price
5. If price == 0, stop the loop
6.If price < 0, print "Invalid amount"
7. If price < 100, then small_count++ and small_total = small_total + price
8. If price >= 100 and price < 500, then medium_count++ and medium_total = medium_total + price
9. If price >= 500, then large_count++ and large_total = large_total + price
10. valid_count = small_count + medium_count + large_count
11. total = small_total + medium_total + large_total
12. If valid_count == 0, display "No valid expenses entered"
13. Else, avg = (float)total / valid_count
14. Display valid_count, total, small_count, medium_count, large_count, small_total, medium_total, large_total, avg
15. Stop