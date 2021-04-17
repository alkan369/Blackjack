#include <iostream>
#include "game.h"
#include "myCstring.h"
#include <cassert>

void Game::game() {
	bool newPlayer = false;
	bool anotherGame = false;
	if (player.getName() != nullptr) {
		printPlayerStats();
		std::cout << "Do you want to enter a new player or play with this one ? Yes/No : ";
		char message[4];
		std::cin.getline(message, 4);
		if (myStrcmp(message, "Yes") == 0) {
			newPlayer = true;
		}
		anotherGame = true;
		player.removeHand();
		dealer.removeHand();
		player.removePoints();
		dealer.removePoints();
	}
	if(newPlayer || player.getName() == nullptr) {
		std::cout << "Enter player name :";
		char name[100];
		std::cin.getline(name, 100);
		std::cout << "Enter age :";
		assert(validName(name));
		size_t age;
		std::cin >> age;
		assert(validAge(age));
		player.setName(name);
		player.setAge(age);
		if (newPlayer) {
			player.removeWins();
			player.removeGames();
		}
	}
	std::cout << "Enter the size of the deck :";
	size_t size;
	std::cin >> size;
	assert(size <= 104);
	std::cin.ignore();
	if (size == 52) {
		if (anotherGame) {
			deck.resize(size);
		}
		display();
	}
	else {
		deck.resize(size);
		display();
	}
}

void Game::display() {
	player.printCurrentHand();
	std::cout << "Hit/Stand/Probability" << std::endl;
	char message[12];
	std::cin.getline(message, 12);
	if (myStrcmp(message, "Hit") == 0) {
		player.setHand(deck.draw());
		if (player.getPoints() > 21) {
			std::cout << "Points are more than 21 you lose :(" << std::endl;
			player.setGame();
			ask();
		}
		else {
			display();
		}
	}
	else if(myStrcmp(message, "Stand") == 0){
		dealerGame();
	}
	else if(myStrcmp(message,"Probability") == 0) {
		std::cout << probability() << std::endl;
		display();
	}
	else {
		std::cout << "Enter valid action" << std::endl;
		display();
	}
}

double Game::probability() {
	size_t cntPoint = 0;
	size_t notPickedCards = 0;
	size_t pointTemp = player.getPoints();
	if (21 - pointTemp > 11) {
		return 0;
	}
	else {
		size_t tempSize = deck.getSizeOfCards();
		for (int i = 0; i < tempSize; i++) {
			if (deck.getCard(i).getPicked() == false) {
				if (deck.getCard(i).getValuePoints() == 21 - pointTemp) {
					++cntPoint;
				}
				++notPickedCards;
			}
		}
		return double(cntPoint) / double(notPickedCards);
	}
}

void Game::dealerGame() {
	if (dealer.getPoints() <= 17) {
		dealer.setHand(deck.draw());
		dealerGame();
	}
	else if (dealer.getPoints() > 21) {
		std::cout << "The dealer's draw :";
		dealer.printCurrentHand();
		std::cout << "The dealer loses and you win :) " << std::endl;
		player.setGame();
		player.setWin();
		ask();
	}
	else {
		if (dealer.getPoints() > player.getPoints()) {
			std::cout << "The dealer's draw :";
			dealer.printCurrentHand();
			std::cout << "The dealer wins and you lose :( " << std::endl;
			player.setGame();
			ask();
		}
		else {
			std::cout << "The dealer's draw :";
			dealer.printCurrentHand();
			std::cout << "The dealer loses and you win :) " << std::endl;
			player.setGame();
			player.setWin();
			ask();
		}
	}
}

bool Game::validName(const char name[]) {
	bool hasInterval = false;
	int cnt = 0;
	for (; name[cnt] != '\0'; cnt++) {
		if (name[cnt] == ' ') {
			hasInterval = true;
			break;
		}
	}
	bool capitalInNames = (name[0] >= 'A' && name[0] <= 'Z') && (name[cnt + 1] >= 'A' && name[cnt + 1] < 'Z');
	return capitalInNames && hasInterval;
}

bool Game::validAge(const size_t age) {
	return age >= 18 && age <= 90;
}

void Game::ask() {
	std::cout << "Do you want to play another game ? Yes/No : ";
	char message[4];
	std::cin.getline(message, 4);
	if (myStrcmp(message, "Yes") == 0) {
		game();
	}
	else {
		printPlayerStats();
	}
}

void Game::printPlayerStats() {
	std::cout << "Player stats : " << std::endl;
	std::cout << "Player name : ";
	player.printName();
	std::cout << "Player games :" << player.getGames() << std::endl;
	std::cout << "Player victories :" << player.getWins() << std::endl;
	player.setWinrate();
	std::cout << "Player winrate :" << player.getWinrate() << std::endl;
}