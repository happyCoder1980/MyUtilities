#include "StdAfx.h"
#include "gcjHashMap.h"


gcjHashMap::gcjHashMap(void)
{
	m_MapType = BASE_CHAR;
}

gcjHashMap::gcjHashMap(int mapType)
{
	m_MapType = mapType;
	if (!setVector(m_MapType))
		printf("Unidentified vector type \n");
}


bool gcjHashMap::setVector(int myMapType)
{
	m_MapType = myMapType;
//	if (m_MapType == BASE_CHAR)
//		m_baseChars = new PlainBaseChar[TOTAL_ALPHA];
	//else 
	if (m_MapType == PAIR_CHAR)
		m_baseChars = new PairChar[TOTAL_ALPHA];
	else if (m_MapType == DEL_CHAR)
		m_baseChars = new DelChar[TOTAL_ALPHA];
	else
		return false;
	return true;
}

int gcjHashMap::getKey(char inputStr)
{
	int ret = (int) inputStr;
	return (ret - ASCII_START);
}

bool gcjHashMap::getElemAtIndex(int myIndex,BaseChar &myElem)
{
	if (myIndex >= TOTAL_ALPHA)
		return false;
	myElem = m_baseChars[myIndex];
	return true;
}

int gcjHashMap::addElem(BaseChar* char2add)
{
	int key2add = getKey(char2add->getCharElem());

	if (m_baseChars[key2add].getCharElem() == char2add->getCharElem())
		return -1;
	else
		m_baseChars[key2add] = *char2add;
	return key2add;
}

bool gcjHashMap::findElem(char elem2find,BaseChar &mybaseChar,int &index)
{
	int key = getKey(elem2find);
	index = key;
	if (m_baseChars[key].getCharElem() != NULL)
		mybaseChar = m_baseChars[key];
	else
		return false;
	return true;
}

gcjHashMap::~gcjHashMap(void)
{
}
