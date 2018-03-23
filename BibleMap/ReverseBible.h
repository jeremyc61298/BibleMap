#pragma once
#include "Bible.h"

class ReverseBible : public Bible::IVisitor
{
public:
	ReverseBible();
	virtual ~ReverseBible();

	virtual void visit(VerseKey& vk, Verse& v);

private:

};

