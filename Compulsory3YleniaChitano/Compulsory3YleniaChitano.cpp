#include <iostream>
#include <vector>
#include <conio.h> // Needed for _getch
#include <fstream> // Needed for the password file I/O
#include <string>
#include "Header.h"



int main()
{
    char account;
    std::string sequence;
    std::string sequenceCheck;
    std::cout << "Welcome to Battleship!\n\n";
account:
    std::cout << "Press 1 if you want to create a new account or 2 to log in to your previous account.\n";
    std::cin >> account;
    std::fstream password;

    password.open("Password.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    std::getline(password, sequence);

    password.close();

    if (account == '1')
    {
        create();
        std::fstream password;

        password.open("Password.txt", std::fstream::in | std::fstream::out | std::fstream::app);
        std::getline(password, sequence);

        password.close();


        menu();
    }

    else if (account == '2')
    {
        insert();
        std::fstream password;

        password.open("PasswordCheck.txt", std::fstream::in | std::fstream::out | std::fstream::app);
        std::getline(password, sequenceCheck);

        password.close();

        

        if (sequenceCheck == sequence)
        {
            menu();
        }

        else
        {
            std::cout << "Wrong password!\n\n";
            goto account;
        }
    }

    else {
        std::cout << "Invalid input\n";
        goto account;
    }
}

   