#include <stdio.h>
#include <math.h>
double division(double, double);
double modulus( int, int);
void print_menu();
int main()
{
    int choice;
    double first , second, result; 
    while(1) {
        print_menu();
        scanf(" %d", & choice);
        if ( choice == 7) {
            break;

    }

    if ( choice < 1 || choice > 7) {
        fprintf(stderr, " Invalid Menu Choice." );
        continue;
    }

    printf("\n Please enter the first number : "); 
    scanf(" %lf", & first);
    printf("\n Now enter the second number : "); 
    scanf(" %lf", & second);

        switch ( choice) {
            case 1:
                result = first + second;
                printf("\n The sum of %.2lf and %.2lf is %.2lf", first, second, result);
                break;
            case 2:
                result = first - second;
                printf("\n The difference of %.2lf and %.2lf is %.2lf", first, second, result);
                break;
            case 3:
                result = first * second;
                printf("\n The product of %.2lf and %.2lf is %.2lf", first, second, result);
                break;
            case 4:
                if (second == 0) {
                    fprintf(stderr, " Error: Division by zero is not allowed.\n");
                    break;
                }
                result = division(first, second);
                printf("\n The quotient of %.2lf and %.2lf is %.2lf", first, second, result);
                break;
            case 5:
                if ((int)second == 0) {
                    fprintf(stderr, " Error: Modulus by zero is not allowed.\n");
                    break;
                }
                result = modulus((int)first, (int)second);
                printf("\n The modulus of %d and %d is %d", (int)first, (int)second, (int)result);
                break;
            case 6:
                result = pow(first, second);
                printf("\n The power of %.2lf raised to %.2lf is %.2lf", first, second, result);
                break;
                 case 7:
            printf("\n Exiting the calculator. Goodbye!\n");
            break; 
        } 
        if (!isnan(result)) {
            printf("\n Result of the operation is : %.2lf", result);
        }
             

    };

    return 0;
}
double division(double a, double b) {
    if (b == 0) {
        fprintf(stderr, " Error: Division by zero is not allowed.\n");
        return NAN;
    }else {
        return a / b;
    }
    }

double modulus( int a, int b) {
    if (b == 0) {
        fprintf(stderr, " Error: Modulus by zero is not allowed.\n");
        return 0;
    } else {
        return a % b;
    }
}

void print_menu() {
    printf("\n\n-----------------------------------"); 
    printf("\n Welcome  to simple calculator. ");
    printf("\n choice one of the following option");  
    printf("\n1. Add");
    printf("\n2. Substract");
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Modulus");
    printf("\n6. Power");
    printf("\n7. Exit");
    printf("\n Now enter your choice : ");
}
