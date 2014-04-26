#pragma once
#include "gcjHashMap.h"
#include "BaseChar.h"
#include "PlainBaseChar.h"
#include "PairChar.h"

class gcjInput
{
private:
	gcjHashMap baseMap;
	BaseChar* elem;
	
public:
	gcjInput(void);
	bool initBaseElems(char inputElem);
	bool addPairs(char c1,char c2,char &resChar);
	bool addDels(char c1,char c2);
	~gcjInput(void);
};

