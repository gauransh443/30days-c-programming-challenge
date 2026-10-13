# Challenge 03 – Smart Cart

## Introduction

SMARTCART :-
This C program calculates the discount, delivery charge, and final payable amount based on the purchase amount, customer type, and delivery distance using conditional statements.

## Discount Rules

* Student with purchase amount ≥ ₹2000: 15% discount.
* Student with purchase amount < ₹2000: 10% discount.
* Regular customer with purchase amount ≥ ₹3000: 8% discount.
* Regular customer with purchase amount < ₹3000: No discount.

## Delivery Rules

* Distance ≤ 5 km: ₹40 delivery charge.
* Distance > 5 km and ≤ 15 km: ₹70 delivery charge.
* Distance > 15 km: ₹100 delivery charge.



## Algorithm for this program is 


1) Start
2) Read purchase amount, customer type (1 = Student, 2 = Regular Customer),delivery distance(in km).
3) If student + purchase amount >= 2000,then discount = purchase_amount*0.15  .
4) If student + purchase amount >2000,then discount = purchase_amount*0.10  .
5) If regular  + purchase amount >= 3000,then discount = purchase_amount*0.08  .
6) If regular + purchase amount <3000,then discount = 0 .
7) Amount after discount = purchase_amount-discount.
8) If distance <= 5km , then delivery charge will be 40 .
9) If distance > 5km and <= 15k , then delivery charge will be 70.
10) If distance >15km ,then delivery charge will be 100.
11) Final charge = Amount after discount + delivery charge.
12) Print purchase_amount,discount,amount after_discount,delivery_charges,final_charges.
13) Stop.
