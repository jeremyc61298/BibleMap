#include "ReverseBible.h"



ReverseBible::ReverseBible()
{
}


ReverseBible::~ReverseBible()
{
}

void ReverseBible::visit(VerseKey& vk, Verse& v)
{
	string oV = v.getVerseText();
	string rV = "";

	for (int i = 0; i < oV.size(); i++)
	{
		rV.push_back(oV.at(oV.size() - i - 1));
	}

	v.setVerseText(rV);
}
