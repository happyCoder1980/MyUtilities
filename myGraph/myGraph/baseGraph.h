#pragma once
#include "graphContainer.h"
#include "graphNode.h"
//#include "eStack.h"
#include <queue>

using namespace std;

class baseGraph
{
private:
	graphContainer m_gMatrix;
	int getKey(graphNode node);
	//eStack m_grStack;
	queue<int> m_grQ;
	bool visitedNodes[MAX_NODES];
	int currLnAtNode[MAX_NODES];
		
public:
	baseGraph(void);
	bool addElem(graphNode n1,graphNode n2,int weight=1);
	bool myBFS(graphNode start,graphNode dst,int &bestPath);
	int addChildren2Q(graphNode node);
	int addChildren2Q(int nodeVal,int tgtNodeVal,bool &found);
	bool checkifVisited(int index);
	virtual ~baseGraph(void);
};

