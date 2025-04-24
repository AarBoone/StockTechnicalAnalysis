#pragma once
#include "Candlestick.h"


public ref class PeakValley // The peak valley class contains
{
public:
	property Candlestick^ Cs;	// A reference to a candlestick
	int Index; // The index of that candlestick in filteredCandlestick
	int Margin;
	bool IsPeak;
	// ------- P3 -------
	double X;
	double Y;

public:
	PeakValley() {};
	PeakValley(Candlestick^ cs, int index, bool isPeak); // Constructor using a candlestick and index
	void SetX(double x);
	void SetY(double y);
};

