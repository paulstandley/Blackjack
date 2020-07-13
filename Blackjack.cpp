// Blackjack.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <algorithm> // std::shuffle
#include <array>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937
#include "BJHeader.h"


int main()
{   
    int playerSore{ 0 };
    int dealerScore{ 0 };
	while (true)
	{
        char play{};
        std::cout << "Do you want too play Blackjack (y) or (n) : ";
        std::cin >> play;
        if (play == 'y')
        {
            auto deck{ createDeck() };
            shuffleDeck(deck);
            if (playBlackjack(deck))
            {
                playerSore++;
                std::cout << "You win!\n";
                std::cout << "your score is " << playerSore << 
                    " and the dealers is " << dealerScore << '\n';
            }
            else
            {
                dealerScore++;
                std::cout << "You lose!\n";
                std::cout << "your score is " << playerSore <<
                    " and the dealers is " << dealerScore << '\n';
            }
        }
        else
        {
            return 0;
        }
	}

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
