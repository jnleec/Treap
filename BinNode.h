#ifndef BINNODE_H
#define BINNODE_H

#include <iostream>
using namespace std;

class BinNode
{
private:
	int key;
	int priority;
	BinNode * lc;
	BinNode * rc;
	BinNode * pa;

public:

	BinNode()
	{
		lc = rc = pa = NULL;
	}

	BinNode(int k, int p, BinNode * l = NULL, BinNode * r = NULL, BinNode * par = NULL)
	{
		key = k;
		priority = p;
		lc = l;
		rc = r;
		pa = par;
	}

	~BinNode(){}

	int& getKey()
	{
		return key;
	}

	void setKey(const int& k)
	{
		key = k;
	}

	int& getPriority()
	{
		return priority;
	}

	void setPriority(const int& p)
	{
		priority = p;
	}

	inline BinNode * left() const
	{
		return lc;
	}

	void setLeft(BinNode * b)
	{
		lc = b;
	}

	inline BinNode * right() const
	{
		return rc;
	}

	void setRight(BinNode * b)
	{
		rc = b;
	}

	inline BinNode * parent() const
	{
		return pa;
	}

	void setParent(BinNode * par)
	{
		pa = par;
	}

	bool isLeaf()
	{
		return (lc == NULL) && (rc == NULL);
	}
};

#endif