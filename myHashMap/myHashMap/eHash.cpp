#include "StdAfx.h"
#include "eHash.h"

const int MAX_ELEMS_IN_KEY = 5;

eHash::eHash(void)
{
	myHash.reserve(10);
}

eHash::eHash(int start,int end)
{
	m_start = start;
	m_end = end;
	myHash.reserve(end-start);

	mygcjInt empInt;
	empInt.num = 0;

	for (int i=0;i<=(m_end-m_start);i++)
		myHash.push_back(empInt);
}

int eHash::getKey(int inputNo)
{
	return (inputNo - m_start);
}

bool eHash::lookupNum(int num2find,int &keyOfNum)
{
	int key = getKey(num2find);

	if (((myHash.size()) - 1) < key)
		return false;
	else
	{
		keyOfNum = key;
		return true;
	}
}

bool eHash::getVisitedFlag(int numKey)
{
	return (myHash[numKey].isVisited);
}

bool eHash::updateNum(int num2update,bool visitedFlag)
{
	int key2update;
	if (lookupNum(num2update,key2update))
		myHash[key2update].isVisited = visitedFlag;
	else
		return false;
	return true;
}

int eHash::getKey(string inputStr)
{
	return 1;
}

int eHash::addElem(int num2add)
{
	int key2add = getKey(num2add);

	mygcjInt num;
	num.num = num2add;

	myHash[key2add] = num;
	
	return key2add;
}

eHash::~eHash(void)
{
}
