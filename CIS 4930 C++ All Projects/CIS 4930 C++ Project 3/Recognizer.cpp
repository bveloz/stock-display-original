#include "pch.h"
#include "Recognizer.h"
String^ Recognizer::getPatternName() { return patternName; }
// return patternName variabale
int Recognizer::getPatternLength() { return patternLength; }
// return patternLength variable
System::Void Recognizer::recognizeAll(List<SmartCandlestick^>^ smartCsList) {
	for (int i = 0; i < smartCsList->Count; i++)
		recognize(smartCsList, i);
		//for each candlestick, call recognize, bounds checking will be done in each implementation
}
bool Recognizer::inBounds(List<SmartCandlestick^>^ smartCsList, int index) {
	return (index >= 0) && (index < smartCsList->Count);
	//return true if index is not our of bounds, false otherwise
}