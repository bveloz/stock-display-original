#include "pch.h"
#include "CandleStick.h"

using namespace System;
using namespace System::Globalization;

Candlestick::Candlestick(System::String^ csvLine) {
	// because the Candlestick class is defined outside of the stockDisplay_Form it needs an arguement to create the candlestick
	array<wchar_t>^ separators = { L'\,', L'"' };
	//list of characters indicating how to split the line
	array<String^>^ tokens = csvLine->Split(separators, StringSplitOptions::RemoveEmptyEntries);
	//create an array of strings from the original string csvLine and split by the separators List
	// 
	//assumes that if the header of the columns are correct, the data within each columns will match the format of its column
	if (tokens->Length == 7)
	{
		date = DateTime::ParseExact(tokens[0], "yyyy-MM-dd", CultureInfo::InvariantCulture);
		//parse the date in the format given as an arguement regardless of the cultural display of time set date to the value
		open = Double::Parse(tokens[1]);
		//parse the open as a double set open to the value
		high = Double::Parse(tokens[2]);
		//parse the high as a double set high to the value
		low = Double::Parse(tokens[3]);
		//parse the low as a double set low to the value
		close = Double::Parse(tokens[4]);
		//parse the close as a double set close to the value
		adjClose = Double::Parse(tokens[5]);
		//parse the adjusted close as a double set adjClose to the value
		volume = UInt64::Parse(tokens[6]);
		//parse the volume as an unsigned 64 bit integer set volume to the value
	}

};
Candlestick::Candlestick() {
	date = DateTime::Now;
	//set the date to now
	open = 0;
	//set open to 0
	high = 0;
	//set high to 0
	low = 0;
	//set low to 0
	close = 0;
	//set close to 0
	adjClose = 0;
	//set adjusted close to 0
	volume = 0;
	//set volume to 0
};
Candlestick::Candlestick(Candlestick^ copy)
{
	date = copy->date;
	//set date to the date of copy
	open = copy->open;
	//set open to the open of copy
	high = copy->high;
	//set high to the high of copy
	low = copy->low;
	//set low to the low of copy
	close = copy->close;
	//set close to the close of copy
	adjClose = copy->adjClose;
	//set adjusted close to the adjusted close  of copy
	volume = copy->volume;
	//set volume to the volume of copy
}
