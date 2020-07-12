// Enum class for Blackjack console game
#include "pch.h"
#include <algorithm> // std::shuffle
#include <array>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937
#include "BJHeader.h"


// Create aliases.
using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

deck_type createDeck()
{
	deck_type deck{};
	index_type card{ 0 };
}

// Maximum score before losing
constexpr int maximumScore{ 21 };
// Minimum score for dealer to have
constexpr int minimumDealerScore{ 17 };

void printCard(const Card& card)
{// switch on suit and rank of Card
	switch (card.suit)
	{
	case CardSuit::SUIT_CLUB:
		std::cout << 'C';
		break;
	case CardSuit::SUIT_DIMOND:
		std::cout << 'D';
		break;
	case CardSuit::SUIT_HEART:
		std::cout << 'H';
		break;
	case CardSuit::SUIT_SPADE:
		std::cout << 'S';
		break;

	default:
		std::cout << '?';
		break;
	}

	switch (card.rank) {
	case CardRank::RANK_2:
		std::cout << '2';
		break;
	case CardRank::RANK_3:
		std::cout << '3';
		break;
	case CardRank::RANK_4:
		std::cout << '4';
		break;
	case CardRank::RANK_5:
		std::cout << '5';
		break;
	case CardRank::RANK_6:
		std::cout << '6';
		break;
	case CardRank::RANK_7:
		std::cout << '7';
		break;
	case CardRank::RANK_8:
		std::cout << '8';
		break;
	case CardRank::RANK_9:
		std::cout << '9';
		break;
	case CardRank::RANK_10:
		std::cout << 'T';
		break;
	case CardRank::RANK_JACK:
		std::cout << 'J';
		break;
	case CardRank::RANK_QUEEN:
		std::cout << 'Q';
		break;
	case CardRank::RANK_KING:
		std::cout << 'K';
		break;
	case CardRank::RANK_ACE:
		std::cout << 'A';
		break;

	default:
			std::cout << '?';
		break;
	}
}

int getCardValue(const Card& card)
{// rank 2 to 10 + 2 and a switch for the rest
	if (card.rank <= CardRank::RANK_10)
	{
		return (static_cast<int>(card.rank) + 2);
	}
	switch (card.rank)
	{
	case CardRank::RANK_JACK:
	case CardRank::RANK_QUEEN:
	case CardRank::RANK_KING:
		return 10;
	case CardRank::RANK_ACE:
		return 11;
	default:// Somthing gone so horibly wrong :-(
		return 0;
	}
}

void printDeck(const deck_type& deck)
{// use printCard to print the deck
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << '\n';
}

