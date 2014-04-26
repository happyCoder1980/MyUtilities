#pragma once
#include "medTree.h"

class MovingAvg
{
private:
	int* allEntries;
	medTree* sortedNums;
public:
	MovingAvg(int windowSize);
	void addNum(int num2add);
	int getMedian();
	~MovingAvg(void);
};

