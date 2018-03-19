/* verseKey.cpp */
// Author: Jeremy Campbell
#include "VerseKey.h"

VerseKey::VerseKey()
{

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
	string temp;
	string temp2;
	int chapter = -1;
	int verseNumber = -1;
	in >> book;
	if (toUpperStr(book) != "QUIT")
	{
		if (book == "1" || book == "2" || book == "3")
		{
			in >> temp;
			book.append(" " + temp);
		}
		if (book == "Song")
		{
			in >> temp >> temp2;
			book.append(" " + temp + " " + temp2);
		}
		getline(in, temp, ':');
		chapter = stoi(temp);
		in >> verseNumber;
	}
	rValue = VerseKey(book, chapter, verseNumber);
	return in;
}

string toUpperStr(string s)
{
	for (auto i = s.begin(); i != s.end(); i++)
	{
		*i = toupper(*i);
	}
	return s;
}
