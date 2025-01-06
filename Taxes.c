/**
* This program computes income taxes based on adjusted
 * gross income and a child tax credit.
 *
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

    double agi = 0.0;
    char c = 'N';
    double tax = 0.0;
    double childCredit = 0.0;
    double totalTax = 0.0;
    int numChildren = 0;

    printf("Please enter your adjusted gross income (AGI): ");
    scanf("%lf", &agi);
    //remove the "enter" endline character
    getchar();

    printf("Do you have any children? (Y) or (N)? ");
    c = getchar();

    if(c == 'y' || c == 'Y') {
        printf("How many children do you have? ");
        scanf("%d", &numChildren);
    }
    // calculating tax based on income bracket
    if (agi > 0 && agi <= 19900){
        tax = agi * .1;
    } else if (agi > 19900 && agi <= 81050){
        tax = 1990 + .12 * (agi - 19900);
    }else if (agi > 81050 && agi <= 172750){
        tax = 9328 + .22 * (agi - 81050);
    }else if (agi > 172750 && agi <= 329850){
        tax =  29502 + .24 * (agi - 172750);
    }else if (agi > 329851 && agi <= 418850){
        tax =  67206 + .32 * (agi - 329851);
    }else if (agi > 418850 && agi <= 628300){
        tax = 95686 + .35 * (agi - 418850);
    }else if (agi > 628300){
        tax = 168933.50 + .37 * (agi - 628300);
    }

    // calculating childCredit based on numChildren
    switch(numChildren) {
        case 1:
            childCredit = 2000.0;
        break;
        case 2:
            childCredit = 4000.0;
        break;
        case 3:
            childCredit = 6000.0;
        break;
        case 4:
            childCredit = 8000.0;
        break;
        case 5:
            childCredit = 10000.0;
        break;
        case 6:
            childCredit = 12000.0;
        break;
    }

    totalTax = tax - childCredit;

    // making sure total tax isn't negative
    if (totalTax < 0){
        totalTax = 0;
    }


    printf("AGI:          $%10.2f\n", agi);
    printf("Tax:          $%10.2f\n", tax);
    printf("Child Credit: $%10.2f\n", childCredit);
    printf("Total Tax:    $%10.2f\n", totalTax);

    return 0;
}
