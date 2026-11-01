#include <stdio.h>
int main(){
    int n,i,j,threshold;
    int sum = 0,t_count = 0;
    int topleft_diagonal=0,topright_diagonal = 0,boundary_total = 0;
    int hotspot_count=0;
    printf("Enter N (3-6): ");
    scanf("%d",&n);
    while(n<3 || n>6){
        printf("Invalid N \nEnter again : ");
        scanf("%d",&n);
    }

    int grid[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Enter risk score (0-100) for elemnt of row %d, coumn %d : ",i,j);
            scanf("%d",&grid[i][j]);
            while(grid[i][j]<0||grid[i][j]>100){
                printf("Invalid risk score \nEnter again : ");
                scanf("%d",&grid[i][j]);
            }
        }
    }

    printf("Enter threshold : ");
    scanf("%d",&threshold);
    while(threshold<1||threshold>100){
        printf("Invalid , Enter again :");
        scanf("%d",&threshold);
    }

// sum of each row ,row number with higest total

    int max_row = grid[0][0];
    for(i=0;i<n;i++){
        sum = 0;
        for(j=0;j<n;j++){
        sum = sum + grid[i][j];
    }
    printf("The sum of row  %d is %d \n",i+1,sum);
        if(sum>max_row){
            max_row=sum;
        }
}


    printf("Row number with highest total are \n");
    for(i=0;i<n;i++){
        sum = 0;
        for(j=0;j<n;j++){
            sum = sum+grid[i][j];
        }
        if(sum==max_row){
            printf("%d \n",i+1);
        }
    }

//for sumof each colmn and colmn number with highest total

    int max_col = grid[0][0];
    for(j=0;j<n;j++){
        sum = 0;
        for(i=0;i<n;i++){
            sum = sum+grid[i][j];
        }
        if(max_col<sum){
            max_col=sum;
            }
        printf("The sum of column %d is %d \n",j+1,sum);
    }

    printf("For number of colms with highest total are  \n");
    for(j=0;j<n;j++){
        sum = 0;
        for(i=0;i<n;i++){
            sum = sum+grid[i][j];

        }
        if(sum==max_col){
            printf("%d \n",j+1);
        }
    }
//for finding maximum value , its postiton printing every position of max
    int max_score = grid[0][0];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(max_score < grid[i][j]){
                max_score=grid[i][j];
            }
            if(grid[i][j]>=threshold){
                t_count++;
            }
        }
    }

    printf("Highest risk score is %d \n",max_score);
    printf("The position is :- \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(max_score == grid[i][j]){
                printf("Row %d , Column %d \n",i+1,j+1);
            }
        }
    }
    printf("The count of elements which are greater than threshold is %d \n",t_count);

//for both diagona sum 

for(i=0;i<n;i++){
    topleft_diagonal = topleft_diagonal+grid[i][i];
    topright_diagonal = topright_diagonal+grid[i][n-i-1];
}


if(topleft_diagonal==topright_diagonal){
    printf("Both diagonals are balanced \n");
}
else{
    printf("Both diagonals are not balanced \n");
}



//for boundary sum
for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
        if(i==0 || i ==n - 1 ||j == 0 || j ==n - 1){
            boundary_total += grid[i][j];
        }
    }
}

printf("Boundary total = %d\n", boundary_total);



//for finding hotspot point


    printf("Local hotspot count : \n");
    for(i = 1; i < n - 1; i++){
        for(j = 1; j < n - 1; j++){
            if(grid[i][j] > grid[i - 1][j] &&    
               grid[i][j] > grid[i + 1][j] &&    
               grid[i][j] > grid[i][j - 1] &&    
               grid[i][j] > grid[i][j + 1] &&    
               grid[i][j] >= threshold){
                printf("(Row %d, Column %d) score %d \n", i + 1, j + 1, grid[i][j]);
                hotspot_count++;
            }
        }
    }
    if(hotspot_count == 0){
        printf("No local hotspot found \n");
    }


    if(hotspot_count > 0){
        printf("Status: CRITICAL\n");
    } 
    else if(t_count >= n){
    printf("Status: WARNING\n");
    } 
    else {
    printf("Status: NORMAL\n");
    }

    return 0;
}