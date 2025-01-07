#include <iostream>
#include <string>
#include "functionsheader.h"

// Function to display the menu
void ShowMenu(BankAccount &Account) // Shows the options available to the user
// Receives the user's choice and calls the corresponding functions
{
    int Option;

    do {
        std::cout << "\n==================== MENU BANCO ====================";
        std::cout << "\n\t\t1. Verificar Saldo";
        std::cout << "\n\t\t2. Depositar Saldo";
        std::cout << "\n\t\t3. Sacar Saldo";
        std::cout << "\n\t\t4. Sair";
        std::cout << "\n====================================================";
        std::cout << "\n\t\tEscolha uma opcao: ";
        std::cin >> Option;

        switch (Option) {
            case 1:
                CheckBalance(Account);
                break;
            case 2:
                DepositBalance(Account);
                break;
            case 3:
                WhithdrawBalance(Account);
                break;
            case 4:
                std::cout << "Encerrando o programa..." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida! Tente novamente." << std::endl;
        }
    } while (Option != 4);
}


// Function to check account balance
void CheckBalance(const BankAccount &Account) //Shows current balance
{
    std::cout << "\nSaldo atual da conta de " << Account.TitularName 
              << " (Conta " << Account.AccountNumber << "): R$ " 
              << Account.Balance << std::endl;
}

// Function to deposit balance
void DepositBalance(BankAccount &Account) // Receives the deposit amount, validates it and adds it to the balance
{
    double Value;
    std::cout << "\nDigite o valor para depositar: R$ ";
    std::cin >> Value;

    if (Value > 0) {
        Account.Balance += Value;
        std::cout << "Depósito realizado com sucesso! Saldo atualizado: R$ " 
                  << Account.Balance << std::endl;
    } else {
        std::cout << "Valor inválido para depósito!" << std::endl;
    }
}

// Function to withdraw balance
void WhithdrawBalance(BankAccount &Account) // Receives the amount to be withdrawn, validates it (sufficient balance) and deducts it from the balance
{
    double Value;
    std::cout << "\nDigite o valor para sacar: R$ ";
    std::cin >> Value;

    if (Value > 0 && Value <= Account.Balance) {
        Account.Balance -= Value;
        std::cout << "Saque realizado com sucesso! Saldo atualizado: R$ " 
                  << Account.Balance << std::endl;
    } else if (Value > Account.Balance) {
        std::cout << "Saldo insuficiente!" << std::endl;
    } else {
        std::cout << "Valor inválido para saque!" << std::endl;
    }
}