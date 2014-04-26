#include "StdAfx.h"
#include "BaseChar.h"


BaseChar::BaseChar(void)
{
	m_char = '0';
}

char BaseChar::getCharElem()
{
	return m_char;
}

void BaseChar::setCharElem(char inChar)
{
	m_char = inChar;
}


BaseChar::~BaseChar(void)
{
}
