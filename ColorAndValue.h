#pragma once

enum Color {
	NoColor,
	Clubs,
	Diamonds,
	Hearts,
	Spades
};

void printColor(const Color&);

enum Value {
	NoValue,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};

void printValue(const Value&);
