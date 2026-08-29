#include <stdio.h>
#include <string.h>

typedef struct {
    char owner[50];
    int balance;
} BankAccount;

void init_account(BankAccount* account, const char* owner, int balance) {
    strncpy(account->owner, owner, sizeof(account->owner) - 1);
    account->owner[sizeof(account->owner) - 1] = '\0';
    account->balance = balance;
}

int deposit(BankAccount* account, int amount) {
    if (amount > 0) {
        account->balance = account->balance + amount;
        printf("Deposited %d\n", amount);
    }
    return account->balance;
}

int withdraw(BankAccount* account, int amount) {
    if (0 < amount && amount <= account->balance) {
        account->balance = account->balance - amount;
        printf("Withdrew %d\n", amount);
    } else {
        printf("Insufficient funds\n");
    }
    return account->balance;
}

int main(void) {
    BankAccount account;
    init_account(&account, "Bob", 200);
    deposit(&account, 100);
    withdraw(&account, 50);
    printf("Balance: %d\n", account.balance);
    return 0;
}
