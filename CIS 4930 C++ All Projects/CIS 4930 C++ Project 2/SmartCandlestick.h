#pragma once
#include "Candlestick.h"
ref class SmartCandlestick : Candlestick
{
public:
	property double range;
	//range variable
	property double bodyRange;
	//bodyRange variable
	property double topPrice;
	//topPrice variable
	property double bottomPrice;
	//bottomPrice variable
	property double upperTail;
	//upperTail variable
	property double lowerTail;
	//lowerTail vaariable
	Dictionary<String^, bool>^ patterns;
	//dictionary storing the values of candlestick patterns such as isBullish, isBearish
	void computeExtraProperties();
	// will compute the variables above using base class input variables
	void computePatterns();
	// will compute what types of patterns a candlestick is
	void setBullish();
	//will compute if a candlestick is Bullish and store it in patterns
	void setBearish();
	//will compute if a candlestick is Bearish and store it in patterns
	void setNeutral();
	//will compute if a candlestick is neutral and store it in patterns
	void setMarubozu();
	//will compute if a candlestick is Marubozu and store it in patterns
	void setHammer();
	//will compute if a candlestick is Hammer and store it in patterns
	void setInvertedHammer();
	//will compute if a candlestick is inverted Hammer and store it in patterns
	void setDoji();
	//will compute if a candlestick is Doji and store it in patterns
	void setDragonflyDoji();
	//will compute if a candlestick is Dragonfly Doji and store it in patterns
	void setGravestoneDoji();
	//will compute if a candlestick is Gravestone Doji and store it in patterns
	void setPattern(String^, bool);
	//will directly modify the patterns dictionary and add a value to the dictionary

	SmartCandlestick();
	//default constructor, all variables initialized to 0
	SmartCandlestick(System::String^);
	//constructor will take a line invoke the base constructor and then it will calculate the variables above
	//using the already instantiated base variables
	SmartCandlestick(Candlestick^);
	//constructor takes a candlestick as an argurment to transform into smartcandlesticks
};

