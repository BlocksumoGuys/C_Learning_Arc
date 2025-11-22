#include <stdio.h>
#include <stdbool.h>

#define BASE_MONEY 27999.99

void CheckBalance(double balance);
void BuyItem(double *balance, const char *list[], const double prices[], int size);

int main() {
    bool isRunning = true;
    int option;
    double balance = BASE_MONEY;

    const char *list[] = {
        "ROG ASTRALL RTX 5090 TI SUPER",
        "32GB cl3 DDR6-7",
        "Ryzen 12 14900x3D"
    };

    const double prices[] = {
        6741.99,
        7900.99,
        999.99
    };

    int SizeList = sizeof(list) / sizeof(list[0]);

    while (isRunning) {
        printf("\nWelcome to the new and improved Microcenter 2! What can I do for you?\n");
        printf("1. Show your balance.\n");
        printf("2. Buy computing thingy.\n");
        printf("3. Exit.\n");
        printf("> ");
        scanf("%d", &option);

        if (option == 1) {
            CheckBalance(balance);
        } 
        else if (option == 2) {
            BuyItem(&balance, list, prices, SizeList);
        }
        else if (option == 3) {
            isRunning = false;
        }
        else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}

void CheckBalance(double balance) {
    printf("Your balance is: $%.2f\n", balance);
}

void BuyItem(double *balance, const char *list[], const double prices[], int size) {
    int option;

    printf("\nWhich item do you want to buy?\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s — $%.2f\n", i, list[i], prices[i]);
    }

    printf("> ");
    scanf("%d", &option);

    if (option < 0 || option >= size) {
        printf("Invalid selection.\n");
        return;
    }

    if (prices[option] <= *balance) {
        *balance -= prices[option];
        printf("Purchase successful! New balance: $%.2f\n", *balance);
    } else {
        printf("Not enough money!\n");
    }
}
