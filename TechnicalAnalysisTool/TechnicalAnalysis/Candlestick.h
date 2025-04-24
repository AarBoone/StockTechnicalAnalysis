// Aaron Boone U64069975

#pragma once
using namespace System;
#include "string"

public ref class Candlestick
{
public:
	//Properties
	property DateTime Date;
	property double Open;
	property double High;
	property double Low;
	property double Close;
	property unsigned long Volume;

	//default constructor
	Candlestick() {}

	//Specialized Constructor
	Candlestick(DateTime date, double open, double high, double low, double close, unsigned long volume);

	//Constructor takes string of for "date,open,high,low,close,volume"
	Candlestick(String^ candlestickString);
};