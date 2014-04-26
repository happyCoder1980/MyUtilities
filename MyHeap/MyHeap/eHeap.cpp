#include "StdAfx.h"
#include "eHeap.h"


eHeap::eHeap(void)
{
	currNode = 0;
	heapArr.reserve(10);
}

int eHeap::getTopValue()
{
	return (heapArr[0].key);
}

bool eHeap::deleteElem(int val2delete)
{
	int index2del;
	if (lookupValue(val2delete,index2del))
		return (deleteIndex(index2del));
	else
		return false;
}

void eHeap::getChildren(int parent,int &leftChild,int &rightChild)
{
	leftChild = ((parent+1)*2) - 1;
	rightChild = (parent+1)*2;
}

bool eHeap::compareNodeVals(int child, int parent)
{
	if ((parent <= currNode) && (child <= currNode))
	{
		if (heapArr[parent].key <= heapArr[child].key)
		return MIN_HEAP;
	else
		return NO_MIN_HEAP;
	}
	else
		return MIN_HEAP;
}

void eHeap::swapNodes(int node1Loc,int node2Loc)
{
	heapNode tempNode;
	tempNode = heapArr[node1Loc];
	heapArr[node1Loc] = heapArr[node2Loc];
	heapArr[node2Loc] = tempNode;
}

void eHeap::insert(int data2insert)
{
	heapNode node2add;

	node2add.key = data2insert;

	//add the node
	//if (currNode == 0)
		heapArr.push_back(node2add);
/*	else
		heapArr[currNode] = node2add;*/
	
	int parentNode;
	//check if heap property is maintained.
	int node2process = currNode;
	while (getParentKey(node2process,parentNode))
	{
		if (compareNodeVals(node2process,parentNode) == NO_MIN_HEAP) //min heap not satisfied..so swap
		{	
			swapNodes(node2process,parentNode);
			node2process = parentNode;
		}
		else
		{
			currNode++;
			return;
		}
	}
			
	currNode++;
		
}

bool eHeap::lookupValue(int data2find,int &index)
{
	return (findValue(0,data2find,index));
}

bool eHeap::findValue(int curr,int data2find,int &index)
{
	int left,right;
	
	while (curr <= (currNode-1))
	{
		if (heapArr[curr].key > data2find)
			return false;
		else if (heapArr[curr].key == data2find)
		{
			index = curr;
			return true;
		}
		else if (heapArr[curr].key < data2find)
		{
			getChildren(curr,left,right);
			//curr = left;
			if (!findValue(left,data2find,index))
				return (findValue(right,data2find,index));
			else
				return true;
		}
	}

	return false;
}

bool eHeap::compNodesRec(int node)
{
	int left,right;
	getChildren(node,left,right);

	if (node <= currNode-1) 
	{
		
		if (compareNodeVals(node,left) == NO_MIN_HEAP)
		{
			swapNodes(node,left);
			if (compNodesRec(left) == NO_MIN_HEAP)
				return (compNodesRec(right) == NO_MIN_HEAP);
		}
		else
			return true;
	}
	else
		return false;
}

bool eHeap::deleteIndex(int index2del)
{
	if (index2del == currNode-1)
	{
		heapArr[currNode-1].key = -1;
		heapArr[currNode-1].remove = true;
		currNode--;
	}
	else
	{
		swapNodes(index2del,currNode-1);
		heapArr[currNode-1].key = -1;
		heapArr[currNode-1].remove = true;//delete the node.

		int node2process = index2del;
		int parentNode;
		bool isHeap = false;

		while ((getParentKey(node2process,parentNode)) && (!isHeap))
		{
			if (compareNodeVals(node2process,parentNode) == NO_MIN_HEAP) //min heap not satisfied..so swap
			{	
				swapNodes(node2process,parentNode);
				node2process = parentNode;
			}
			else
				isHeap = true;
		}

		node2process = index2del;

		compNodesRec(node2process);
		currNode--;
	}
	return true;
}



#if 0
bool eHeap::searchData(int data2search,myLL* &listwithdata)
{
	return false;
}

bool eHeap::searchKey(int key2search, myLL* &listwithkey)
{
	return false;
}
#endif

bool eHeap::getParentKey(int myKey,int &parentKey)
{
	if (myKey == 0) //head
		return false;
	
	if (myKey %2 == 0) //even number
		parentKey = ((myKey/2)-1);
	else
		parentKey = (myKey/2);
	return true;
}

eHeap::~eHeap(void)
{
}
