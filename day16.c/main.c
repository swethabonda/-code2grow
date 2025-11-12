#include <stdio.h>

int main() {
    int price[5] = {50, 30, 80, 120, 60}; // Fixed prices for Coffee, Tea, Sandwich, Burger, Pastry
    char items[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int quantitySold[5] = {0};  // To track total quantity sold for each item
    int customers, i, j, n, itemNo, qty;
    int totalRevenue = 0;

    printf("===== Café Order Management System =====\n");
    printf("\nMenu:\n");
    printf("1. Coffee   - Rs %d\n", price[0]);
    printf("2. Tea      - Rs %d\n", price[1]);
    printf("3. Sandwich - Rs %d\n", price[2]);
    printf("4. Burger   - Rs %d\n", price[3]);
    printf("5. Pastry   - Rs %d\n", price[4]);

    printf("\nEnter total number of customers (max 10): ");
    scanf("%d", &customers);

    for(i = 1; i <= customers; i++) {
        int customerTotal = 0;

        printf("\n--- Customer %d ---\n", i);
        printf("Enter number of items: ");
        scanf("%d", &n);

        for(j = 1; j <= n; j++) {
            printf("Enter item number and quantity: ");
            scanf("%d %d", &itemNo, &qty);

            customerTotal += price[itemNo - 1] * qty;
            quantitySold[itemNo - 1] += qty;
        }

        printf("Total Bill for Customer %d = Rs %d\n", i, customerTotal);
        totalRevenue += customerTotal;
    }

    // Summary after all customers
    printf("\n===== Café Summary =====\n");
    printf("Total Revenue of the Day: Rs %d\n", totalRevenue);

    int totalItemsSold = 0, mostOrderedIndex = 0, leastOrderedIndex = 0;

    for(i = 0; i < 5; i++) {
        totalItemsSold += quantitySold[i];
        if(quantitySold[i] > quantitySold[mostOrderedIndex])
            mostOrderedIndex = i;
        if(quantitySold[i] < quantitySold[leastOrderedIndex])
            leastOrderedIndex = i;
    }

    printf("Total Items Sold: %d\n", totalItemsSold);
    printf("Most Ordered Item: %s\n", items[mostOrderedIndex]);
    printf("Least Ordered Item: %s\n", items[leastOrderedIndex]);

    return 0;
}
