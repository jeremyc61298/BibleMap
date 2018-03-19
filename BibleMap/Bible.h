/* Bible.h */
// Author: Jeremy Campbell
#include "Map.hpp"
#include "VerseKey.h"
#include "Verse.h"
#pragma once

class Bible : public util::Map<VerseKey, Verse>
{
public:
	Bible();
	virtual ~Bible();
};

