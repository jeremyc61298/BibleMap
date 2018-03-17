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

void Verse::printVerse()
{
	cout << verseKey.book << " " << verseKey.chapter << ":" << verseKey.verseNumber << " - ";
	cout << verseText << endl << endl;
}
