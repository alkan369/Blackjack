#pragma once
#include "card.h"
#include "deck.h"
#include "vector.h"
#include "vector.cpp"

class Player {
	private:
		char* name;
		size_t age;
		double winRate;
		size_t wins;
		size_t games;
		size_t currentPoints;
		void copy(const Player& other);
		Vector<Card>hand;
		size_t cardsInHand;
	public:
		Player();
		Player(const char _name[], size_t _age);
		Player(const Player& other);
		Player& operator=(const Player& other);
		~Player();
		void cardPoints();
		double getWinrate()const;
		size_t getGames()const;
		size_t getWins()const;
		size_t getPoints()const;
		size_t getCardsInHand()const;
		void setWinrate();
		void setName(const char*);
		void setAge(const size_t);
		void setHand(const Card& card);
		void setGame();
		void setWin();
		void printCurrentHand();
		void removeCardsInHand();
		void removeGames();
		void removeWins();
		void removePoints();
		char* getName()const;
		void printName()const;
		void removeHand();
};