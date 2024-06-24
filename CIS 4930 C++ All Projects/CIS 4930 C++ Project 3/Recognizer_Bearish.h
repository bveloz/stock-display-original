#pragma once
#include "Recognizer.h"
ref class Recognizer_Bearish : public Recognizer
{
	public:
		Recognizer_Bearish();
		/// <summary>
		/// When the Recognizer_Bearish contructor is called, it will initilize the contructor setting the name and pattern length
		/// </summary>
		bool recognize(List<SmartCandlestick^>^ smartCsList, int index) override;
		/// <summary>
		/// When the recognize function is called, it will override the abstract class function and will determin if a candlestick is bearish
		/// </summary>	
};

