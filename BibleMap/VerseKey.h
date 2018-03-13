#include<string>
#include<iostream>
#pragma once

using std::string;
using std::istream;

class VerseKey
{
public:
	VerseKey();
	VerseKey(string book, int chapter, int verseNumber);
	~VerseKey();

	bool operator==(const VerseKey& rValue) const;

private:
	string book;
	int chapter;
	int verseNumber;
};

istream& operator>>(istream& in, VerseKey& rValue);