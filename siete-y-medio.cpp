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
void update_game_log(std::ostream&, int, int, Player, Player);


// Non member functions implementations (if any)
char capitalize(char to_capitalize) {
	return (to_capitalize < 123 && 96 < to_capitalize) ? (to_capitalize - 32) : to_capitalize;
};

void update_game_log(std::ostream& game_log, int round, int bet, Player player, Player dealer) {
	game_log << "-----------------------------------------------\n\nGame number: " << round << "\t\tMoney left: $" << player.get_wallet() - bet
		<< "\nBet: $" << bet << "\n\nYour cards:\n" << player.show_hand() << "\nYour total: " << player.get_Rank() << ".\n\n"
		<< "Dealer's cards:\n" << dealer.show_hand() << "\nDealer's total is: " << dealer.get_Rank() << ".\n";
};

// Stub for main
int main() {
	char response = '\0';
	int bet = 0, temp_int = 0, round = 1;
	std::ofstream log;
	log.open("gamelog.txt");
	
	std::cout << "This is a game called Siete y medio!\nIf you don't know how to play, Google is your guide!\n";
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

		while (bet < 1 || the_player.get_wallet() < bet) {
			std::cout << "You have: $" << the_player.get_wallet() << ". Enter bet: ";
			std::cin >> bet;
			if (bet < 1 || the_player.get_wallet() < bet) std::cout << "You can't bet negative, zero, or more than you have!\n";
		};

		the_player.draw_card();
		std::cout << the_player.show_hand();

		while (the_player.get_Rank() < 7.5) {
			std::cout << "Your total is " << the_player.get_Rank() << ". Do you want to draw another card? Y/N ";
			std::cin >> response;
			if (capitalize(response) != 'Y') break;
			the_player.draw_card();
			std::cout << "New card:\n";
			the_player.show_newest_card();
			std::cout << "Your cards:\n";
			std::cout << the_player.show_hand();
		};
		std::cout << "Your total is " << the_player.get_Rank() << ".\n";

		while (dealer.get_Rank() < 5.5) {
			dealer.draw_card();
			std::cout << "New card:\n";
			dealer.show_newest_card();
			std::cout << "Dealer's cards:\n";
			std::cout << dealer.show_hand();
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

		update_game_log(log, round, bet, the_player, dealer);
		++round;

		std::cout << "Play another round of Siete y medio? Y/N ";
		std::cin >> response;
		if (capitalize(response) != 'Y') break;

	} while ((0 < the_player.get_wallet()) && (0 < dealer.get_wallet()));

	std::cout << "Game's concluded! You walk away with... $" << the_player.get_wallet() << ".\n";
	std::cout << ((0 < the_player.get_wallet() - temp_int) ? "You won $" : "You lost $");
	std::cout << the_player.get_wallet() - temp_int << "!\nCome back again!";
	return 0;
}