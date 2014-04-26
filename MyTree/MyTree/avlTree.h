#pragma once
#include "etree.h"

const bool RIGHT = true;
const bool LEFT = false;

const _int8 BALANCED = 0;
const _int8 RIGHT_UNBALANCED = 1;
const _int8 LEFT_UNBALANCED = 2;

class avlTree :
	public eTree
{
	typedef struct avlStruct {
		int data;
		avlStruct* left;
		avlStruct* right;
		avlStruct* parent;
	} myAVLStruct;

	int m_leftHt;
	int m_rightHt;

	avlStruct* m_head;
	avlStruct* m_curr;
	_int8 isBalanced();
	bool rotateLeft(avlStruct* &node);
	bool rotateRight(avlStruct* &node);
	int addElem2AVL(avlStruct* node,int data2add,bool leftOrRightOfHead);

public:
	avlTree(void);
	int getHeight(bool leftOrRight);
	int addElement(int value);
	bool balanceTree(avlStruct* &node);
	virtual ~avlTree(void);
};

