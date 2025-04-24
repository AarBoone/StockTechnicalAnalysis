#pragma once
#include "PeakValley.h"

// Added for Project 2

ref class Wave // Wave class (basically just stores indexes of start and end of wave)
{
public: 
	int Start;
	int End;

public:
	Wave() {};
	Wave(int start, int end);

public: static bool isBelow(Candlestick^ a, Candlestick^ b); // checks if candlestick b is lower than a 
		static bool isBelow(PeakValley^ a, PeakValley^ b); // checks if candlestick stored in PeakValleys
		static bool isAbove(Candlestick^ a, Candlestick^ b); // checks is candlestick b is above a
		static bool isAbove(PeakValley^ a, PeakValley^ b); // Same function but takes PeakValley objects
};




