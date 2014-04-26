#pragma once
#include "graphNode.h"

const int MAX_NODES = 10;
class graphContainer
{
public:
	int grCont[MAX_NODES][MAX_NODES];
	graphContainer(void);
	virtual ~graphContainer(void);
};

