#pragma once
#include <string>

// Structure to represent a bank account
struct BankAccount 
{
    std::string TitularName;
    int AccountNumber;
    double Balance;
};

// Function prototypes or declarations
void CheckBalance(const BankAccount &Conta);
void DepositBalance(BankAccount &Conta);
void WhithdrawBalance(BankAccount &Conta);
void ShowMenu(BankAccount &Conta);