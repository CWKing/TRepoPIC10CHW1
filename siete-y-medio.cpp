#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
//#include <typeinfo> //For typeid (typeid([var_name]).name())
#include "cards.h"

// Global constants (if any)


// Non member functions declarations (if any)
char capitalize(char);


// Non member functions implementations (if any)
char capitalize(char to_capitalize) {
	return (to_capitalize < 123 && 96 < to_capitalize) ? (to_capitalize - 32) : to_capitalize;
};

// Stub for main
int main() {
	char response = '\0';
	int bet = 0, temp_int = 0;
	bool random = true;
	Deck the_deck = Deck();

	std::cout << "This is a game called Siete y medio!\nIf you don't know how to play, Google is your guide!\n"
		<< "Play with an infinite deck or finite deck? I/F ";
	std::cin >> response;
	if (capitalize(response) != *"I") {
		if (capitalize(response) == *"F") { random = false; }
		else {
			std:cout << "I don't understand; let's do an infinite deck!\n";
			random = true;
		}
	}
	else random = true;

	while (temp_int < 1) {
		std::cout << "Please specify your starting holdings: ";
		std::cin >> temp_int;
		if (temp_int < 1) std::cout << "If you have no money to bet, you can't play!\n";
	};

	Player the_player(temp_int);
	Player dealer(900);

	do {
		bet = 0;
		the_player.clear_player_hand();
		dealer.clear_player_hand();
		if(!random) the_deck.Shuffle();

		while (bet < 1 || the_player.get_wallet() < bet) {
			std::cout << "You have: $" << the_player.get_wallet() << ". Enter bet: ";
			std::cin >> bet;
			if (bet < 1 || the_player.get_wallet() < bet) std::cout << "You can't bet negative, zero, or more than you have!\n";
		};

		the_player.draw_card(random, the_deck);
		the_player.show_hand();

		while (the_player.get_Rank() < 7.5) {
			std::cout << "Your total is " << the_player.get_Rank() << ". Do you want to draw another card? Y/N ";
			std::cin >> response;
			if (capitalize(response) != 'Y') break;
			the_player.draw_card(random, the_deck);
			std::cout << "New card:\n";
			the_player.show_newest_card();
			std::cout << "Your cards:\n";
			the_player.show_hand();
		};
		std::cout << "Your total is " << the_player.get_Rank() << ".\n";

		while (dealer.get_Rank() < 5.5) {
			dealer.draw_card(random, the_deck);
			std::cout << "New card:\n";
			dealer.show_newest_card();
			std::cout << "Dealer's cards:\n";
			dealer.show_hand();
			std::cout << "The dealer's total is " << dealer.get_Rank() << ".\n";
		};

		if (7.5 < the_player.get_Rank()) {
			std::cout << "You lose " << bet << ".\n";
			the_player.modify_monies(-bet);
		}
		else if (7.5 < dealer.get_Rank() || 0 < (the_player.get_Rank() - dealer.get_Rank())) {
			std::cout << "You win " << bet << ".\n";
			the_player.modify_monies(bet);
			dealer.modify_monies(-bet);
		}
		else if (the_player.get_Rank() == dealer.get_Rank()) {
			std::cout << "It's a draw; you get your bet back.\n";
		}
		else {
			std::cout << "You lose " << bet << ".\n";
			the_player.modify_monies(-bet);
		};

		std::cout << "Play another round of Siete y medio? Y/N ";
		std::cin >> response;
		if (capitalize(response) != 'Y') break;

	} while ((0 < the_player.get_wallet()) && (0 < dealer.get_wallet()));

	std::cout << "Game's concluded! You walk away with... $" << the_player.get_wallet() << ".\n";
	std::cout << ((0 < the_player.get_wallet() - temp_int) ? "You won $" : "You lost $");
	std::cout << the_player.get_wallet() - temp_int << "!\nCome back again!";
	return 0;
}