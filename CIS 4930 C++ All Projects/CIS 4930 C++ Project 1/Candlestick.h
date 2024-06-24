#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
using namespace System::IO;

ref class Candlestick
{
public:
	property DateTime date;
	//date variable
	property double open;
	//open variable
	property double high;
	//high variable
	property double low;
	//low variable
	property double close;
	//close variable
	property double adjClose;
	//adjusted close variable
	property unsigned long long int volume;
	//volume variable, needs to be unsigned long long int to support the length of numbers from volume fields
	Candlestick(String^);
	//constructor will take a line, parse it into individual components and set each variable accordingly
	//property keyword gives the variable a default getter and setter function 
	//which will allow it to be accessed like a public variable
	//unsigned long long int equivalent to ulong int in c#, 64 bit integer 
};