// MyTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "eTree.h"
//#include "avlTree.h"
#include "medTree.h"
#include <typeinfo>

//medTree* testTree;

int _tmain(int argc, _TCHAR* argv[])
{
	medTree* testTree = new medTree();

	//eTree* testTree = new eTree();

	
	testTree->addElem(8);
	testTree->addElem(10);
	int median = testTree->getCurrMedian();

	testTree->addElem(7);

	median = testTree->getCurrMedian();

	testTree->addElem(9);
	testTree->addElem(11);
	testTree->addElem(25);
	testTree->addElem(4);
	testTree->addElem(3);
	median = testTree->getCurrMedian();
	testTree->addElem(27);

	median = testTree->getCurrMedian();

	/*
	testTree->add(12,429);
	testTree->add(10,119);
	testTree->add(7,19);
	testTree->add(19,118);
	testTree->inOrder();
	testTree->del(12,429);
	testTree->del(10,429); */

	return 0;
}

