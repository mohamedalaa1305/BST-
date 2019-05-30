#include<iostream>
#include <string>
#include"binary_tree.h"
using namespace std;
int main()
{
	binary_tree<string> tree;
	string x;
	for (int i = 0; i < 8; i++)
	{
		cin >> x;
		tree.insert(x);
	}
	if (tree.find("sa"))
		cout << "found" << endl;
	else
		cout << "Not found" << endl;

	tree.bfsdisplay();

	cin >> x;
	tree.remove(x);
	tree.bfsdisplay();
	/*
	cin >> x;
	tree.remove(x);
	tree.bfsdisplay();
	cin >> x;
	tree.remove(x);
	tree.bfsdisplay();
	*/
	system("pause");
	return 0;
}
