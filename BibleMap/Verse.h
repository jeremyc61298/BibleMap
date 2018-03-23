/* Verse.h */
// Author: Jeremy Campbell
#include "VerseKey.h"
#include <iostream>
#pragma once

class Verse
{
public:
	Verse();
	Verse(VerseKey verseKey, string verseText);
	virtual ~Verse();

	void printVerse() const;

	string getVerseText() const;
	void setVerseText(string newVerse);

private:

	VerseKey verseKey;
	string verseText;
};

