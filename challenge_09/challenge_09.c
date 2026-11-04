#include <stdio.h>
#define ROWS 5
#define COLS 8

void initializeSeats(int seats[ROWS][COLS]);
void displaySeats(int seats[ROWS][COLS]);
int bookSeat(int seats[ROWS][COLS], int row, int col);
int cancelSeat(int seats[ROWS][COLS], int row, int col);
int reserveGroup(int seats[ROWS][COLS], int groupSize);
void displayReport(int seats[ROWS][COLS]);

int main(){
    int choice;
    int seats[ROWS][COLS];
    int row,col;
    int size;

    initializeSeats(seats);

    do{
        printf("Choose an option from menu :- \n");
        printf("1. Display Seats \n");
        printf("2. Book one seat \n");
        printf("3. Cancel Booking \n");
        printf("4. Group reservation \n");
        printf("5. Occupancy checker \n");
        printf("6. Exit \n");

        scanf("%d",&choice);

        while(choice<1||choice>6){
            printf("Invalid Choice Number , Enter again : ");
            scanf("%d",&choice);
        }


        if(choice == 1 ){
            displaySeats(seats);
        }

        else if(choice == 2){
            printf("Enter rows number : ");
            scanf("%d",&row);
            printf("Enter column number : ");
            scanf("%d",&col);
            if(bookSeat(seats,row,col) == 1 ){
                printf("Seat booked successfully \n");
            }
            else{
                printf("Seat is not available \n");
            }
            displaySeats(seats);
        }

        else if(choice == 3){
            printf("Enter row number : ");
            scanf("%d",&row);
            printf("Enter column number : ");
            scanf("%d",&col);
            if(cancelSeat(seats,row,col)==1){
                printf("Seat cancelled successfully \n");
            }
            else{
                printf("Seat not cancelled \n");
            }
            displaySeats(seats);
        }

        else if(choice == 4){
            printf("Enter group size (2-8): ");
            scanf("%d",&size);
            if(reserveGroup(seats,size)==1){
                printf("Group reserved \n");
            }
            else{
                printf("No seats available/Rejected \n");
            }

            displaySeats(seats);

        }

        else if(choice==5){
            displayReport(seats);
        }

        else if(choice==6){
            printf("You have exited successfully \n");
        }



    }while(choice != 6);
    
return 0;
}

void initializeSeats(int seats[ROWS][COLS]){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            seats[i][j]=0;
        }
    }
}


void displaySeats(int seats[ROWS][COLS]){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%d ",seats[i][j]);
        }
        printf("\n");
    }
    printf("Legend : 1-Booked , 0-Available  \n");
}

int bookSeat(int seats[ROWS][COLS], int row, int col){
    if(row<1||row>ROWS || col<1 || col>COLS){
        return 0;
    }
    row--;
    col--;
    if(seats[row][col] == 1){
        return 0;
    }
    else{
        seats[row][col]=1;
        return 1;
    }


}

int cancelSeat(int seats[ROWS][COLS], int row, int col){
        if(row<1||row>ROWS||col<1||COLS<col){
            return 0;
        }
        row--;
        col--;
        if(seats[row][col]==0){
            return 0;
        }
        else{
            seats[row][col]=0;
            return 1;
        }
    }


int reserveGroup(int seats[ROWS][COLS], int groupSize){
    int i,j,k,count;
    if(groupSize<2||groupSize>8){
        return 0;
    }

    for(i=0;i<ROWS;i++){
        count = 0;
        for(j=0;j<COLS;j++){
            if(seats[i][j]==0){
                count++;
            }
            else{
                count = 0;
            }
            
            if(groupSize==count){
                for(k=j;k>j-groupSize;k--){
                    seats[i][k]=1;
                }
                    printf("Group booked: Row %d, first seat %d\n", i + 1, j - groupSize + 2);
                    return 1;
                
            }
        }
    }
    return 0;    

}


void displayReport(int seats[ROWS][COLS]){
    int i,j,booked=0,max=0,count=0;
    for(i=0;i<ROWS;i++){
        count = 0;
        for(j=0;j<COLS;j++){
            if(seats[i][j]==1){
                count++;
                booked++;
            }
            if(count>max){
                max=count;
            }
        }
    }
    printf("Total tickets booked are %d \n",booked);
    printf("The free seats are %d \n",ROWS*COLS-booked);
    printf("Occupancy percentage is %.2f \n",(booked/40.0)*100.0);
    printf("The most busiest row is :- ");
    if(max==0){
        printf("None \n");
    }
    else{
        for(i=0;i<ROWS;i++){
            count=0;
            for(j=0;j<COLS;j++){
                if(seats[i][j]==1){
                    count++;
                } 
            }
            if(count==max){
                printf("%d ",i+1);
            }
        }
        printf("\n");
    }

}