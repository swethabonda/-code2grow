#include <stdio.h>

void inputProducts(int n, int ids[], char names[][20], int qty[], float price[]) {
    for (int i = 0; i < n; i++) {
        printf("Enter Product %d ID: ", i + 1);
        scanf("%d", &ids[i]);
        printf("Enter Product %d Name: ", i + 1);
        scanf("%s", names[i]);
        printf("Enter Product %d Quantity: ", i + 1);
        scanf("%d", &qty[i]);
        printf("Enter Product %d Price: ", i + 1);
        scanf("%f", &price[i]);
    }
}

void buildBill(int n, int ids[], char names[][20], int qty[], float price[], int bill[][3], float total[]) {
    for (int i = 0; i < n; i++) {
        bill[i][0] = ids[i];
        bill[i][1] = qty[i];
        bill[i][2] = (int)price[i];
        total[i] = qty[i] * price[i];
    }
}

void showBill(int n, int bill[][3], char names[][20], float total[]) {
    float grand = 0;
    printf("\nFinal Bill:\n");
    printf("ID\tName\tQty\tPrice\tTotal\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\t%.2f\n", bill[i][0], names[i], bill[i][1], bill[i][2], total[i]);
        grand += total[i];
    }
    printf("\nGrand Total: %.2f\n", grand);
}

int main() {
    int n;
    printf("Enter number of products: ");
    scanf("%d", &n);

    int ids[n];
    char names[n][20];
    int qty[n];
    float price[n];
    int bill[n][3];
    float total[n];

    inputProducts(n, ids, names, qty, price);
    buildBill(n, ids, names, qty, price, bill, total);
    showBill(n, bill, names, total);

    return 0;
}
