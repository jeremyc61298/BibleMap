#include "Bible.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Verse.h"
#include "VerseKey.h"

using std::ifstream;
using std::cout;
using std::endl;
using std::stringstream;

Bible::Bible()
{
	// Read in from the bible text file into key value pairs
	ifstream bibleText("bible.txt");
	if (!bibleText.is_open())
	{
		cout << "The bible text file could not be opened. " << endl;
	}
	else
	{
		string line = "";
		string junk = "";
		// Change to verseKey struct
		VerseKey extractedVK;
		string verse = "";
		while (!bibleText.eof() && !bibleText.fail()) 
		{
			stringstream ss;
			getline(bibleText, line);
			ss << line;
			if (line.substr(0, 4) == "Book")
			{
				ss >> junk >> junk >> extractedVK.book;
			}
			else
			{
				ss >> extractedVK.chapter >> extractedVK.verseNumber;
				getline(ss, verse);
				set(extractedVK, Verse(extractedVK, verse));
			} 

		}
	}
}


Bible::~Bible()
{
}
