#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "header.h"

int main() 
{
    BankAccount Account;
    Account.Balance = 0.0; // Initialize Balance

    // Generate a 5-digit random number based on the current time using function std::time
    std::srand(std::time(nullptr));
    Account.AccountNumber = 10000 + std::rand() % 90000; // Generate a random number between 10000 and 99999 using function std::rand

    // Input for user to enter their name
    std::cout << "Type your name: ";
    std::cin >> Account.TitularName;

    //Displays the menu
    ShowMenu(Account);

    return 0;
}