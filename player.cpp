#include <iostream>
#include <cstring>
#include "player.h"
#include "myCstring.h"

void Player::copy(const Player& other) {

	setName(other.name);
	setAge(other.age);
	winRate = other.winRate;
	wins = other.wins;
	games = other.games;
	currentPoints = other.currentPoints;
	cardsInHand = other.cardsInHand;
	hand = other.hand;
}

Player::Player() {
	name = nullptr;
	age = 18;
	winRate = 0;
	wins = 0;
	games = 0;
	currentPoints = 0;
	cardsInHand = 0;
}

Player::Player(const char _name[], size_t _age) {
	setName(_name);
	setAge(_age);
	winRate = 0;
	wins = 0;
	games = 0;
	currentPoints = 0;
	cardsInHand = 0;
}

Player::Player(const Player& other) {
	copy(other);
}

Player& Player::operator=(const Player& other) {
	if (this != &other) {
		delete[] name;
		copy(other);
	}
	return *this;
}

Player::~Player() {
	delete[] name;
}

void Player::cardPoints() {

	if (hand[cardsInHand].getValue() >=1 && hand[cardsInHand].getValue() <= 9) {
		currentPoints = currentPoints + int(hand[cardsInHand].getValue()) + 1;
	}
	if (hand[cardsInHand].getValue() >= 10 && hand[cardsInHand].getValue() <= 12) {
		currentPoints = currentPoints + 10;
	}
	if (hand[cardsInHand].getValue() == 13) {
		if (currentPoints + 11 > 21) {
			currentPoints = currentPoints + 1;
		}
		else {
			currentPoints = currentPoints + 11;
		}
	}
	++cardsInHand;
}

double Player::getWinrate()const {
	return winRate;
}

size_t Player::getGames()const {
	return games;
}

size_t Player::getWins()const{
	return wins;
}

size_t Player::getPoints() const {
	return currentPoints;
}

size_t Player::getCardsInHand()const {
	return cardsInHand;
}

char* Player::getName()const {
	return name;
}

void Player::setWinrate() {
	winRate = double(wins) / double(games);
}

void Player::setName(const char _name[]) {
	if (name != nullptr) {
		delete[] name;
	}
	size_t size = myStrlen(_name);
	name = new(std::nothrow) char[size + 1];
	myStrCpy(name,size + 1, _name);
}
void Player::setAge(const size_t _age) {
	age = _age;
}

void Player::setHand(const Card& card) {
	hand.push_back(card);
	cardPoints();
}

void Player::setGame() {
	++games;
}
void Player::setWin() {
	++wins;
}

void Player::printCurrentHand() {
	size_t size = hand.getSize();
	for (int i = 0; i < size; i++) {
		printValue(hand[i].getValue());
		std::cout << "("; 
		printColor(hand[i].getColor());
		std::cout << ")" << " ";
	}
	if (hand.getSize() > 0) {
		std::cout << " (Points :" << currentPoints << ")" << std::endl;
	}
}

void Player::removeCardsInHand() {
	cardsInHand = 0;
}

void Player::removeGames() {
	games = 0;
}
void Player::removeWins() {
	wins = 0;
}

void Player::removePoints() {
	currentPoints = 0;
}

void Player::printName()const {
	std::cout << name << std::endl;
}

void Player::removeHand() {
	hand.pop();
	removeCardsInHand();
}