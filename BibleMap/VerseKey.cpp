#include "VerseKey.h"

VerseKey::VerseKey()
{
	// Include default initialization?
}

VerseKey::VerseKey(string book, int chapter, int verseNumber) :
	book(book), chapter(chapter), verseNumber(verseNumber)
{}

VerseKey::~VerseKey()
{
}

bool VerseKey::operator==(const VerseKey & rValue) const
{
	bool result = false;
	if (rValue.book == book && rValue.chapter == chapter && rValue.verseNumber == verseNumber)
	{
		result = true;
	}
	return result;
}

istream & operator>>(istream & in, VerseKey & rValue)
{
	string book, temp;
	int chapter = -1;
	int verseNumber = -1;
	in >> book;
	if (book != "Quit")
	{
		getline(in, temp, ':');
		chapter = stoi(temp);
		in >> verseNumber;
	}
	rValue = VerseKey(book, chapter, verseNumber);
	return in;
}
