/* Verse.cpp */
// Author: Jeremy Campbell
#include "Verse.h"
using std::cout;
using std::endl;

Verse::Verse()
{

}

Verse::Verse(VerseKey verseKey, string verseText) :
	verseKey(verseKey), verseText(verseText)
{
}


Verse::~Verse()
{
}

void Verse::printVerse() const
{
	cout << verseKey.book << " " << verseKey.chapter << ":" << verseKey.verseNumber << " - ";
	cout << verseText << endl;
}

string Verse::getVerseText() const
{
	return verseText;
}

void Verse::setVerseText(string newVerse)
{
	verseText = newVerse;
}
