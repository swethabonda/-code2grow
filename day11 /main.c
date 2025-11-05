#include <stdio.h>

int main() {
    int balance = 1000, choice, amount;
    
    while(1) {
        printf("
Banking System:
");
        printf("1. Check balance
");
        printf("2. Withdraw money
");
        printf("3. Deposit money
");
        printf("4. Exit
");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Your balance is: %d
", balance);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%d", &amount);
                if(amount > balance) {
                    printf("Insufficient balance
");
                } else {
                    balance -= amount;
                    printf("Withdrawal successful
");
                }
                break;
            case 3:
                printf("Enter amount to deposit: ");
                scanf("%d", &amount);
                balance += amount;
                printf("Deposit successful
");
                break;
            case 4:
                printf("Thank you for using our service
");
                return 0;
            default:
                printf("Invalid choice
");
        }
    }

    return 0;
}
