/* *************************************
   Ricardo Salazar, February 26, 2015

   Interface of a simple Card class
   ************************************* */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t { OROS, COPAS, ESPADAS, BASTOS };
enum suit_te {GOLDS, CUPS, SWORDS, CLUBS};

enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };
enum rank_te { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, JACK = 9, KNIGHT = 10, KING = 11 };

class Card {
public:
	Card();

	string get_spanish_suit() const;
	string get_spanish_rank() const;
	string get_english_suit() const;
	string get_english_rank() const;
	double get_rank() const;
	void display_card() const;

	bool operator < (Card card2) const;

private:
	suit_t suit;
	rank_t rank;
	suit_te suite;
	rank_te ranke;
};

class Hand {
public:
	Hand();

	double get_Total_Rank() const;
	void display_hand() const;
	void show_newest_card2electricboogaloo() const;
	void draw();

private:
	vector<Card> hand;
};


class Player {
public:
	Player(int m = 100);
	int get_wallet() const;
	void show_hand() const;
	double get_Rank() const;
	void show_newest_card() const;
	void draw_card();
	   
private:
	int money;
	Hand player_hand;

};

#endif