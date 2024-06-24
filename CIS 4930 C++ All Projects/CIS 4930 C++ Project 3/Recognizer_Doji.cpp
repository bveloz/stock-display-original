#include "pch.h"
#include "Recognizer_Doji.h"
Recognizer_Doji::Recognizer_Doji() {
	this->patternName = "Doji";
	//set the name of the recognizer
	this->patternLength = 1;
	//set the length of the recognizer
};
bool Recognizer_Doji::recognize(List<SmartCandlestick^>^ smartCsList, int index) {
	bool value;
	//output value of tryget
	if (smartCsList[index]->patterns->TryGetValue(patternName, value)) return value;
	//check for the existence of pattern in the patterns to see if it has already been calculated
	else if (!inBounds(smartCsList, index));
	//check that the index is out of bounds do nothing
	else {
		//otherwise
		if (smartCsList[index]->range * 0.15 > smartCsList[index]->bodyRange)
		{
			//test to see if bodyrange is less than 5% of total range
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