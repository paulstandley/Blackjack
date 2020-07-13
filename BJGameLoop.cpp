#include "pch.h"
#include <algorithm> // std::shuffle
#include <array>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937
#include "BJHeader.h"


bool playerWantsHit()
{// needs type checking
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
            {// player not bust
                return false;
            }
        }
    }
}

bool dealerTurn(const deck_type& deck, index_type& nexIndex, Player& dealer)
{// Return true if dealer went bust
    while (dealer.score < minimumDealerScore)
    {// Draw until minimum value
        dealer.score += getCardValue(deck[nexIndex++]);
        std::cout << "The dealer has: " << dealer.score << '\n';
    }
    // If dealers score is too high, they went bust.
    return (dealer.score > maximumScore);
}

bool playBlackjack(const deck_type& deck)
{// Index of the card that will be drawn next. This cannot overrun the array, 
    //because a player will lose before all cards are used up.
    index_type nextCardIndex{ 0 };

    // Create the dealer and give them 1 card.
    Player dealer{ getCardValue(deck[nextCardIndex++]) };

    // Create a player and give them two cards
    Player player{ getCardValue(deck[nextCardIndex]) 
        + getCardValue(deck[nextCardIndex + 1]) };
    nextCardIndex += 2;

    std::cout << "The dealer is showing: " << dealer.score << '\n';
    if (playerTurn(deck, nextCardIndex, player))
    {// the player went bust 
        return false;
    }

    if (dealerTurn(deck, nextCardIndex, dealer))
    {// the dealer went bust player wins
        return true;
    }

    return (player.score > dealer.score);
}

