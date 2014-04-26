#pragma once
class BaseChar
{
private:
	char m_char;

public:
	BaseChar(void);
	virtual ~BaseChar(void);
	void setCharElem(char inChar);
	char getCharElem();
};

