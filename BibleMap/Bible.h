/* Bible.h */
// Author: Jeremy Campbell
#include "Map.hpp"
#include "VerseKey.h"
#include "Verse.h"
#pragma once

using std::ostream;

class Bible : public util::Map<VerseKey, Verse>
{
public:
	virtual ~Bible();
	static Bible& getInstance();
	bool failedToOpen();

private:
	Bible();
	Bible(Bible&) = delete;
	void operator=(Bible& junk) = delete;
	static Bible* bible;
	bool failed;
};

ostream& operator<<(ostream& out, const Verse verseI);

