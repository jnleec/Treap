#ifndef TREAP_H
#define TREAP_H

#include "BinNode.h"

class Treap
{
private:
	BinNode * root;
	int nodecount;

	void clearhelp(BinNode *);
	BinNode * inserthelp(BinNode *, const int&, const int&);
	BinNode * removehelp(BinNode *, const int&);
	BinNode * lrot(BinNode *);
	BinNode * rrot(BinNode *);
	BinNode removetop();
	void printhelp(BinNode *, int) const;
	int heighthelp(BinNode *);

public:
	Treap()
	{
		root = NULL;
		nodecount = 0;
	}

	~Treap()
	{
		clearhelp(root);
	}

	void clear()
	{
		clearhelp(root);
		root = NULL;
		nodecount = 0;
	}

	bool insert(const int& k, const int& p)
	{
		root = inserthelp(root, k, p);
		nodecount++;
		return true;
	}

	void remove(const int& K)
	{
		root = removehelp(root, K);
		nodecount--;
	}

	BinNode * sort(int nunber_of_node) 
	{
		if (size() > 0) 
		{
			BinNode *sortList = new BinNode[nunber_of_node];
			for (int i = 0; i < nunber_of_node; i++)
			{
				sortList[i] = removetop();
			}

			return sortList;
		}
		else
		{
			return NULL;
		}
	}

	int size()
	{
		return nodecount;
	}

	void print() const
	{
		if(root == NULL)
			cout<<"The Treap is empty.\n";
		else
			printhelp(root, 0);
	}

	int height();
};

#endif