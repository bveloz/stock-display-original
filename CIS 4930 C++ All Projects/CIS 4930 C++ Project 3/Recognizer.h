#pragma once
#include "SmartCandlestick.h"
ref class Recognizer abstract
{
	protected: 
		String^ patternName;
		//pattern name variable
		int patternLength;
		//number of candlesticks required to recognize pattern
	public:
		
		String^ getPatternName();
		/// <summary>
		/// When the getPatternName method is called, it returns the name of the candlestick pattern
		/// </summary>
		int getPatternLength();
		/// <summary>
		/// When the getPatternLength method is called, it number of the candlesticks required to recognize a pattern
		/// </summary>
		virtual bool recognize(List<SmartCandlestick^>^, int) = 0;
		/// <summary>
		/// When the Recognize method is called, will return true if a pattern is found in the list of SmartCandlesticks that is passed to it
		/// and it will also set the SmartCandlestick dictionary true for the pattern if it is recognized as a pattern, defined individually in each
		/// class inheriting from Recognizer
		/// </summary>
		void recognizeAll(List<SmartCandlestick^>^);
		/// <summary>
		/// When the Recognize all method, the recognize function will be called on all the candlesticks in the candlesticklist 
		/// </summary>
		bool inBounds(List<SmartCandlestick^>^, int);
		/// <summary>
		/// When the inBounds all method, the SmartCandlestickList will be tested to see if the index passed is in bounds 
		/// </summary>

};

