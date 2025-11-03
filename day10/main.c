include <stdio.h>

int main() {
    int choice;
    int quantity;
    float total = 0;

    // Menu items and prices
    printf("Menu:
");
    printf("1. Samosa - Rs 10
");
    printf("2. Burger - Rs 50
");
    printf("3. Pizza - Rs 100
");
    printf("4. Coke - Rs 50
");
    printf("5. Coffee - Rs 30
");

    // Taking orders
    while(1) {
        printf("Enter your choice (0 to finish): ");
        scanf("%d", &choice);

        if(choice == 0) {
            break;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        switch(choice) {
            case 1:
                total += quantity * 10;
                break;
            case 2:
                total += quantity * 50;
                break;
            case 3:
                total += quantity * 100;
                break;
            case 4:
                total += quantity * 50;
                break;
            case 5:
                total += quantity * 30;
                break;
            default:
                printf("Invalid choice.
");
        }
    }

    printf("Total Bill: Rs %.2f
", total);

    return 0;
}
