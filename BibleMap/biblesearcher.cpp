/* biblesearcher.cpp */
// Author: Jeremy Campbell

#include "Bible.h"
#include "VerseKey.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::exception;

// This function illustrates the Bible as a Map data stucture, allowing a user to 
// search the Bible for a specific verse in a "Book Chapter:Verse" format
void searchBible()
{
	Bible& bible = Bible::getInstance();

	VerseKey requestedVK;
	Verse requestedVerse;

	cout << "What verse would you like? ";
	cin >> requestedVK;

	while (toUpperStr(requestedVK.book) != "QUIT")
	{
		try
		{
			requestedVerse = bible[requestedVK];
			requestedVerse.printVerse();
		}
		catch (exception e)
		{
			cerr << "Verse not found." << endl << endl;
		}

		cout << "What verse would you like? ";
		cin >> requestedVK;
	}
}

void iterateBible()
{
	Bible& bible = Bible::getInstance();
	string genesis = "Genesis";
	string revelation = "Revelation";
	string rowBreak = "******************************************************************";
	VerseKey vkEnd(revelation, 22, 20);
	VerseKey vkBegin(genesis, 1, 3);
	Bible::Iterator iEnd = bible.getIterator(vkEnd);

	cout << rowBreak << endl;
	cout << "The end of the Bible to the beginning: " << endl;
	for (int j = 0; j < 5; j++)
	{
		cout << *iEnd;
		iEnd++;
	}

	Bible::Iterator iBegin = bible.getIterator(vkBegin);
	cout << rowBreak << endl;
	cout << "The beginning of the Bible to the end: " << endl;
	for (int j = 0; j < 5; j++)
	{
		cout << *iBegin;
		iBegin--;
	}
	cout << rowBreak << endl;
}

void main()
{
	Bible& bible = Bible::getInstance();
	if (bible.failedToOpen())
	{
		cout << "The Bible text file could not be opened. " << endl;
	}
	else
	{
		searchBible();
		iterateBible();
	}
}