#pragma once
#include "Candlestick.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

ref class StockReader
{
public:
	static List<Candlestick^>^ ReadFromCSV(String^ filePath);
};

