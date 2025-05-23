#include <stdio.h>

//HAVE to declare the functions first apparently. They technically have no vars yet.
void check_balance(float balance);
//* only for when the function needs to edit value
void deposit(float *balance);
void withdraw(float *balance);
//Use double. Finance has to be extremely precise.
//Doubles DO NOT WORK here. Too large for user interaction (but backend sure).

int main() {
    //what user starts with
    float balance = 7777.00;
    int choices;

    while (1) {
        //While program runs these need to be constant options
        printf("\n!!!ATM Options!!!\n");
        printf("1.Checking Balance\n");
        printf("2.Depositing\n");
        printf("3.Withdrawing\n");
        printf("4.Exit\n");
        printf("Enter your choice (1-4): ");
        //Scan for all choices at any point in time
        scanf("%d", &choices);

        //Choices is registered neatly.
        if (choices == 1) {
            check_balance(balance);
        } else if (choices == 2) {
            deposit(&balance);
        } else if (choices == 3) {
            withdraw(&balance);
        } else if (choices == 4) {
            printf("Thanks for giving me your money!\n");
            return 0;
        } else {
            printf("Invalid option! Try again.\n");
        }
    }
}

void check_balance(float balance) {
    //Very simply checks the  balance nothing greater. Function because amount moves up and down.
    printf("Current Balance: $%.2f\n", balance);
}

void deposit(float *balance) {
    float amount;
    //amount is reiterated as usage place for deposit
    printf("Amount to Deposit: $");
    scanf("%f", &amount);

    if (amount < 0) {
        //Can't deposit any negative
        printf("Error: Make the number a positive!\n");
    } else {
        //If its good add it to the original balance/amount
        *balance += amount;
        printf("New balance: $%.2f\n", *balance);
    }
}

void withdraw(float *balance) {
    float amount;
    //amount is reiterated as usage takes pplace for withdraw
    printf("Amount to Withdraw: $");
    scanf("%f", &amount);

    if (amount < 0) {
        printf("Error: Withdrawing not positive!\n");
    } else if (amount > *balance) {
        printf("Error: Insufficient Amount. Balance: $%.2f\n", *balance);
    } else {
        *balance -= amount;
        printf("Withdrawing $%.2f. New balance: $%.2f\n", amount, *balance);
    }
}