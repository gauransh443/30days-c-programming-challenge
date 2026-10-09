/*
A student is purchasing items from an online store. Read the purchase amount, customer type (1 = Student, 2 = Regular Customer),
and delivery distance in kilometres. Determine the discount and delivery charge using conditional statements. Display the purchase
amount, discount amount, amount after discount, delivery charge, and final payable amount.
*/

#include <stdio.h>
int main(){
    float purchase_amount,customer_type , distance ,discount , after_dis,delivery,del_charges,final;

    printf("Enter Purchase Amount : \n");
    scanf("%f",&purchase_amount);
    printf("Enter 1 - Student , 2 - Regular customer : \n");
    scanf("%f",&customer_type);
    printf("Enter delivery distance in kilometers : ");
    scanf("%f",&distance);

    if(customer_type == 1 && purchase_amount>=2000){
        discount = purchase_amount*0.15;
    }
    else if(customer_type == 1 && purchase_amount<2000){
        discount = purchase_amount*0.10;
    }
    else if(customer_type == 2&& purchase_amount>=3000){
        discount = purchase_amount*0.08;
    }
    else{
        discount = 0;
    }

    after_dis = purchase_amount-discount;


    if (distance<=5){
        del_charges = 40;
    }
    else if(distance >5 && distance <=15){
        del_charges = 70;
    }
    else{
        del_charges = 100;
    }

    final = after_dis+del_charges;

    printf("Purchase amount is : %.2f \n",purchase_amount);
    printf("Discount amount is : %.2f\n",discount);
    printf("Amount after discount is : %.2f\n",after_dis);
    printf("Delivery Charges is : %.2f \n",del_charges);
    printf("Final payable amount is : %.2f\n",final);
    return 0;

}