/* biblesearcher.cpp */
// Author: Jeremy Campbell

#include "Bible.h"
#include "VerseKey.h"
#include "BibleWordCounter.h"
#include "ReverseBible.h"
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

	cout << "What verse would you like? (Quit to stop) ";
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

		cout << "What verse would you like? (Quit to stop) ";
		cin >> requestedVK;
		cout << endl;
	}
	cout << endl;
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

void countWord()
{
	string wordToCount = "";

	cout << "Please enter a word to count (QUIT to stop): ";
	cin >> wordToCount;

	while (toUpperStr(wordToCount) != "QUIT")
	{
		BibleWordCounter counter(wordToCount);
		Bible& bible = Bible::getInstance();
		bible.visit(counter);

		cout << counter.getWordToCount() << " was found in the Bible " << counter.getCount() << " time(s)" << endl << endl;

		cout << "Please enter a word to count (Quit to stop): ";
		cin >> wordToCount;
	}
}

void reverseBible()
{
	ReverseBible rb;
	Bible& bible = Bible::getInstance();
	bible.visit(rb);

	cout << "The Bible text has been reversed!" << endl << endl;
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
		int choice;

		do
		{
			cout << "What would you like to do? (Enter a #)" << endl
				<< "1) Search for a Verse" << endl
				<< "2) Iterate the ends of the Bible" << endl
				<< "3) Count the occurance of a word" << endl
				<< "4) Reverse the verses" << endl
				<< "5) Quit" << endl;

			cin >> choice;
			cin.ignore();

			switch (choice)
			{
			case 1:
				searchBible();
				break;
			case 2:
				iterateBible();
				break;
			case 3:
				countWord();
				break;
			case 4:
				reverseBible();
				break;
			case 5:
				break;
			default:
				cout << "Invalid input, please retry." << endl << endl;
			}
		} while (choice != 5);
	}
}