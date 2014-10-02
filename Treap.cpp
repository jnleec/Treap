#include "Treap.h"

void Treap::clearhelp(BinNode * subroot)
{
	if(subroot == NULL)
		return;
	clearhelp(subroot->left());
	clearhelp(subroot->right());
	delete subroot;
}

BinNode * Treap::inserthelp(BinNode * subroot, const int& k, const int& p)
{
	if(subroot == NULL)
		return (new BinNode(k, p, NULL, NULL));
	if(k < subroot->getKey()) 
	{
		subroot->setLeft(inserthelp(subroot->left(), k, p));
		if(subroot->left()->getPriority() > subroot->getPriority())
		{
			subroot = rrot(subroot);
		}
	} 
	else 
	{
		subroot->setRight(inserthelp(subroot->right(), k, p));
		if(subroot->right()->getPriority() > subroot->getPriority()) 
		{
			subroot = lrot(subroot);
		}
	}
	return subroot;
}

BinNode * Treap::removehelp(BinNode * subroot, const int& K)
{
	if(subroot == NULL)
		return NULL;
	else if(K < subroot->getKey())
		subroot->setLeft(removehelp(subroot->left(), K));
	else if(K > subroot->getKey())
		subroot->setRight(removehelp(subroot->right(), K));
	else
	{
		if(subroot->left() == NULL) 
		{
			BinNode * tmp = subroot;
			subroot = subroot->right();
			delete tmp;
		}
		else if(subroot->right() == NULL)
		{
			BinNode * tmp = subroot;
			subroot = subroot->left();
			delete tmp;
		}
		else if (subroot->left()->getPriority() < subroot->right()->getPriority())
		{
			subroot = lrot(subroot);
			subroot->setLeft(removehelp(subroot->left(), K));
		}
		else
		{
			subroot = rrot(subroot);
			subroot->setRight(removehelp(subroot->right(), K));
		}
	}
	return subroot;
}

BinNode * Treap::lrot(BinNode * k1) 
{
	BinNode * k2 = k1->right();
	k1->setRight(k2->left());
    k2->setLeft(k1);
    k1 = k2;
	return k1;
}
	
BinNode * Treap::rrot(BinNode * k1) 
{
	BinNode * k2 = k1->left();
    k1->setLeft(k2->right());
    k2->setRight(k1);
    k1 = k2;
	return k1;
}

BinNode Treap::removetop() 
{
	BinNode rootNode = *root;
	root = removehelp(root, root->getKey());
	return rootNode;
}

void Treap::printhelp(BinNode * subroot, int level) const
{
	if(subroot == NULL)
		return;
	printhelp(subroot->left(), level+1);
	for(int i = 0; i < level; i++)
		cout<<"  ";
	cout<<subroot->getKey()<<"|"<<subroot->getPriority()<<endl;
	printhelp(subroot->right(), level+1);
}

int Treap::heighthelp(BinNode * subroot)
{
	if(subroot == NULL)
		return 0;
	return 1 + max(heighthelp(subroot->left()), heighthelp(subroot->right()));
}

int Treap::height()
{
	return heighthelp(root);
}