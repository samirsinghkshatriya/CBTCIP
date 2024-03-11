#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bank account
typedef struct {
    int accountNumber;
    char accountHolder[100];
    double balance;
    int accountType; // 1 for Savings, 2 for Current
} BankAccount;

// Function to create a new bank account
BankAccount createAccount(int accountNumber, const char *accountHolder, double initialBalance, int accountType) {
    BankAccount account;
    account.accountNumber = accountNumber;
    strcpy(account.accountHolder, accountHolder);
    account.balance = initialBalance;
    account.accountType = accountType;
    return account;
}

// Function to deposit funds into an account
void deposit(BankAccount *account, double amount) {
    account->balance += amount;
    printf("Deposited %.2lf. New balance: %.2lf\n", amount, account->balance);
}

// Function to withdraw funds from an account
void withdraw(BankAccount *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawn %.2lf. New balance: %.2lf\n", amount, account->balance);
    } else {
        printf("Insufficient funds!\n");
    }
}

// Function to calculate interest based on account type
double calculateInterest(const BankAccount *account) {
    // Assume 5% interest for savings account and 2% interest for current account
    return (account->accountType == 1) ? account->balance * 0.05 : account->balance * 0.02;
}

// Function to display account information
void displayAccountInfo(const BankAccount *account) {
    printf("\nAccount Number: %d\n", account->accountNumber);
    printf("Account Holder: %s\n", account->accountHolder);
    printf("Account Type: %s\n", (account->accountType == 1) ? "Savings" : "Current");
    printf("Current Balance: %.2lf\n", account->balance);
}

int main() {
    BankAccount accounts[10]; // Assuming a maximum of 10 accounts
    int accountCount = 0;
    int choice;
    int accountNumber;

    do {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create Account
                if (accountCount < 10) {
                    int accNumber;
                    char accHolder[100];
                    double initialBalance;
                    int accType;

                    printf("Enter Account Number: ");
                    scanf("%d", &accNumber);
                    printf("Enter Account Holder Name: ");
                    scanf("%s", accHolder);
                    printf("Enter Initial Balance: ");
                    scanf("%lf", &initialBalance);
                    printf("Enter Account Type (1 for Savings, 2 for Current): ");
                    scanf("%d", &accType);

                    accounts[accountCount++] = createAccount(accNumber, accHolder, initialBalance, accType);
                    printf("Account created successfully!\n");
                } else {
                    printf("Maximum number of accounts reached!\n");
                }
                break;

            case 2: // Deposit
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        double amount;
                        printf("Enter Deposit Amount: ");
                        scanf("%lf", &amount);
                        deposit(&accounts[i], amount);
                        break;
                    }
                }
                break;

            case 3: // Withdraw
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        double amount;
                        printf("Enter Withdrawal Amount: ");
                        scanf("%lf", &amount);
                        withdraw(&accounts[i], amount);
                        break;
                    }
                }
                break;

            case 4: // Check Balance
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        displayAccountInfo(&accounts[i]);
                        break;
                    }
                }
                break;

            case 5: // Calculate Interest
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        double interest = calculateInterest(&accounts[i]);
                        printf("Interest: %.2lf\n", interest);
                        break;
                    }
                }
                break;

            case 0: // Exit
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
