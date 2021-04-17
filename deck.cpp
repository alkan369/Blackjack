#include "deck.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "myCstring.h"

void Deck::copy(const Deck& other) {
	cards = new (std::nothrow) Card[other.sizeOfCards];
	sizeOfCards = other.sizeOfCards;
	for (int i = 0; i < sizeOfCards; i++) {
		cards[i] = other.cards[i];
	}
	if (other.series == nullptr) {
		myStrCpy(series, 10, "Copied");
	}
	else {
		myStrCpy(series, 10, other.series);
	}
	colorSize = other.colorSize;
	valueSize = other.valueSize;
}

void add(char text[], int cnt) {
	int i = 0;
	for (; text[i] != '\0'; i++) {

	}
	if (cnt >= 10) {
		if (text[i] == '\0') {
			text[i] = (cnt % 10 + '0');
			text[i + 1] = '\0';
		}
		add(text, cnt / 10);
	}
	else {
		text[i] = cnt + '0';
		text[i + 1] = '\0';
	}
}

void Deck::cardSeries(Card& card,const char series[], int cnt) {
	char temp[15];
	myStrCpy(temp, 15, series);
	add(temp, cnt + 1);
	card.setSeries(temp);
}

void Deck::standartDeck() {
	setSeries("Default");
	colorSize = 4;
	valueSize = 13;
	size_t cnt = 0;
	for (int i = 1; i <= colorSize; i++) {
		for (int j = 1; j <= valueSize; j++) {
			cards[cnt].setColor(Color(i));
			cards[cnt].setValue(Value(j));
			cardSeries(cards[cnt], series, cnt);
			//cards[cnt].setPicked(false);
			++cnt;
		}
	}
	shuffle();
}

Deck::Deck() {
	cards = new (std::nothrow) Card[52];
	sizeOfCards = 52;
	standartDeck();
}

Deck::Deck(const size_t k,const char s[]) {
	if (k > 52 * 2) {
		std::cout << "The max size for custom deck is 104 cards" << std::endl;
	}
	else if (k > 52) {
		if (s == nullptr) {
			setSeries("Custom");
		}
		else {
			setSeries(s);
		}
		size_t occurance[52] = { 0 };
		cards = new(std::nothrow) Card[k];
		sizeOfCards = k;
		colorSize = 4;
		valueSize = 13;
		int cnt = 0;
		for (int i = 1; i <= colorSize; i++) {
			for (int j = 1; j <= valueSize; j++) {
				cards[cnt].setColor(Color(i));
				cards[cnt].setValue(Value(j));
				cardSeries(cards[cnt], series, cnt);
				occurance[cnt] = 1;
				++cnt;
			}
		}
		srand(time(0));
		while (cnt != sizeOfCards) {
			size_t colorIndex = 1 + (rand() % colorSize);
			size_t valueIndex = 1 + (rand() % valueSize);
			Card temp;
			temp.setColor(Color(colorIndex));
			temp.setValue(Value(valueIndex));
			for (int k = 0; k < 52; k++) {
				if (cards[k] == temp && occurance[k] == 1) {
					occurance[k] = 2;
					cards[cnt] = temp;
					cardSeries(cards[cnt], series, cnt);
					++cnt;
					break;
				}
			}
		}
		shuffle();
	}
	else if (k == 52) {
		cards = new(std::nothrow) Card[k];
		sizeOfCards = k;
		standartDeck();
	}
	else {
		if (s == nullptr) {
			setSeries("Custom");
		}
		else {
			setSeries(s);
		}
		cards = new(std::nothrow) Card[k];
		sizeOfCards = k;
		colorSize = 4;
		valueSize = 13;
		int cnt = 0;
		bool found = false;
		srand(time(0));
		while (cnt != sizeOfCards) {
			found = false;
			size_t colorIndex = 1 + (rand() % colorSize);
			size_t valueIndex = 1 + (rand() % valueSize);
			Card temp;
			temp.setColor(Color(colorIndex));
			temp.setValue(Value(valueIndex));
			for (int i = 0; i < sizeOfCards;i++) {
				if (cards[i] == temp) {
					found = true;
				}
			}
			if (!found) {
				cards[cnt] = temp;
				cardSeries(cards[cnt], series, cnt);
				++cnt;
			}
		}
		shuffle();
	}
}

Deck::Deck(const Deck& other) {
	copy(other);
}

Deck& Deck::operator=(const Deck& other) {
	if (this != &other) {
		delete[] cards;
		copy(other);
	}
	return *this;
}

Deck::~Deck() {
	delete [] cards;
	std::cout << "Deck has been deleted" << std::endl;
}

Card Deck::draw() {
	Card tempCard(cards[sizeOfCards - 1]);
	cards[sizeOfCards - 1].setPicked(true);
	for (int i = sizeOfCards - 2; i > 0 ; i--) {
		swap(i,i + 1);
	}
	return tempCard;
}

void Deck::swap(size_t first, size_t second) {
	if (first < sizeOfCards && second < sizeOfCards) {
		Card temp(cards[first]);
		cards[first] = cards[second];
		cards[second] = temp;
	}
	else {
		std::cout << "The operation cannot be made" << std::endl;
		return;
	}
}


int Deck::suit_count(const Color& color) {
	int cnt = 0;
	for (int i = 0; i < sizeOfCards; i++) {
		if (cards[i].getColor() == color) {
			++cnt;
		}
	}
	return cnt;
}

int Deck::rank_count(const Value& value) {
	int cnt = 0;
	for (int i = 0; i < sizeOfCards; i++) {
		if (cards[i].getValue() == value && cards[i].getPicked() == false) {
			++cnt;
		}
	}
	return cnt;
}

void Deck::shuffle() {
	srand(time(0));

	size_t randomIndex = 0;

	for (size_t i = 0; i < sizeOfCards; i++) {
		randomIndex = rand() % sizeOfCards;
		swap(i,randomIndex);
	}

}

void Deck::print() {
	for (int i = 0; i < sizeOfCards; i++) {
		std::cout << "------------------------------" << std::endl;
		std::cout << " Card's color :" << cards[i].getColor() << std::endl;
		std::cout << " Card's value :" << cards[i].getValue() << std::endl;
		std::cout << " Card's serialNum :"; 
		cards[i].printSeries();
		std::cout << "------------------------------" << std::endl;
	}
}

size_t Deck::getSizeOfCards()const {
	return sizeOfCards;
}

Card Deck::getCard(const int i) {
	return cards[i];
}

void Deck::setSeries(const char other[]) {
	myStrCpy(series, 10, other);
}

void Deck::resize(size_t size) {
	delete[] cards;
	Deck temp(size,nullptr);
	copy(temp);
}

