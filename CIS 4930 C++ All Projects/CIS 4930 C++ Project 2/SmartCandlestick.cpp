#include "pch.h"
#include "SmartCandlestick.h"
System::Void SmartCandlestick::computeExtraProperties() {
	range = high - low;
	//calculate range
	topPrice = Math::Max(open, close);
	//set topPrice to the max between open and close
	bottomPrice = Math::Min(open, close);
	//set bottomPrice to the min between open and close
	bodyRange = topPrice - bottomPrice;
	//calculate bodyRange
	upperTail = high - topPrice;
	//calculate upperTail
	lowerTail = bottomPrice - low;
	//calculate lowerTail
}
System::Void SmartCandlestick::computePatterns() {
	setBullish();
	setBearish();
	setNeutral();
	setMarubozu();
	setHammer();
	setInvertedHammer();
	setDoji();
	setDragonflyDoji();
	setGravestoneDoji();
};
System::Void SmartCandlestick::setBullish() {
	if (open > close)
	//test if open greater than close
		setPattern("Bullish", false);
		//set pattern with key Bullish to false
	if (close > open)
	//test if close greater than open
		setPattern("Bullish", true);
		//set pattern with key Bullish to true	
};
System::Void SmartCandlestick::setBearish() {
	if (open > close)
	//test if open greater than close
		setPattern("Bearish", true);
		//set pattern with key Bearish to true
	if (close > open)
		//test if close greater than open
		setPattern("Bearish", false);
		//set pattern with key Bearish to false	
};
System::Void SmartCandlestick::setNeutral() {
	if (bodyRange < range *.1 && Math::Abs(upperTail - lowerTail) < range * .3)
	//test if bodyrange is less than 10% of total range and if upper tail and lower tail lengths 
		setPattern("Neutral", true);
		//set pattern with key Neutral to true
	else
		//test if open is not = close
		setPattern("Neutral", false);
		//set pattern with key Neutral to false
};
System::Void SmartCandlestick::setMarubozu() {
	if (bodyRange  > range * .8)
	// test to see if the bodyrange is at least 95% of the size of the total range
		setPattern("Marubozu", true);
		//set pattern with key isMarubozu to true
	else
	//if bodyrange is less than 95% of the size of total range
		setPattern("Marubozu", false);
		//set pattern with key isMarubozu to false
}
System::Void SmartCandlestick::setHammer() {
	if (bodyRange < range * 0.33 && lowerTail > range * 0.57 )
	//test to see if body range is less than 33% of the range, if lower tail is slightly larger than half of range,
	//and if the upper tail is less than 10% of the body range
		setPattern("Hammer", true);
		//set pattern with key Hammer to true
	else
	//otherwise
		setPattern("Hammer", false);
		//set pattern with key Hammer to false
}
System::Void SmartCandlestick::setInvertedHammer() {
	if (bodyRange < range * 0.33 && upperTail > range * 0.57)
	//test to see if body range is less than 33% of the range, if upper tail is slightly larger than half of range,
	//and if the lower tail is less than 10% of the body range
		setPattern("Inverted Hammer", true);
		//set pattern with key iInvertedHammer to true
	else
	//otherwise
		setPattern("Inverted Hammer", false);
		//set pattern with key Inverted Hammer to false
}
System::Void SmartCandlestick::setDoji() {
	if (range * 0.15 > bodyRange)
		//test to see if bodyrange is less than 5% of total range
		setPattern("Doji", true);
		//set pattern with key Doji to true
	else
	//otherwise
		setPattern("Doji", false);
		//set pattern with key Doji to false
}
System::Void SmartCandlestick::setDragonflyDoji() {
	if (range * 0.15 > bodyRange && lowerTail > .7 * range)
	//test to see if bodyrange is less than 5% of total range & if lower tail is about more than 70% of the range
		setPattern("Dragonfly Doji", true);
		//set pattern with key Dragonfly Doji to true
	else
	//otherwise
		setPattern("Dragonfly Doji", false);
		//set pattern with key Dragonfly Doji to false
}
System::Void SmartCandlestick::setGravestoneDoji() {
	if (range * 0.15 > bodyRange && upperTail > .7 * range)
		//test to see if bodyrange is less than 5% of total range & if upper tail is about more than 70% of the range
		setPattern("Gravestone Doji", true);
		//set pattern with key Gravestone Doji to true
	else
	//otherwise
		setPattern("Gravestone Doji", false);
		//set pattern with key Gravestone Doji to false
}
SmartCandlestick::SmartCandlestick(System::String^ csvLine) : Candlestick(csvLine) {
	computeExtraProperties();
	//computes the rest of the properties
	patterns = gcnew Dictionary<String^, bool>;
	//initialize patterns
	computePatterns();
	//compute patterns
};
SmartCandlestick::SmartCandlestick() : Candlestick() {
	computeExtraProperties();
	//sets all the above properties to 0 since all the base properties are 0 and
	//arithmetic operiations will result in 0
	patterns = gcnew Dictionary<String^, bool>;
	//initialize patterns
}
SmartCandlestick::SmartCandlestick(Candlestick^ cs) : Candlestick(cs) {
	computeExtraProperties();
	//will compute extra properties using the candlestick values
	patterns = gcnew Dictionary<String^, bool>;
	//initialize patterns
	computePatterns();
	//will compute the patterns using the candlestick values
}
System::Void SmartCandlestick::setPattern(String^ s, bool x) {
	if(s != nullptr)
		patterns[s] = x;
		//pattern with key s will be set to value x
}
