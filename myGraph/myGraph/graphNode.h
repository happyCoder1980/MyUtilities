#pragma once
class graphNode
{
private:
	int m_val;
public:
	graphNode(void);
	int getVal();
	void setVal(int value);
	virtual ~graphNode(void);
};

