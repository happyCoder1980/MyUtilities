// MyStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "eStack.h"

eStack* mySt;

bool processStrInput(string inStr)
{
    //mySt = new eStack();
	mySt = eStack::initStack();
	if (mySt == NULL)
		return false;
	
	
	char* str;
	char* indWord;

	str = strtok((char*) inStr.c_str()," ");
	mySt->push(str);

	while (str != NULL)
	{
		str = strtok(NULL," ");
		indWord = str;
		if (indWord != NULL)
			mySt->push(indWord);
	}
	return true;
}

bool printReverse()
{
	while (mySt->getStackCt() != 0)
	{
		printf("%s",(mySt->pop()).c_str());
		printf(" ");
	}
	return true;
}


int getStrLen(string s)
{
	int sLen = 0;
	const char* sC = s.c_str();
	while (sC != NULL)
	{
		sLen++;
	}
	return sLen;
}


bool reverseStr(string &inStr)
{
	int leng = strlen(inStr.c_str());
	char* inSc = (char*) inStr.c_str();
	char temp;

	while (inSc != '\0')
	{
		temp = *(inSc+leng-1);
		*(inSc+leng-1) = *inSc;
		*inSc = temp;
		inSc++;
	}

	inStr = inSc;
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//processStrInput("this");
	processStrInput("This is a test string");
	mySt->deleteNodes(1,3);
	mySt->keepAndDeleteNodes(1,2);
	string s2 = "Test";
	reverseStr(s2);
	mySt->reverseStack();
	mySt->deleteElem("test");
	mySt->cleanUpStack();
	//printReverse();
	return 0;
}

