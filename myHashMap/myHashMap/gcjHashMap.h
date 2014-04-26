#pragma once
#include <vector>
#include "ehash.h"
#include "BaseChar.h"
//#include "PlainBaseChar.h"
#include "PairChar.h"
#include "DelChar.h"

using namespace std;

const int BASE_CHAR = 0;
const int PAIR_CHAR = 1;
const int DEL_CHAR = 2;
const int ASCII_START = 65;
const int TOTAL_ALPHA  = 26;

class gcjHashMap :
	public eHash
{
private:
	int m_MapType;
	
	//vector<BaseChar> baseChars;
public:
	gcjHashMap(void);
	gcjHashMap(int mapType);
	bool setVector(int myMapType);
	int getKey(char inputStr);
	int addElem(BaseChar* char2add);
	bool findElem(char elem2find,BaseChar &mybaseChar,int &index);
	bool getElemAtIndex(int myIndex,BaseChar &myElem);
	
	//void setMapType(int myMapType);
	~gcjHashMap(void);
	BaseChar* m_baseChars;
};

