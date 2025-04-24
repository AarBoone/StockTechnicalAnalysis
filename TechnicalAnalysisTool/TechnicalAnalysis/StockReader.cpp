#include "pch.h"
#include "StockReader.h"

List<Candlestick^>^ StockReader::ReadFromCSV(String^ filePath) 
{
	List<Candlestick^>^ candlesticks = gcnew List<Candlestick^>();


	//Create a new stream reader
	StreamReader^ reader = gcnew StreamReader(filePath);

	//Skip the first line because its just the csv hearer
	String^ line = reader->ReadLine();

	// While the read line isnt the end of strea
	while (!reader->EndOfStream) 
	{
		//Read the next line
		line = reader->ReadLine();
		// Make sure the string isnt whitespace
		if (!String::IsNullOrWhiteSpace(line)) 
		{
			//Create a new candlestick based on the line from the csv and add it to the list of candlesticks
			Candlestick^ newCandlestick = gcnew Candlestick(line);
			candlesticks->Add(newCandlestick);
		}
	}

	// Close the reader
	reader->Close();
	
	// Check if candlesticks are in the right order
	if (candlesticks[0]->Date > candlesticks[1]->Date) {
		// Reverse if they arent
		candlesticks->Reverse();
	}

	// return the list of candlesticks
	return candlesticks;
}



