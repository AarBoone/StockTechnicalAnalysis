#include "pch.h"
#include "PeakValley.h"


PeakValley::PeakValley(Candlestick^ cs, int index, bool isPeak) // Constructor for PeakValley
{
	this->Cs = cs;
	this->Index = index;
	this->Margin = 0;
	this->IsPeak = isPeak;
	this->X = 0;
	this->Y = 0;
}

void PeakValley::SetX(double x) { this->X = x; }
void PeakValley::SetY(double y) { this->Y = y; }


