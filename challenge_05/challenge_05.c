#include <stdio.h>
#include <math.h>

int main() {
    int choice, a, b, c, n, i, discriminant;
    int fact ;
    float x, root1, root2;

    do {
        printf("Choose one option from below :-\n");
        printf("1 - Solve linear equation (ax+b=0)\n");
        printf("2 - Solve factorial (n!)\n");
        printf("3 - Solve a quadratic equation (ax^2+bx+c=0)\n");
        printf("4 - Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You selected solving linear equation (ax + b = 0)\n");
            printf("Enter a :");
            scanf("%d",&a);
            printf("Enter b :");
            scanf("%d",&b);

            if (a==0 && b==0) {
                printf("Infinitely many solutions \n");
            }
            else if (a != 0) {
                x = (float)-b / a;
                printf("The value of x is %.2f \n", x);
            }
            else {
                printf("No solution \n");
            }
        }
        else if (choice == 2) {
            printf("You have selected factorial\n");
            printf("Enter number between (0-12) : ");
            scanf("%d", &n);

            if (n<0 || n>12) {
                printf("Invalid number \n");
            }
            else { 
                fact = 1;                    
                for (i = 1; i <= n; i++) {     
                    fact = fact * i;
                }
                printf("The factorial is %d\n", fact);
            }
        }
        else if (choice == 3) {
            printf("You have selected quadratic equation (ax^2+bx+c)\n");
            printf("Enter a : ");
            scanf("%d",&a);
            printf("Enter b : ");
            scanf("%d",&b);
            printf("Enter c : ");
            scanf("%d", &c);

            if (a == 0) {
                printf("This is not a quadratic equation\n");
            }
            else {
                discriminant = (b * b) - (4 * a * c);

                if (discriminant > 0) {
                    root1 = (-b + sqrt(discriminant)) / (2.0 * a);
                    root2 = (-b - sqrt(discriminant)) / (2.0 * a);
                    printf("Two distinct real roots are %.2f and %.2f\n", root1, root2);
                }
                else if (discriminant == 0) {
                    root1 = (float)-b / (2 * a);
                    printf("Both roots are equal: %.2f\n", root1);
                }
                else {
                    printf("No real roots\n");
                }
            }
        }
        else if (choice == 4) {
            printf("You have exited program successfully \n");
        }
        else {
            printf("Invalid number, enter between 1-4\n");
        }

    } while (choice != 4);

    return 0;
}