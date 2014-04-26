#include "StdAfx.h"
#include "PlainBaseChar.h"


PlainBaseChar::PlainBaseChar(void)
{
	m_marked4pairing = false;
	m_marked4del = false;
	pairMap.setVector(PAIR_CHAR);
	delMap.setVector(DEL_CHAR);
}

PlainBaseChar::PlainBaseChar(char c,bool pairFlag,bool delFlag)
{
	setCharElem(c);
	m_marked4pairing = pairFlag;
	m_marked4del = delFlag;
}

bool PlainBaseChar::getDelFlag()
{
	return m_marked4del;
}

bool PlainBaseChar::getPairFlag()
{
	return m_marked4pairing;
}

void PlainBaseChar::setDelFlag(bool del)
{
	m_marked4del = del;
}

void PlainBaseChar::setPairFlag(bool pair)
{
	m_marked4pairing = pair;
}

bool PlainBaseChar::addPair(char c1,char c2,char resChar)
{
	if (c1 == getCharElem())
	{
		PairChar* pair = new PairChar();
		pair->setCharElem(c2);
		pair->setPairedChar(resChar);
		pairMap.addElem(pair);
		delete pair;
		return true;
	}
	else
	{
		printf("Element not in the map \n");
		return false;
	}
}

bool PlainBaseChar::addDel(char c1,char c2)
{
	if (c1 == getCharElem())
	{
		DelChar* del = new DelChar();
		del->setDelChar(c2);
		delMap.addElem(del);
		delete del;
		return true;
	}
	else
	{
		printf("Element not in map \n");
		return false;
	}
}

PlainBaseChar::~PlainBaseChar(void)
{
	m_marked4pairing = false;
	m_marked4del = false;
}
