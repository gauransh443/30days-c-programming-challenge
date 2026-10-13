#include <stdio.h>
int main(){
    int price;
    int small_count = 0 , small_total = 0 , medium_count = 0 , medium_total = 0, large_count = 0,large_total=0;
    int total,valid_count;
    float avg;

    while(1){
        printf("Enter the price of item , press - 0 for stop :  ");
        scanf("%d",&price);

        if(price == 0){
            printf("Stopped Successfully \n");
            break;
        }

        else if(price<0){
            printf("Invalid Amount \n");
        }

        

        else if(price<100){
            small_count++;
            small_total = price+small_total;
        }

        else if(price >=100 && price<500){
            medium_count++;
            medium_total = price+medium_total;
        }

        else if(price>=500 ){
            large_count++;
            large_total= price + large_total;
        }

    }

    total = small_total+medium_total+large_total;
    valid_count = small_count+medium_count+large_count;

    if(valid_count == 0){
        printf("No valid expenses entered ");
    }
    else{
        avg = (float)total/valid_count;
    }
    
    


    printf("The number of valid expense are : %d \n",valid_count);
    printf("The total of valid expenses is : %d \n ",total);
    printf("The count and total of small expenses is %d and %d \n",small_count,small_total);
    printf("The count and total of medium expenses is %d and %d \n",medium_count,medium_total);
    printf("The count and total of large expenses is %d and %d \n",large_count,large_total);
    printf("The avergae of valid expenses is %.2f",avg);

    return 0;


}