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
	string book;
	int chapter;
	int verseNumber;
	in >> book >> chapter >> verseNumber;
	VerseKey vK(book, chapter, verseNumber);
	rValue = vK;
	return in;
}
