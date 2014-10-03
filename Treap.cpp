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
		return (new BinNode(k, p, NULL, NULL, NULL));
	if(k < subroot->getKey()) 
	{
		BinNode * left_child = inserthelp(subroot->left(), k, p);
		subroot->setLeft(left_child);
		left_child->setParent(subroot);

		if(subroot->left()->getPriority() > subroot->getPriority())
			subroot = rrot(subroot);
	} 
	else 
	{
		BinNode * right_child = inserthelp(subroot->right(), k, p);
		subroot->setRight(right_child);
		right_child->setParent(subroot);

		if(subroot->right()->getPriority() > subroot->getPriority()) 
			subroot = lrot(subroot);
	}
	return subroot;
}

BinNode * Treap::removehelp(BinNode * subroot, const int& K)
{
	if(subroot == NULL)
		return NULL;
	else if(K < subroot->getKey()) 
	{
		BinNode * left_child = removehelp(subroot->left(), K);
		subroot->setLeft(left_child);
		if (left_child != NULL) 
			left_child->setParent(subroot);
	}
	else if(K > subroot->getKey())
	{
		BinNode * right_child = removehelp(subroot->right(), K);
		subroot->setRight(right_child);
		if (right_child != NULL) 
			right_child->setParent(subroot);
	}
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
			BinNode * left_child = removehelp(subroot->left(), K);
			subroot->setLeft(left_child);
			if (left_child != NULL) 
				left_child->setParent(subroot);
		}
		else
		{
			subroot = rrot(subroot);
			BinNode * right_child = removehelp(subroot->right(), K);
			subroot->setRight(right_child);
			if (right_child != NULL) 
				right_child->setParent(subroot);
		}
	}
	return subroot;
}

BinNode * Treap::lrot(BinNode * k1) 
{
	BinNode * k2 = k1->right();

	k1->setRight(k2->left());
	if (k2->left() != NULL) 
		k2->left()->setParent(k1);

    k2->setLeft(k1);
	k1->setParent(k2);

    k1 = k2;
	return k1;
}
	
BinNode * Treap::rrot(BinNode * k1) 
{
	BinNode * k2 = k1->left();

    k1->setLeft(k2->right());
	if (k2->right() != NULL)
		k2->right()->setParent(k1);

    k2->setRight(k1);
	k1->setParent(k2);

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