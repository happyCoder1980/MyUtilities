#include "StdAfx.h"
#include "MovingAvg.h"


MovingAvg::MovingAvg(int windowSize)
{
	allEntries = new int[windowSize];
	sortedNums = new medTree();
}


MovingAvg::~MovingAvg(void)
{
}
