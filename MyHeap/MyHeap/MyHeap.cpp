// MyHeap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "eHeap.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int topVal;
	eHeap* myH = new eHeap();
	myH->insert(10);
	myH->insert(22);
	myH->insert(28);
	myH->insert(18);
	topVal = myH->getTopValue();
	
	myH->insert(8);
	topVal = myH->getTopValue();

	myH->deleteElem(22);

	int index = 0;
	if (myH->lookupValue(28,index))
		printf("Value found \n");

	if (!(myH->lookupValue(44,index)))
		printf("Val not found \n");



	/*
	//delete an elem...
	myH->deleteElemWithData(28);
	myH->deleteElemWithData(7);
	topVal = myH->getTopValue();
	myH->deleteElemWithData(8);
	topVal = myH->getTopValue();*/

	delete myH;
	return 0;
}

