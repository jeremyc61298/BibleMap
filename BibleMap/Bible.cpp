#include "Bible.h"
#include <fstream>
#include <iostream>
#include <sstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::stringstream;

Bible::Bible()
{
	// Read in from the bible text file into key value pairs
	ifstream bibleText("bibleTest.txt");
	if (!bibleText.is_open())
	{
		cout << "The bible text file could not be opened. " << endl;
	}
	else
	{
		while (!bibleText.eof()) 
		{
			stringstream ss;
			string line;
			getline(bibleText, line);
			ss << line;
			// Next, read the stringstream into the actual map. 
		}
	}
}


Bible::~Bible()
{
}
