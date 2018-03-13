#include "VerseKey.h"
#pragma once

class Verse
{
public:
	Verse();
	Verse(VerseKey verseKey, string verseText);
	~Verse();

private:
	VerseKey verseKey;
	string verseText;
};

