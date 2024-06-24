#include "pch.h"
#include "Recognizer_BearishEngulfing.h"
Recognizer_BearishEngulfing::Recognizer_BearishEngulfing() {
	this->patternName = "Bearish Engulfing";
	//set the name of the recognizer
	this->patternLength = 2;
	//set the length of the recognizer
};
bool Recognizer_BearishEngulfing::recognize(List<SmartCandlestick^>^ smartCsList, int index) {
	bool value;
	//output value of tryget
	if (smartCsList[index]->patterns->TryGetValue(patternName, value)) return value;
	//check for the existence of pattern in the patterns to see if it has already been calculated
	else if (!inBounds(smartCsList, index) || !inBounds(smartCsList, index + 1));
	//check that the index is out of bounds do nothing
	else {
		//otherwise
		if (smartCsList[index]->topPrice < smartCsList[index + 1]->topPrice && smartCsList[index]->bottomPrice > smartCsList[index + 1]->bottomPrice &&
			smartCsList[index]->open < smartCsList[index]->close && smartCsList[index + 1]->close < smartCsList[index + 1]->open &&
			smartCsList[index]->high < smartCsList[index + 1]->high && smartCsList[index]->low > smartCsList[index + 1]->low)
		{
			//if this candlestick topPrice is greater than right candlestick topPrice and this candlestick bottomPrice is greater than right candlestick bottomPrice
			//and if this candlestick is bullish and right candlestick bearish
			//and if this candlestick high less than right candlestick high and this candlestick low greater than right candlestick high
			smartCsList[index]->setPattern(patternName, true);
			//set new pattern to true
			return true;
			//return true

		}
	}
	//if all the conditions above fail, set pattern to false return false
	smartCsList[index]->setPattern(patternName, false);
	//set new pattern to false
	return false;
	//return false
}