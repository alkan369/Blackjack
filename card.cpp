#include "card.h"
#include <cstring>
#include <iostream>
#include "myCstring.h"

void Card::copy(const Card& other) {
	setColor(other.color);
	setValue(other.value);
	setSeries(other.seriesNum);
	setPicked(other.picked);
}

Card::Card() {
	setColor(NoColor);
	setValue(NoValue);
	setSeries("No series");
	setPicked(false);
}


Card::Card(Color& _color, Value& _value, char _seriesNum[]) {
	setColor(_color);
	setValue(_value);
	setSeries(_seriesNum);
	setPicked(false);
}

Card::Card(const Card& other) {
	copy(other);
}


Card& Card::operator=(const Card& other) {
	if (this != &other) {
		copy(other);
	}
	return *this;
}

Color Card::getColor()const {
	return color;
}

Value Card::getValue() const {
	return value;
}

char Card::getSeries()const {
	return *seriesNum;
}

bool Card::getPicked()const {
	return picked;
}

size_t Card::getValuePoints()const {
	if (value >= 1 && value <= 9) {
		return value;
	}
	else if (value >= 10 && value <= 12) {
		return 10;
	}
	else {
		return 11;
	}
}

void Card::setColor(const Color& _color) {
	color = _color;
}

void Card::setValue(const Value& _value) {
	value = _value;
}

void Card::setSeries(const char _series[]) {
	myStrCpy(seriesNum, 15, _series);
}

void Card::setPicked(const bool pick) {
	picked = pick;
}

void Card::printSeries()const {
	std::cout << seriesNum << std::endl;
}

bool Card::operator==(const Card& other) {
	return value == other.value && color == other.color;
}

bool Card::operator!=(const Card& other) {
	return !(*this == other);
}


