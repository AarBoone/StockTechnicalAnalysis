#include "pch.h"
#include "Candlestick.h"

//Constructor
Candlestick::Candlestick(DateTime date, double open, double high, double low, double close, unsigned long volume) 
{
	this->Date = date;
	this->Open = open;
	this->High = high;
	this->Low = low;
	this->Close = close;
	this->Volume = volume;
}

Candlestick::Candlestick(String^ candlestickString) 
{
	array<wchar_t>^ separators = gcnew array<wchar_t>{',', '\"'};

	array<String^>^ tokens = candlestickString->Split(separators, StringSplitOptions::RemoveEmptyEntries);

	if (tokens->Length == 6) {
		this->Date = DateTime::Parse(tokens[0]);
		this->Open = Convert::ToDouble(tokens[1]);
		this->High = Convert::ToDouble(tokens[2]);
		this->Low = Convert::ToDouble(tokens[3]);
		this->Close = Convert::ToDouble(tokens[4]);
		this->Volume = Convert::ToInt64(tokens[5]);
	}
	else 
	{
		;
	}
}