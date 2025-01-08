#include <string>
#pragma once

// Structure to represent a bank account
struct BankAccount 
{
    std::string TitularName;
    int AccountNumber;
    double Balance;
};

// Function prototypes or declarations
void CheckBalance(const BankAccount &Account);
void DepositBalance(BankAccount &Account);
void WithdrawBalance(BankAccount &Account);
void ShowMenu(BankAccount &Account);