#include "Treap.h"

int main()
{

	int nunber_of_node;
	int key;
	int priority;
	Treap treap;

	cout<<"nunber_of_node:";
	cin>>nunber_of_node;
	for(int j = 0; j<nunber_of_node; j++)
	{
		cout<<"key:";
		cin>>key;
		cout<<"priority:";
		cin>>priority;
		treap.insert(key, priority);
	}
	cout<<"treap:"<<endl;
	treap.print();

	//cout<<"delete one node by key:";
	//cin>>key;
	
	//treap.remove(key);
	//treap.print();

	cout<<"sort by priority:"<<endl;
	BinNode *sortList = treap.sort(nunber_of_node);
	for (int i = 0; i < nunber_of_node; i++)
	{
		cout<<sortList[i].getKey()<<"|"<<sortList[i].getPriority()<<"\t";
	}
	cout<<endl;

	system("pause");
	return 0;
}