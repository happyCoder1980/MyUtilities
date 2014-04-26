#pragma once
#include "basechar.h"
#include "gcjHashMap.h"

class PlainBaseChar :
	public BaseChar
{
private:
	bool m_marked4pairing;
	bool m_marked4del;
	
public:
	gcjHashMap pairMap;
	gcjHashMap delMap;
	PlainBaseChar(void);
	PlainBaseChar(char c,bool pairFlag,bool delFlag);
	virtual ~PlainBaseChar(void);
	void setPairFlag(bool pair);
	bool getPairFlag();
	void setDelFlag(bool del);
	bool getDelFlag();
	bool addPair(char c1,char c2,char resChar);
	bool addDel(char c1,char c2);
};

