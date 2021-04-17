#pragma once
#include "card.h"


class Deck {
	private:
		Card *cards;
		char series[10];
		size_t sizeOfCards;
		size_t colorSize;
		size_t valueSize;
		void copy(const Deck& other);
		void standartDeck();
		void shuffle();
		void cardSeries(Card&,const char*, int);
	public:
		Deck();
		Deck(const size_t,const char*);
		Deck(const Deck& other);
		Deck& operator=(const Deck& other);
		~Deck();
		Card draw();
		void swap(size_t,size_t);
		int suit_count(const Color&);
		int rank_count(const Value&);
		void print();
		size_t getSizeOfCards()const;
		Card getCard(const int i);
		void setSeries(const char other[]);
		void resize(size_t size);
};