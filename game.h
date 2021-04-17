#pragma once
#include "card.h"
#include "deck.h"
#include "player.h"



class Game {
	private:
		Player player;
		Player dealer;
		Deck deck;
		void display();
		double probability();
		void dealerGame();
		bool validName(const char name[]);
		bool validAge(const size_t age);
		void ask();
		void printPlayerStats();
	public:
		void game();
};