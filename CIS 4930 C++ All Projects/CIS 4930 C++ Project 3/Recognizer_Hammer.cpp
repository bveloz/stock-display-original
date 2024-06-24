#include "pch.h"
#include "Recognizer_Hammer.h"
Recognizer_Hammer::Recognizer_Hammer() {
	this->patternName = "Hammer";
	//set the name of the recognizer
	this->patternLength = 1;
	//set the length of the recognizer
};
bool Recognizer_Hammer::recognize(List<SmartCandlestick^>^ smartCsList, int index) {
	bool value;
	//output value of tryget
	if (smartCsList[index]->patterns->TryGetValue(patternName, value)) return value;
	//check for the existence of pattern in the patterns to see if it has already been calculated
	else if (!inBounds(smartCsList, index));
	//check that the index is out of bounds do nothing
	else {
		//otherwise
		if (smartCsList[index]->bodyRange < smartCsList[index]->range * 0.33 && smartCsList[index]->lowerTail > smartCsList[index]->range * 0.57)
		{
			//test to see if body range is less than 33% of the range, if lower tail is slightly larger than half of range,
			//and if the upper tail is less than 10% of the body range
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