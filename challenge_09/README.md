# SEATSMART - Challenge 09

A menu-driven C program to manage seat reservations in an auditorium with 5 rows and 8 seats per row.

0 means Available and 1 means Booked.

## Menu Options

1. Display Seats
2. Book one seat
3. Cancel Booking
4. Group reservation
5. Occupancy checker
6. Exit

## Functions

- `void initializeSeats(int seats[ROWS][COLS])` - sets all 40 seats to 0.
- `void displaySeats(int seats[ROWS][COLS])` - displays the seating arrangement and the 0/1 legend.
- `int bookSeat(int seats[ROWS][COLS], int row, int col)` - books a seat using 1-based row and seat numbers. Returns 1 on success, otherwise 0.
- `int cancelSeat(int seats[ROWS][COLS], int row, int col)` - cancels a booked seat using 1-based row and seat numbers. Returns 1 on success, otherwise 0.
- `int reserveGroup(int seats[ROWS][COLS], int groupSize)` - books consecutive free seats (group size 2 to 8) in one row, first-fit. Returns 1 if booked, otherwise 0.
- `void displayReport(int seats[ROWS][COLS])` - displays booked and free seats, occupancy percentage, and the busiest row(s).


## Algorihtms
1. Start
2. Add function prototypes and defins ROWS 5 and COLS 8 .
3. Create the array seats[5][8] and call initializeSeats.
4. Show the menu (1 to 6) using do-while loop and read choice .
5. While choice is less than 1 or greater than 6, print “Invalid choice” and read it again.
6. If choice is 1 , call displayseats.
7. If choice is 2 ,read row and column then call bookSeat if it return 1 , display "Seat booked successfully"
   else display "Seat is not available".
8. Display updated seat by calling function displaySeats.
9. If choice is 3 ,read row and column then call cancelSeat if it return 1 display "Seat cancelled successfully" else display "Seat not cancelled ".
10. Display updated seat by calling function displaySeats.
11. If choice is 4 , read group size , then call reserveGroup if it return 1 , display "Group reserved"       otherwise display "No seats available".
12. Display updated seat by calling function displaySeats.
13. If choice is 5 ,call displayReport.
14. If choice is 6, print the exit message.
15. Stop .


initializeSeats(int seats[ROWS][COLS])

1. For each row i from 0 to 4:
2. For each column j from 0 to 7, set seats[i][j] = 0.

displaySeats(int seats[ROWS][COLS])

1. For each row, print all 8 seat values on one line using for loop .
2. Print the "legend: 1 is Booked, 0 is Available".

bookSeat(int seats[ROWS][COLS], int row, int col)

1. If row is less than 1 or greater than 5 , column is less than 1 or greater than 8 , return 0.
2. Decrement row--,column--.
3. If seats[row][col] is 1, return 0.
4. Set seats[row][col] = 1 and return 1.

cancelSeat(int seats[ROWS][COLS], int row, int col)

1. If row is less than 1 or greater than 5 , column is less than 1 or greater than 8 , return 0.
2. Subtract 1 from row and col.
3. If seats[row][col] is 0, return 0.
4. Set seats[row][col] = 0 and return 1.

reserveGroup(int seats[ROWS][COLS], int groupSize)

1. Declare varibale i,j,k,count = 0.
2. If groupSize is less than 2 or greater than 8, return 0.
3. Using for loop for each row from i = 0 to 4 , set count = 0.
4. Use again for loop inner for colums from j=0 to 7 
5. If seats[i][j] is 0, add 1 to count. Otherwise set count = 0.
6. If groupsize = count , then use a for loop from k = j while k>j-groupsize and update by k--.
7. Print “Group booked: Row i + 1, first seat j - groupSize + 2” ,then return 1 , otherwise return 0.

displayReport(int seats[ROWS][COLS])

1. Declare varibale i,j,booked=0,max=0,count=0.
2. Using for loop for each row and column , count its booked seats if seat[i][j]==1. Add the count to booked and update max if max< count.
3. Display booked seat , free seats using :40 - bookedseat , occupancy percentage using:  booked / 40 × 100.
4. If max is 0 , display "NONE"
5. Otherwise,using nested for loop ,  print every row number whose booked count equals max.
