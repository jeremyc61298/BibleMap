#include<string>
#include<iostream>
#pragma once

using std::string;
using std::istream;

struct VerseKey
{
	VerseKey();
	VerseKey(string book, int chapter, int verseNumber);
	~VerseKey();

	bool operator==(const VerseKey& rValue) const;

	string book;
	int chapter;
	int verseNumber;
};

istream& operator>>(istream& in, VerseKey& rValue);