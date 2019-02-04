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

	std::cout << "This is a game called Siete y medio!\nIf you don't know how to play, Google is your guide!\n";
	while (temp_int < 1) {
		std::cout << "Please specify your starting holdings: ";
		std::cin >> temp_int;
		if (temp_int < 1) std::cout << "If you have no money to bet, you can't play!\n";
	};

	Player the_player(temp_int);
	Player dealer(900);

	do {
		
		while (bet < 1 || the_player.get_wallet() < bet) {
			std::cout << "You have: $" << the_player.get_wallet() << ". Enter bet: ";
			std::cin >> bet;
			if (bet < 1 || the_player.get_wallet() < bet) std::cout << "You can't bet negative, zero, or more than you have!\n";
		};

		the_player.draw_card();
		the_player.show_hand();

		while (the_player.get_Rank() < 7.5) {
			std::cout << "Your total is " << the_player.get_Rank() << ". Do you want to draw another card? Y/N ";
			std::cin >> response;
			if (capitalize(response) != 'Y') break;
			the_player.draw_card();
			std::cout << "New card:\n";
			the_player.show_newest_card();
			std::cout << "Your cards:\n";
			the_player.show_hand();
		};
		std::cout << "Your total is " << the_player.get_Rank() << ".\n";

		while (dealer.get_Rank() < 5.5) {
			dealer.draw_card();
			std::cout << "New card:\n";
			dealer.show_newest_card();
			std::cout << "Dealer's cards:\n";
			dealer.show_hand();
			std::cout << "The dealer's total is " << dealer.get_Rank() << ".\n";
		};

		std::cout << "Play a(nother) round of Siete y medio? Y/N ";
		std::cin >> response;
		if (capitalize(response) != 'Y') break;

	} while ((0 < the_player.get_wallet()) && (0 < dealer.get_wallet()));


	return 0;
}