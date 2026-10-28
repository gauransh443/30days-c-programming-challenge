#include <stdio.h>
int main(){
    int n,i,j,pair = 0,R,target;
    int duplicateID,missingID ,cduplicate = 0 ,cmissing = 0,targetcount = 0;
    int ticketID;

    do{
        printf("Enter size of array : ");
        scanf("%d",&n);
        if(n<5 || n>15){
            printf("Invalid again \n");
        }
    }while(n<5 || n>15);


    int arr[n];

    for(i=0;i<n;i++){
        printf("Enter ticket ID %d : ",i+1);
        scanf("%d",&arr[i]);
        while(arr[i]<1 || arr[i]>n){
            printf("Invalid , enter again %d \n",i+1);
            scanf("%d",&arr[i]);
        }
    }

    printf("The original scan sequence is : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    printf("\n");

    for(ticketID=1;ticketID<=n;ticketID++){
        int count = 0;
        for(i=0;i<n;i++){
            if(arr[i] == ticketID){
                count++;
            }
        }
        if(count == 0){
            missingID = ticketID;
            cmissing++;
        }

        if(count == 2){
            duplicateID = ticketID;
            cduplicate++;
        }
    }

    if(cmissing != 1 || cduplicate != 1){
        printf("Invalid scan logs \n");
    }
    else{
        printf("The missing number is %d \n",missingID);
        printf("The dupliacte number is %d \n",duplicateID);
    
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
            pair++;
            }
        }
    }

    printf("The out of order pair is %d \n",pair);


    printf("Enter last two digit of registration number : ");
    scanf("%d",&R);
    target = (R%n)+1;
    printf("Target id is %d \n",target);

    printf("The position is : ");
    for(i=0;i<n;i++){
        if(arr[i]==target){
            printf("%d ",i+1);
            targetcount++;
        }
    }
    printf("\n");

printf("The target count is %d ",targetcount);
    

return 0;

}