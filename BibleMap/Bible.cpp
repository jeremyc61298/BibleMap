/* Bible.cpp */
// Author: Jeremy Campbell

#include "Bible.h"
#include <fstream>
#include <exception>
#include <iostream>
#include <sstream>
#include "Verse.h"
#include "VerseKey.h"

using std::ifstream;
using std::exception;
using std::cout;
using std::endl;
using std::stringstream;

Bible* Bible::bible = NULL;

Bible::Bible() : failed(false)
{
	// Read in from the bible text file into key value pairs
	ifstream bibleText("bible.txt");
	if (!bibleText.is_open())
	{
		failed = true;
	}
	else
	{
		string line = "";
		string junk = "";
		VerseKey extractedVK;
		string verse = "";
		while (!bibleText.eof() && !bibleText.fail()) 
		{
			stringstream ss;
			getline(bibleText, line);
			ss << line;
			if (line.substr(0, 4) == "Book")
			{
				extractedVK.book = line.substr(8);
			}
			else
			{
				ss >> extractedVK.chapter >> extractedVK.verseNumber;
				getline(ss, verse);
				set(extractedVK, Verse(extractedVK, verse));
			} 
		}
	}
	bibleText.close();
}


Bible::~Bible()
{
}

Bible& Bible::getInstance()
{
	if (bible == NULL)
	{
		bible = new Bible();
	}
	return *bible;
}

bool Bible::failedToOpen()
{
	return failed;
}

ostream& operator<<(ostream& out, const Verse verseI) 
{
	verseI.printVerse();
	return out;
}