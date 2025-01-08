#include <iostream>
#include <string>

// Definition of the BankAccount structure
struct BankAccount 
{
    std::string TitularName; // Account holder's name
    int AccountNumber;       // Account number
    double Balance;          // Current balance
};

// Function to check the account balance
void CheckBalance(const BankAccount &Account) 
{
    std::cout << "\nCurrent balance of " << Account.TitularName 
              << " (Account " << Account.AccountNumber << "): $ " << Account.Balance << std::endl;
}

// Function to deposit money into the account
void DepositBalance(BankAccount &Account) 
{
    double Value;
    std::cout << "\nEnter the amount to deposit: $ ";
    std::cin >> Value;

    if (Value > 0) 
    {
        Account.Balance += Value;
        std::cout << "Deposit successful! Updated balance: $ " << Account.Balance << std::endl;
    } else 
    {
        std::cout << "Invalid amount for deposit!" << std::endl;
    }
}

// Function to withdraw money from the account
void WithdrawBalance(BankAccount &Account)
{
    double Value;
    std::cout << "\nEnter the amount to withdraw: $ ";
    std::cin >> Value;

    if (Value > 0 && Value <= Account.Balance) 
    {
        Account.Balance -= Value;
        std::cout << "Withdrawal successful! Updated balance: $ " << Account.Balance << std::endl;
    } else if (Value > Account.Balance) 
    {
        std::cout << "Insufficient funds!" << std::endl;
    } else 
    {
        std::cout << "Invalid amount for withdrawal!" << std::endl;
    }
}

// Function to end the program
void endProgram() 
{
    std::cout << "Thank you for using our program." << std::endl;
}

// Function to display the menu
void ShowMenu(BankAccount &Account) 
{
    int Option;

    do {
        std::cout << "\n==================== BANK MENU ====================";
        std::cout << "\n\t\t1. Check Balance";
        std::cout << "\n\t\t2. Deposit Money";
        std::cout << "\n\t\t3. Withdraw Money";
        std::cout << "\n\t\t4. Exit";
        std::cout << "\n===================================================";
        std::cout << "\n\t\tChoose an option: ";
        std::cin >> Option;

        switch (Option) 
        {
            case 1:
                CheckBalance(Account);
                break;
            case 2:
                DepositBalance(Account);
                break;
            case 3:
                WithdrawBalance(Account);
                break;
            case 4:
                endProgram();
                break;
            default:
                std::cout << "Invalid option! Please try again." << std::endl;
        }
    } while (Option != 4);
}

