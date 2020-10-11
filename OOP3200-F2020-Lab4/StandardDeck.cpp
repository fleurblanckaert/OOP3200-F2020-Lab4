/* Name: Fleur Blanckaert (100747083), Gabriel Dietrich (100764733)
   Date: Oct 11 2020
   Program: OOP 3200 - Lab 4 - Collections
   Description: This page performs some tasks like initializing the deck
				of cards, shuffling the cards in the deck, drawing and
				removing cards from the deck.
*/


#include "StandardDeck.h"
//#include "PlayingCard.h"
#include <iostream>

//Sets member from PlayingCard pointer to 0
StandardDeck::StandardDeck() :ptr(NULL)
{
	//Calls method Initialize() to allocate arrays and initialize size variable
	Initialize();
}

StandardDeck::~StandardDeck()
= default;

void StandardDeck::Initialize()
{
	//Variables
	int size = 52;
	int num = 1;

	// Check if private member pointer is not equal to 0
	if (ptr != NULL)
	{
		//Deletes any deck that may be in existence
		std_deck.clear();
	}
	else
	{
		//Allocate memory for 52 cards, essentially resets size to 52
		ptr = new PlayingCard[size];
	}


	//Loop to display every card of the deck in sensible order
	for (int suit = 0; suit < PlayingCard::SUITS; suit++)
	{
		for (int rank = 1; rank <= PlayingCard::RANKS; rank++)
		{
			std_deck.push_back(PlayingCard(rank, suit, num, true));
			num++;
		}
	}

	//Displays Deck
	for (int i = 0; i < CardsRemaining(); i++)
	{
		std::cout << std_deck[i].GetRank() << " of " << std_deck[i].GetSuit() << " | ";
	}

}

StandardDeck::StandardDeck(std::vector<PlayingCard> & other_deck)
{
	// Copies the default constructor
	std_deck = other_deck;
}

StandardDeck& StandardDeck::operator=(std::vector<PlayingCard> & other_deck)
{
	// Assigns the value of cards
	std_deck = other_deck;

	// returns a reference to the object
	return(*this);
}

int StandardDeck::CardsRemaining()
{
	//Returns the size of the cards vector
	return std_deck.size();
}


void StandardDeck::DrawNextCard()
{
	// Draws next card on deck and removes it
	std_deck[0];
	std_deck.erase(std_deck.begin() + 0);

	std::cout << std_deck[0].GetRank() << " of " << std_deck[0].GetSuit();
}

void StandardDeck::DrawRandomCard()
{
	// Draws random card from deck and removes it
	int num = rand() % std_deck.size();
	std_deck[num];
	std_deck.erase(std_deck.begin() + num);

	std::cout << std_deck[num].GetRank() << " of " << std_deck[num].GetSuit();

}

void StandardDeck::Shuffle()
{
	DrawRandomCard();
	int num = rand() % std_deck.size();
	std::string removeRank = std_deck[num].GetRank();
	std::string removeSuit = std_deck[num].GetSuit();

	// Keeps drawing random cards from deck until there are no more cards
	for (int i = 0; i < CardsRemaining(); i++)
	{
		int num = rand() % std_deck.size();

		// Removes two of spades since it was already drawn
		if (std_deck[num].GetRank() == "Two" && std_deck[num].GetSuit() == "Spades")
		{
			i--;
			std_deck.erase(std_deck.begin() + num);
		}

		// Removes random card
		if (std_deck[num].GetRank() == removeRank && std_deck[num].GetSuit() == removeSuit)
		{
			i--;
			std_deck.erase(std_deck.begin() + num);
		}

		std::cout << std_deck[num].GetRank() << " of " << std_deck[num].GetSuit() << " | ";
	}
}
