#include <stdio.h>
int main(){
    int size,i;
    int sum = 0,max = 0,min = 1000,sec_max=-1;
    float avg;
    int local_peak = 0;
    int count = 1,length = 1;
    int k,s,temp;
    int R,D,dcount= 0;

//for taking size and input for array

    printf("Enter size of array (5-12) : ");
    scanf("%d",&size);
    while(size<5 || size>12){
        printf("Enter again : ");
        scanf("%d",&size);
    }
    
    int n[size];

    for(i=0;i<size;i++){
        
        printf("Enter a number for element %d between (0-1000) : ",i+1);
        scanf("%d",&n[i]);
        while(n[i]<0||n[i]>1000){
            printf("Enter again : \n");
            scanf("%d",&n[i]);
        }
    }

//for printing orginal array ,sum,avg,max and min

    printf("The original array readings are :\n ");
    for(i=0;i<size;i++){
        printf("%d ",n[i]);
        sum = sum+n[i];
        if(n[i]>max){
            max = n[i];
        }

        if(n[i]<min){
            min = n[i];
        }
        }
        printf("\n");
        avg = (float)sum / size;
        printf("The sum of all elements of array is %d \n",sum);
        printf("The average of all elements is %.2f \n",avg);
        printf("The maximum value in array is %d \n",max);
        printf("The minimum value in array is %d \n",min);

//for seecond max vlaue
        for(i=0;i<size;i++){
            if(n[i] != max && n[i]>sec_max ){
            sec_max = n[i];
            }
        }
        if(sec_max == -1){
            printf("All the vlaue is same , no second largest \n");
        }
        else{
            printf("The second largest value is %d \n",sec_max);
        }

// loop for counting peak value
        for(i=1;i<size-1;i++){
            if(n[i] > n[i+1]  && n[i] >n[i-1]){
                local_peak++;
            }
        }
        printf("The peak count is %d \n",local_peak);

// for increasing contiguous order

        for(i=1;i<size;i++){
            if(n[i]>n[i-1]){
                count++;
            }
            else{
                count = 1;
            }
            if(count >length ){
                length = count;
            }
        }

    printf("THe strictly increasing contiguous run is %d \n",length);

    
//for ratation by k units

        printf("Enter k for rotating array (positive - rotates right , negative - rotate left )");
        scanf("%d",&k);
        k = k%size;
        if(k<0){
            k=k+size;
        }
        for(s=0;s<k;s++){
            temp = n[size-1];
            for(i=size-1;i>0;i--){
                n[i] = n[i-1];
            }
            n[0] = temp;
        }

    printf("The rotated array is :");
    for(i=0;i<size;i++){
        printf("%d ",n[i]);
    }
    printf("\n");

//how many value divisible by 2

    printf("Enter last two digits of registration number : ");
    scanf("%d",&R);
    D = (R%9)+1;
    for(i=0;i<size;i++){
        if(n[i]%D==0){
            dcount++;
        }
    }

    printf("The vlaue of D is %d \n",D);
    printf("THe count of number divisible by D is %d \n",dcount);
    return 0;
}