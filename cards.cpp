#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

   /*
	  Default constructor for the Card class.
	  It could give repeated cards. This is OK.
	  Most variations of Blackjack are played with
	  several decks of cards at the same time.
   */
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; suite = GOLDS; break;
	case 2: suit = COPAS; suite = CUPS; break;
	case 3: suit = ESPADAS; suite = SWORDS; break;
	case 4: suit = BASTOS; suite = CLUBS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; ranke = ACE; break;
	case  2: rank = DOS; ranke = TWO; break;
	case  3: rank = TRES; ranke = THREE; break;
	case  4: rank = CUATRO; ranke = FOUR; break;
	case  5: rank = CINCO; ranke = FIVE; break;
	case  6: rank = SEIS; ranke = SIX; break;
	case  7: rank = SIETE; ranke = SEVEN; break;
	case  8: rank = SOTA; ranke = JACK; break;
	case  9: rank = CABALLO; ranke = KNIGHT; break;
	case 10: rank = REY; ranke = KING; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
	string suitNameEngl;
	switch (suite) {
	case GOLDS:
		suitNameEngl = "coins"; //Literal translation is 'golds' but use 'coins' instead
		break;
	case CUPS:
		suitNameEngl = "cups";
		break;
	case SWORDS:
		suitNameEngl = "spades"; //Literal translation is 'swords' but use 'spades' instead
		break;
	case CLUBS:
		suitNameEngl = "clubs";
		break;
	default: break;
	}
	return suitNameEngl;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
	string rankNameEngl;
	switch (rank) {
	case ACE:
		rankNameEngl = "Ace";
		break;
	case TWO:
		rankNameEngl = "Two";
		break;
	case THREE:
		rankNameEngl = "Three";
		break;
	case FOUR:
		rankNameEngl = "Four";
		break;
	case FIVE:
		rankNameEngl = "Five";
		break;
	case SIX:
		rankNameEngl = "Six";
		break;
	case SEVEN:
		rankNameEngl = "Seven";
		break;
	case JACK:
		rankNameEngl = "Jack";
		break;
	case KNIGHT:
		rankNameEngl = "Knight";
		break;
	case KING:
		rankNameEngl = "King";
		break;
	default: break;
	}
	return rankNameEngl;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

void Card::display_card() const {
	std::cout << "\t\t" << this->get_spanish_rank() << " de " << this->get_spanish_suit()
		<< "\t\t" << "(" << this->get_english_rank() << " of " << this->get_english_suit() << ").\n";
};

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return this->get_rank() < card2.get_rank();
}



/*	*************************************************
	Hand class
	************************************************* */
	// Implemente the member functions of the Hand class here.

Hand::Hand() {
	hand.reserve(15); // Max possible cards one can have before busting + 1
};

unsigned short Hand::get_Total_Rank() const {
	unsigned short total_Rank = 0;
	for (const Card& ele : this->hand) total_Rank += ele.get_rank();
	return total_Rank;
};

void Hand::display_hand() const {
	for (const Card& ele : this->hand) ele.display_card();
};

void Hand::show_newest_card2electricboogaloo() const {
	this->hand[hand.size() - 1].display_card();
};

void Hand::draw() {
	this->hand.push_back(Card());
};

//Card Hand::operator[](int index) const {
//
//};

/*	*************************************************
	Player class
	************************************************* */
	// Implemente the member functions of the Player class here.

Player::Player(int starting_money) : money(starting_money) {};

int Player::get_wallet() const {
	return this->money;
};

void Player::show_hand() const {
	this->player_hand.display_hand();
};

unsigned short Player::get_Rank() const {
	return player_hand.get_Total_Rank();
};

void Player::show_newest_card() const {
	this->player_hand.show_newest_card2electricboogaloo();
};

void Player::draw_card() {
	this->player_hand.draw();
};

