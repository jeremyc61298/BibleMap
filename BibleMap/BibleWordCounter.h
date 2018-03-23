#pragma once
#include "Bible.h"

class BibleWordCounter : public util::Map<VerseKey, Verse>::IVisitor
{
public:
	BibleWordCounter(string word);
	virtual ~BibleWordCounter();

	virtual void visit(VerseKey& key, Verse& value);

	string getWordToCount() const;
	unsigned int getCount() const;

private:
	string wordToCount;
	unsigned int count;
};

