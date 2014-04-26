#pragma once
#include <vector>

using namespace std;

typedef struct gcjInt{
	int num;
	bool isVisited;
	gcjInt::gcjInt()
	{
		isVisited = false;
	}
} mygcjInt;

class eHash
{
private:
	vector<mygcjInt> myHash;
	
public:
	eHash(void);
	eHash(int start,int end);
	int addElem(int num2add);
	virtual int getKey(int inputNo);
	virtual int getKey(string inputStr);
	bool lookupNum(int num2find,int &keyOfNum);
	bool updateNum(int num2update,bool visitedFlag);
	bool getVisitedFlag(int numKey);
	int m_start;
	int m_end;
	~eHash(void);
};

