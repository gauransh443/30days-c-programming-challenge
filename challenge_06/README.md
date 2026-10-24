Challenge - 06

Problem Statement :-
1. Read N activity readings into a one-dimensional array and complete every task below. N must be between 5 and 12 inclusive. Each reading must be an integer from 0 to 1000 inclusive. If N or a reading is invalid, ask again until valid input is entered.

2. Display the original readings in the order entered.
3. Calculate the sum and average, then identify the minimum and maximum readings.
4. Find the second-largest DISTINCT value. Repeated copies of the maximum do not count as the second-largest value. If no second-largest     distinct value exists, display a clear message.
5. Count the local peaks. A local peak is an interior element that is strictly greater than both its immediate neighbours. The first and last elements cannot be peaks.
6. Find the length of the longest strictly increasing contiguous run. The values must be next to each other in the original array. If no increase occurs, the longest run has length 1.
7. Ask for an integer K and rotate the array right by K positions. Positive K rotates right; negative K rotates left. The program must work     when the magnitude of K is greater than N. Do not use a second array.
8. Let R be the last two numeric digits of your registration number. Calculate D = (R % 9) + 1, then count how many values in the rotated array are exactly divisible by D. Display D and the count.


Algorithm :-
1. Start
2. Declare size , i , K , s , temp , R , D , sum = 0, max=0 ,min = 1000 ,sec_max = -1, local_peak=0,count = 1, length =1,dcount = 0,avg.
3. If size <5 or size>12,enter again using while loop.
4. Take elements of array according to size using for loop , if element > 1000 or element < 0 ask again using while loop.
5. Print original array using for loop starting from i=0 to i<size ,changes by i++  and calculate sum = sum + n[i],if n[i] >max then max = n    [i] , if n[i] <min ,then min = n[i].
6. Calculate average = (float)sum/size.
7. Display sum,avg,max,min.
8. Start a for loop i = 0 to i<size ,change by i++ ,then if n[i] != max and n[i]>sec_max.
9. Then sec_max = n[i].
10. If sec_max == -1 ,then display "All the values are the same".
11. Else display , sec_max.
12. For local peak value use for loop starting from 1 to size -2 .
13. If n[i]>n[i+1] and n[i]>n[i-1],then increase the local_peak counter by 1 using increment operator.
14. Display local_peak counter.
15. For checking increasing contiguous run , start a for loop from 1 to size -1 , if n[i]>n[i-1],then increase count value by 1 using increment
      Operator.
16. Else count  = 1.
17. If count > length , then length = count , then display length.
18. For rotation of array , K = K%size , if K<0 then K = K+size (K is positive then right side , K is negative then left side).
19. Start a for loop s = 0 to s<k ,then temp = n[size-1]
20. Again start a nested loop starting from i = size to i>0 , i- - ,then n[i] = n[i-1].
21. Then n[0] = temp.
22. Display rotated array using for loop starting for i  = 0 to i<size ,change by i++ , then display n[i].
23. Calculate D using D = (R%9)+1 , then display it .
24. Start a for loop again from i = 0 to i<size change by i++ ,then if n[i]%D==0 ,increase dcount++.
25. Display dcount.
26. Stop.



