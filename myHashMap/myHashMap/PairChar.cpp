#include "StdAfx.h"
#include "PairChar.h"


PairChar::PairChar(void)
{
}

char PairChar::getPairedChar()
{
	return m_pairedChar;
}

void PairChar::setPairedChar(char char2pair)
{
	m_pairedChar = char2pair;
}

PairChar::~PairChar(void)
{
}
