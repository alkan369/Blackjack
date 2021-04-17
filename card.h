#pragma once
#include "ColorAndValue.h"


class Card {
	private:
		Color color;
		Value value;
		char seriesNum[15];
		bool picked;
		void copy(const Card& other);
	public:
		Card();
		Card(Color&, Value&, char*);
		Card(const Card& other);
		Card& operator=(const Card& other);
		Color getColor()const;
		Value getValue()const;
		char getSeries()const;
		bool getPicked()const;
		size_t getValuePoints()const;
		void setColor(const Color& _color);
		void setValue(const Value& _other);
		void setSeries(const char _series[]);
		void setPicked(const bool);
		void printSeries()const;
		bool operator==(const Card& other);
		bool operator!=(const Card& other);
};

