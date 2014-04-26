// myGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "baseGraph.h"
#include "graphNode.h"

int _tmain(int argc, _TCHAR* argv[])
{
	baseGraph gr;

	graphNode myNode[MAX_NODES];
	
	for (int i=0;i<=MAX_NODES-1;i++)
		myNode[i].setVal(i);

	gr.addElem(myNode[0],myNode[1]);
	gr.addElem(myNode[0],myNode[2]);

	gr.addElem(myNode[1],myNode[0]);
	gr.addElem(myNode[1],myNode[2]);
	gr.addElem(myNode[2],myNode[3]);
	gr.addElem(myNode[2],myNode[0]);
	gr.addElem(myNode[2],myNode[1]);
	gr.addElem(myNode[3],myNode[2]);
	
	int shortest;
	if (gr.myBFS(myNode[0],myNode[3],shortest))
		printf("Found the element \n");
	else
		printf("Couldnt find element \n");

	return 0;
}

