#pragma once

#include <algorithm>
#include <vector>

using namespace std;

const bool MIN_HEAP = true;
const bool NO_MIN_HEAP = false;

class eHeap
{
private:
	
typedef struct myNode{
		int key;
		bool remove;
		myNode():remove(false)
		{
		}
	} heapNode;

	vector<heapNode> heapArr;
	int currNode;
	bool getParentKey(int myKey,int &parentKey);
	void getChildren(int parent,int &leftChild,int &rightChild);
	bool compareNodeVals(int child,int parent);
	void swapNodes(int node1Loc,int node2Loc);
	bool findValue(int curr,int data2find,int &index);
	bool deleteIndex(int index2del);
	bool compNodesRec(int node);
	
#if 0
	bool searchKey(int key2search,myLL* &listwithkey);
	bool searchData(int data2search,myLL* &listwithdata);
#endif

public:
	eHeap(void);
	void insert(int data2insert);
	bool lookupValue(int data2find,int &index);
	int getTopValue();
#if 0
	bool deleteElem(myLL* node2delete,int &value);
#endif
	bool deleteElem(int val2delete);
	~eHeap(void);
};

