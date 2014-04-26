#include "StdAfx.h"
#include "baseGraph.h"


baseGraph::baseGraph(void)
{
	for (int i=0;i<=MAX_NODES-1;i++)
	{
		visitedNodes[i] = false;
		currLnAtNode[i] = 0;
		for (int j=0;j<=MAX_NODES-1;j++)
			m_gMatrix.grCont[i][j] = 0;
	}
}

bool baseGraph::addElem(graphNode n1,graphNode n2,int weight)
{
	int k1 = getKey(n1);
	int k2 = getKey(n2);

	m_gMatrix.grCont[k1][k2] = weight;
	return true;
}

int baseGraph::addChildren2Q(graphNode node)
{
	int key2search = getKey(node);
	bool found = false;

	return (addChildren2Q(key2search,-1,found));
}

int baseGraph::addChildren2Q(int nodeVal,int tgtNodeVal,bool &found)
{
	int dist = 0;
	found = false;

	for (int i = 0;i<=MAX_NODES;i++)
	{
		if ((!checkifVisited(i)) && (m_gMatrix.grCont[nodeVal][i] == 1))
		{
			m_grQ.push(i);
			visitedNodes[i] = true;
			currLnAtNode[i] = currLnAtNode[nodeVal] + 1;
			if (i == tgtNodeVal)
			{
				found = true;
				dist = currLnAtNode[i];
			}
		}
	}

	return dist;
}

bool baseGraph::checkifVisited(int index)
{
	return (visitedNodes[index]);
}

bool baseGraph::myBFS(graphNode start,graphNode dst,int &bestPath)
{
	bestPath = 0;
	int visitedCt = 0;
	bool foundElem = false;

	m_grQ.push(start.getVal());
	visitedNodes[visitedCt] = true;
	visitedCt++;

	while (m_grQ.size() != 0)
	{
		//bestPath++;
		int currNodeVal = m_grQ.front();
		m_grQ.pop();

		int path = addChildren2Q(currNodeVal,dst.getVal(),foundElem);

		if (path == 0)
			printf("No children in Q \n");
		else
		{
			if (foundElem)
			{
				bestPath = path;
				return true;
			}
		}
	}
	return false;
}

int baseGraph::getKey(graphNode node)
{
	return (node.getVal());
}

baseGraph::~baseGraph(void)
{
}
