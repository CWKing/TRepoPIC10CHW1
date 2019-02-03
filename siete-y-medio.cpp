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
	bool playing = true;
	unsigned int bet = 0;
	while (true) {
		std::cout << "Play a(nother) game of Siete y medio? Y/N ";
		std::cin >> response;
		if (capitalize(response) != 'Y') break;

		std::cout << "Please specify your starting holdings: ";
		unsigned int temp_int = 0;
		std::cin >> temp_int;
		Player the_player(temp_int);
		Player dealer(900);
		
		while (playing && (0 < the_player.get_wallet()) && (0 < dealer.get_wallet())) {
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
		};

	};
	return 0;
}