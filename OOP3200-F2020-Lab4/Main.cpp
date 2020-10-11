#include <ctime>
#include <iostream>
#include "StandardDeck.h"

void Pause() {
	std::cout << "\nPress \'ENTER\' to continue..." << std::endl;
	std::cin.ignore();	fflush(stdin);
}



int main()
{

	/*	Your main() function should demonstrate each of the features of the StandardDeck class*/
	srand(time(nullptr)); // seed the random number generator

	// create a deck
	std::cout << "A deck has been created\n" << std::endl;;
	StandardDeck standardDeck;
	std::cout << std::endl;

	// Show the deck object as initialized
	std::cout << std::endl << "A deck has been initialized\n" << std::endl;
	standardDeck.Initialize();
	Pause();

	// Draw the next card and show it
	std::cout << std::endl << "The next card has been drawn " << std::endl;
	standardDeck.DrawNextCard();
	Pause();

	// Draw a random card and show it
	std::cout << std::endl << "The random card has been drawn "  << std::endl;
	standardDeck.DrawRandomCard();
	Pause();

	// Show the deck with the remaining cards
	std::cout << std::endl << "Below are the remaining cards of the deck" << std::endl;
	std::cout << standardDeck.CardsRemaining();
	Pause();

	// Shuffle the deck and show the result
	std::cout << std::endl << "Below is a shuffled deck\n" << std::endl;
	standardDeck.Shuffle();
	Pause();

	// Reset the deck and show the result
	std::cout << std::endl << "The deck has been reset\n";
	standardDeck.Initialize();
	std::cout << std::endl << std::endl << "Number of Cards: " << standardDeck.CardsRemaining();
	Pause();

}



