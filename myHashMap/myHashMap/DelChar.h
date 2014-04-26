#pragma once
#include "basechar.h"
class DelChar :
	public BaseChar
{
private:
	char m_delChar;
public:
	DelChar(void);
	void setDelChar(char delChar);
	char getDelChar();
	virtual ~DelChar(void);
};

