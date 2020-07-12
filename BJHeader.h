#ifndef BLACKJACK

enum class CardSuit
{
	SUIT_CLUB,
	SUIT_DIMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUITS
};

enum class CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS
};

struct Card
{
	CardSuit suit{};
	CardRank rank{};
};

struct Player
{
	int score{};
};

deck_type createDeck();

void printCard(const Card& card);
int getCardValue(const Card& card);
void printDeck(const deck_type& deck);



#endif // !BLACKJACK

