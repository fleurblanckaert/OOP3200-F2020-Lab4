/* Name: Fleur Blanckaert (100747083), Gabriel Dietrich (100764733)
   Date: Oct 11 2020
   Program: OOP 3200 - Lab 4 - Collections
   Description: This file displays to the user the different commands
				created relative to the deck of cards

*/

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
	std::cout << "A deck has been created:\n" << std::endl;;
	StandardDeck standardDeck;
	std::cout << std::endl;

	// Show the deck object as initialized
	std::cout << std::endl << "A deck has been initialized:\n" << std::endl;
	standardDeck.Initialize();
	std::cout << std::endl;
	Pause();

	// Draw the next card and show it
	std::cout << std::endl << "The next card has been drawn: ";
	standardDeck.DrawNextCard();
	std::cout << std::endl;
	Pause();


	// Draw a random card and show it
	std::cout << std::endl << "A random card has been drawn: ";
	standardDeck.DrawRandomCard();
	std::cout << std::endl;
	Pause();

	// Show the deck with the remaining cards
	std::cout << std::endl << "The deck still has ";
	std::cout << standardDeck.CardsRemaining();
	std::cout << " cards remaining." << std::endl;
	Pause();
	
	//// Shuffle the deck and show the result
	std::cout << std::endl << "The remaining cards of the deck have been shuffled:\n" << std::endl;
	standardDeck.Shuffle();
	std::cout << std::endl;
	Pause();

	// Reset the deck and show the result
	std::cout << std::endl << "The deck has been reset\n\n";
	standardDeck.Initialize();
	std::cout << std::endl;
	Pause();

	//Counts the number of cards in the deck
	std::cout << std::endl << "The deck now has " << standardDeck.CardsRemaining();
	std::cout << " cards" << std::endl;
	Pause();
	standardDeck.~StandardDeck();
	

}


