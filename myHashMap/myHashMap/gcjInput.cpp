#include "StdAfx.h"
#include "gcjInput.h"


gcjInput::gcjInput(void)
{
	//initBaseElems();
}

bool gcjInput::initBaseElems(char inputElem)
{
	elem = new PlainBaseChar(inputElem,false,false);
	int index;
	if (!baseMap.findElem(inputElem,*elem,index))
		baseMap.addElem(elem);
	//elem->setCharElem(inputElem);
	return true;
}


bool gcjInput::addPairs(char c1,char c2,char &resChar)
{
	int index = 0;
	PlainBaseChar* plainChar = new PlainBaseChar();
	if (!baseMap.findElem(c1,*plainChar,index))
	{
		printf("Non-base elem in input \n");
		return false;
	}
		
	//(PlainBaseChar*) elem;
	plainChar->addPair(c1,c2,resChar);
	return true;
}

bool gcjInput::addDels(char c1,char c2)
{
	int index = 0;
	return 0;
}


gcjInput::~gcjInput(void)
{
}
