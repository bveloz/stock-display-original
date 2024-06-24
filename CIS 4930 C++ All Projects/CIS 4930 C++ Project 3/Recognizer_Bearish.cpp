#include "pch.h"
#include "Recognizer_Bearish.h"
Recognizer_Bearish::Recognizer_Bearish() {
	this->patternName = "Bearish";
	//set the name of the recognizer
	this->patternLength = 1;
	//set the length of the recognizer
};
bool Recognizer_Bearish::recognize(List<SmartCandlestick^>^ smartCsList, int index) {
	bool value;
	//output value of tryget
	if (smartCsList[index]->patterns->TryGetValue(patternName, value)) return value;
	//check for the existence of pattern in the patterns to see if it has already been calculated
	else if (!inBounds(smartCsList, index));
	//check that the index is out of bounds do nothing
	else {
		//otherwise
		if (smartCsList[index]->open > smartCsList[index]->close)
		{
			//if candlestick open is greater than close
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