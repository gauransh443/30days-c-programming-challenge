Challenge - 07

Problem Statement :- 
A campus event uses ticket IDs from 1 to N. The scanner records N entries, but one ticket ID is missing and another ticket ID has been scanned twice. Your job is to audit the scan log, identify the missing and duplicate IDs, and measure how far the scan sequence is out of order. Plan your logic before writing code.

Requirements :-
1. Display the original scan sequence.
2. Identify the duplicated ticket ID and the missing ticket ID. Do not sort the sequence and do not use a  second array.
3. Count the out-of-order pairs. A pair of positions (i, j) is out of order when i < j and ticket[i] > ticket[j]. Count each pair of positions once. Equal values do not count as out of order.
4. Find your personalised audit ticket. Let R be the last two numeric digits of your registration number. 5,5. Calculate Target = (R % N) + 1. Display the target ID, all its one-based positions in the original sequence, and its occurrence count.
6.If N or any ticket ID is outside its allowed range, ask for that value again. If the completed sequence does not contain exactly one missing ID and one duplicated ID, display an invalid-log message.
7. Use only a one-dimensional array, loops (including nested loops), and conditional statements. Do not use a second array, sorting functions, or hard-coded outputs.



Algorithm :-
1.  Start
2.  Declare and initialize variables: i, j, n, target, R, duplicateID, missingID, ticketID, cmissing = 0, cduplicate = 0, targetcount = 0, pair = 0.
3.  Use a do-while loop to read n; if n < 5 or n > 15, print "Invalid again" and read again.
4.  Declare arr[n].
5.  Input elements using for(i=0; i<n; i++); use a while loop to re-enter arr[i] if arr[i] < 1 or arr[i] > n.
6.  Display the original sequence using a for loop for(i=0; i<n; i++).
7.  For missing and duplicate IDs, use a for loop for(ticketID=1; ticketID<=n; ticketID++).
8.  Set count = 0.
9.  Make an inner for loop for(i=0; i<n; i++); if arr[i] == ticketID, then count++.
10. If count is 0, it is the missing ID (missingID = ticketID, cmissing++); if count is 2, it is the duplicate ID (duplicateID = ticketID, cduplicate++).
11. If cmissing != 1 or cduplicate != 1, display "Invalid scan logs".
12. Else display the missing number and the duplicate number.
13. For out-of-order pairs, make an outer for loop for(i=0; i<n; i++).
14. Make an inner for loop for(j=i+1; j<n; j++); if arr[i] > arr[j], then pair++.
15. Display the out-of-order pair count.
16. Take the last two digits of the registration number from the user and store them in R.
17. Calculate target = (R % n) + 1.
18. Display target.
19. Make a for loop for(i=0; i<n; i++); if arr[i] == target, display the position i+1 and do targetcount++.
20. Display targetcount.
21. Stop
