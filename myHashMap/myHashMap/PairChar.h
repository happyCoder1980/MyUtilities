#pragma once
#include "basechar.h"
class PairChar :
	public BaseChar
{
private:
	char m_pairedChar;
public:
	PairChar(void);
	char getPairedChar();
	void setPairedChar(char char2pair);
	virtual ~PairChar(void);
};

