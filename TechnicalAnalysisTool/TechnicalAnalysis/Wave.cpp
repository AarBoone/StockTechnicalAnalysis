#include "pch.h"
#include "Wave.h"


Wave::Wave(int start, int end) {
	this->Start = start;
	this->End = end;
}

bool Wave::isBelow(Candlestick^ a, Candlestick^ b) {
	if (a->Low <= b->Low) { return false; }
	else { return true; }
}

bool Wave::isBelow(PeakValley^ a, PeakValley^ b) {
	return isBelow(a->Cs, b->Cs);
}

bool Wave::isAbove(Candlestick^ a, Candlestick^ b) {
	if (a->High >= b->High) { return false; }
	else { return true; }
}

bool Wave::isAbove(PeakValley^ a, PeakValley^ b) {
	return isAbove(a->Cs, b->Cs);
}


