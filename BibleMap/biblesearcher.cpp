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

void main()
{
	Bible& bible = Bible::getInstance();
	if (bible.failedToOpen())
	{
		cout << "The Bible text file could not be opened. " << endl;
	}
	else
	{
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
}