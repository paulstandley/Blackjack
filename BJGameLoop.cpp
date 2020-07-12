#include "pch.h"
#include <algorithm> // std::shuffle
#include <array>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937
#include "BJHeader.h"


bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

bool playerTurn(const deck_type& deck, index_type& nextIndex, Player& player)
{// return true if player went bust else false
    while (true)
    {
        std::cout << "You have: " << player.score << '\n';
        if (player.score > maximumScore)
        {// This can happen even before the player had a choice if they drew 2 aces.
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                player.score += getCardValue(deck[nextIndex++]);
            }
            else
            {// player ont bust
                return false;
            }
        }
    }
}

