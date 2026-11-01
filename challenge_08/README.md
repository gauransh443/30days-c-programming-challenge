Problem Statement :- 
Campus security has divided a high-traffic area into an N × N grid. Each cell stores a risk score from a sensor: 0 means no risk and 100 means the highest risk. You must build a C program called GRIDWATCH that traverses the grid in different ways to identify risky zones and recommend a response. This is not just a maximum-value problem: your solution must correctly analyse rows, columns, diagonals, boundaries, and neighbouring cells.

Condition:-
1. Row traversal: calculate each row total and identify all row numbers with the highest total.
2. Column traversal: calculate each column total and identify all column numbers with the highest total.
3. Full-grid traversal: find the highest risk score, display every position where it occurs, and count how many cells have a score greater than or equal to T.
4. Diagonal traversal: calculate the main diagonal sum (top-left to bottom-right) and the secondary diagonal sum (top-right to bottom-left). If both sums are equal, report that the diagonal totals are balanced.
5. Boundary traversal: calculate the total of all boundary cells. Count each boundary cell exactly once, including corners.
6. Neighbour traversal: identify every local hotspot. A hotspot must be an interior cell whose value is strictly greater than its top, bottom, left, and right neighbours, and is also greater than or equal to T. Diagonal neighbours do not count.
7. Decision using conditions: display CRITICAL if at least one local hotspot exists; otherwise display WARNING if at least N cells meet or exceed T; otherwise display NORMAL.


Algorithm:-
1. Start
2. Declare and initialize variable i,j,n,threshold,t_count = 0 ,sum = 0,topleft_diagonal = 0, topright_diagonal = 0, boundary_total = 0, hotspot_count = 0 , max_row ,max_col,max_score.
3. Read n , using while loop if n< 3 or n > 6 , take input again.
4. Create matrix using grid[n][n]. Using nested for loop take input one by one, using while loop if input is less than 0 or greater than 100 , display "Invalid score and enter again".
5. Read the threshold using while loop if threshold < 1 or threshold > 100 ,display "Invalid" and take input again.
6. Set max_row to grid[0][0]. For each row, set sum to 0, add all the elements of that row to sum, and display the sum of row i+1. If sum is greater than max_row, store sum in max_row.
7. Again using for nested loop display the number (i+1) of every row , if sum is equal to max_row.
8. Set max_col to grid[0][0]. For each column, set sum to 0, add all the elements of that column to sum, and display the sum of column j+1. If sum is greater than max_col, store sum in max_col.
9. Again using for nested loop display the number (j+1) of every column , if sum is equal to max_col.
10. Set max_score to grid[0][0]. Using for nested loop if the grid[i][j] is greater than max_score, store it in max_score.
11. If the cell is greater than or equal to the threshold, t_count++.
12. Display max_score.
13. Using for nested loop again display the position (row i+1, column j+1) if grid[i][j] = max_score. Then display t_count.
14. Using for loop , topleft_diagonal = grid[i][i] + topleft_diagonal and topright_diagonal = grid[i][n-1-i] + topright_diagonal. If both sums are equal, print "Both diagonals are balanced". Otherwise, print "Both diagonals are not balanced".
15. Use nested loop again , add all element in the first row, the last row, the first column or the last column, add it to boundary_total using if and "or" logical operator. Display boundary_total.
16. Using nested loop in which i and j go from 1 to n-2. If a cell is strictly greater than its top, bottom, left and right neighbours, and is also greater than or equal to the threshold, display position and score , then hotspot_count++.
17. If hotspot_count = 0 after checking all the interior cells, print "No local hotspot found".
18. If hotspot_count is greater than 0, print "Status: CRITICAL". Otherwise, if t_count is greater than or equal to n, print "Status: WARNING". Otherwise, print "Status: NORMAL".
19. Stop.