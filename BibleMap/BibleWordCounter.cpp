#include "BibleWordCounter.h"
#include <sstream>

using std::stringstream;

BibleWordCounter::BibleWordCounter(string word) : wordToCount(word), count(0)
{}


BibleWordCounter::~BibleWordCounter()
{}

void BibleWordCounter::visit(VerseKey& key, Verse& value)
{
	if (key.book == wordToCount)
	{
		count++;
	}

	stringstream ss(value.getVerseText());
	string wordFromVerse = "";

	while (!ss.eof())
	{
		ss >> wordFromVerse;

		if (wordFromVerse == wordToCount)
		{
			count++;
		}
	}
}

string BibleWordCounter::getWordToCount() const
{
	return wordToCount;
}

unsigned int BibleWordCounter::getCount() const
{
	return count;
}
