#include "pch.h"
#include "Recognizer_Peak.h"
Recognizer_Peak::Recognizer_Peak() {
	this->patternName = "Peak";
	//set the name of the recognizer
	this->patternLength = 3;
	//set the length of the recognizer
};
bool Recognizer_Peak::recognize(List<SmartCandlestick^>^ smartCsList, int index) {
	bool value;
	//output value of tryget
	if (smartCsList[index]->patterns->TryGetValue(patternName, value)) return value;
	//check for the existence of pattern in the patterns to see if it has already been calculated
	else if (!inBounds(smartCsList, index - 1) || !inBounds(smartCsList, index) || !inBounds(smartCsList, index + 1));
	//check that the index is out of bounds do nothing
	else {
	//otherwise
		if (smartCsList[index - 1]->high < smartCsList[index]->high && smartCsList[index + 1]->high < smartCsList[index]->high)
		{
			//if candlestick high is taller than left and right candlestick
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