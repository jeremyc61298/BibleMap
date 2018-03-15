#include "VerseKey.h"
#include <iostream>
#pragma once

class Verse
{
public:
	Verse();
	Verse(VerseKey verseKey, string verseText);
	~Verse();

	void printVerse();

private:

	VerseKey verseKey;
	string verseText;
};

