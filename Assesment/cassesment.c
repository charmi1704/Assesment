#include <stdio.h>

// Function prototypes
void displayMenu();
void addItemToBill(int item, int quantity, float *total);

int main() {
    int item, quantity;
    char choice;
    float totalBill = 0.0;

    printf("Welcome to the Food Billing System\n");

    do {
        // Display the food menu
        displayMenu();
        
        printf("Enter the item number you want to order: ");
        scanf("%d", &item);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        // Add the selected item to the total bill
        addItemToBill(item, quantity, &totalBill);

        printf("Do you want to order more items? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume newline character

    } while (choice == 'y' || choice == 'Y');

    // Display the final bill
    printf("\nYour final bill is: Rs. %.2f\n", totalBill);
    printf("Thank you for visiting!\n");

    return 0;
}

void displayMenu() {
    printf("\n--- Food Menu ---\n");
    printf("1. Burger - Rs. 100\n");
    printf("2. Pizza - Rs. 250\n");
    printf("3. Sandwich - Rs. 150\n");
    printf("4. Coffee - Rs. 50\n");
    printf("-------------------\n");
}

void addItemToBill(int item, int quantity, float *total) {
    float price = 0;

    switch (item) {
        case 1: price = 100; break;
        case 2: price = 250; break;
        case 3: price = 150; break;
        case 4: price = 50; break;
        default:
            printf("Invalid item selected!\n");
            return;
    }

    *total += price * quantity;
    printf("Added %d x item %d to the bill. Current total: Rs. %.2f\n", quantity, item, *total);
}

