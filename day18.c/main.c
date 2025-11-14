#include <stdio.h>

int main() {
    int productID[10], quantity[10], price[10];
    char name[10][20];
    int n, choice, searchID;

    printf("Enter number of products (max 10): ");
    scanf("%d", &n);

    
    for(int i = 0; i < n; i++) {
        printf("\nProduct %d ID: ", i+1);
        scanf("%d", &productID[i]);

        printf("Product %d Name: ", i+1);
        scanf("%s", name[i]);

        printf("Quantity: ");
        scanf("%d", &quantity[i]);

        printf("Price: ");
        scanf("%d", &price[i]);
    }

    while(1) {
        printf("\n---- MENU ----\n");
        printf("1. Display all products\n");
        printf("2. Total inventory value\n");
        printf("3. Highest & Lowest value product\n");
        printf("4. Search product by ID\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nID\tName\tQty\tPrice\n");
            for(int i = 0; i < n; i++) {
                printf("%d\t%s\t%d\t%d\n", productID[i], name[i], quantity[i], price[i]);
            }
        }

        else if(choice == 2) {
            int total = 0;
            for(int i = 0; i < n; i++) {
                total += quantity[i] * price[i];
            }
            printf("Total Inventory Value = %d\n", total);
        }

        else if(choice == 3) {
            int maxVal = quantity[0] * price[0], minVal = maxVal;
            int maxIndex = 0, minIndex = 0;

            for(int i = 1; i < n; i++) {
                int val = quantity[i] * price[i];

                if(val > maxVal) {
                    maxVal = val;
                    maxIndex = i;
                }
                if(val < minVal) {
                    minVal = val;
                    minIndex = i;
                }
            }

            printf("Highest Value Product: %s (Value = %d)\n", name[maxIndex], maxVal);
            printf("Lowest Value Product: %s (Value = %d)\n", name[minIndex], minVal);
        }

        else if(choice == 4) {
            printf("Enter Product ID to search: ");
            scanf("%d", &searchID);

            int found = 0;
            for(int i = 0; i < n; i++) {
                if(productID[i] == searchID) {
                    printf("Product Found: %s, Qty: %d, Price: %d\n",
                           name[i], quantity[i], price[i]);
                    found = 1;
                    break;
                }
            }
            if(!found)
                printf("Product not found!\n");
        }

        else if(choice == 5) {
            printf("Exiting...");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
