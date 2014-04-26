#pragma once
#include "avlTree.h"

/*const int BALANCED = 0;
const int RIGHT_UNBALANCED = 1;
const int LEFT_UNBALANCED = 2;*/

typedef struct myLL {
		int value;
		myLL* left;
		myLL* right;
		myLL* parent;
	} treeLL;

class medTree
{
private:
	

	//int m_currMedian;
	int m_leftCt;
	bool m_leftOfHead;
	int m_rightCt;
	myLL* head;
	myLL* curr;
	myLL* m_currMedian;
	_int8 getBalancedState(int &htDiff);
	bool rotateLeft(myLL* &node);
	bool rotateRight(myLL* &node);
	bool balanceTree(myLL* &node);
	bool lookupElem(myLL* node,int data2find);
	bool deleteElement(myLL* node,int num2del);
	bool deleteNode(myLL* &node2del);
	void addElement(myLL* &node,int num,bool &leftOfHead);

public:
	medTree(void);
	~medTree(void);
	void addElem(int num2add);
	bool deleteElem(int num);
	int getCurrMedian();
	bool updateCurrMedian();
	bool find(int num);
};

