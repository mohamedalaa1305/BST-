#pragma once
#include<iostream>
#include<deque>
#include <string>
using namespace std;
template<class data_type>
class binary_tree
{
	struct node
	{
		data_type value;
		node *left;
		node *right;
	};
	node *root;
	node *insert(data_type v, node *n)
	{
		if (n == NULL)
		{
			n = new node;
			n->value = v;
			n->left = n->right = NULL;
		}
		else if (v < n->value)
			n->left = insert(v, n->left);
		else if (v > n->value)
			n->right = insert(v, n->right);
		return n;
	}
	bool find(data_type value, node *n)
	{
		if (n == NULL)
			return false;
		if (value < n->value)
			return find(value, n->left);
		else if (value > n->value)
			return find(value, n->right);
		else
			return true;
	}
	node *reset(node *n)
	{
		if (n == NULL)
			return NULL;
		reset(n->left);
		reset(n->right);
		delete n;
		n = NULL;
		return NULL;
	}
	node *findmin(node *n)
	{
		if (n == NULL)
			return NULL;
		else if (n->left == NULL)
			return n;
		else
			return findmin(n->left);
	}
	node *remove(data_type value, node *n)
	{
		if (n == NULL)
			return NULL;
		if (value < n->value)
			n->left = remove(value, n->left);
		else if (value > n->value)
			n->right = remove(value, n->right);
		else if (n->left&&n->right)
		{
			node *temp;
			temp = findmin(n->right);
			n->value = temp->value;
			n->right = remove(n->value, n->right);
		}
		else
		{
			if (n->left)
				n = n->left;
			else if (n->right)
				n = n->right;
			else
			{
				delete n;
				n = NULL;
			}
		}
		return n;
	}
	void inorder(node* t)
	{
		if (t == NULL)
			return;
		inorder(t->left);
		cout << t->value << " ";
		inorder(t->right);
	}
	void bfs()
	{
		if (root == NULL)
		{
			cout << "the tree is empty";
			return;
		}
		deque< pair<node*, int> >dq;
		dq.push_back({ root,0 });
		int lastlevel = 0;
		while (!dq.empty())
		{
			node *n = dq.front().first;
			int level = dq.front().second;
			dq.pop_front();
			if (level>lastlevel)
			{
				cout << endl;
				lastlevel = level;
			}
			cout << n->value << " ";
			if (n->left != NULL)
				dq.push_back({ n->left,level + 1 });
			if (n->right != NULL)
				dq.push_back({ n->right,level + 1 });
		}
	}

public:
	binary_tree()
	{
		root = NULL;
	}
	~binary_tree()
	{
		root = reset(root);
	}
	void insert(data_type value)
	{
		root = insert(value, root);
	}
	bool find(data_type value)
	{
		return find(value, root);
	}
	void remove(data_type value)
	{
		if (find(value, root))
			root = remove(value, root);
		else
			cout << "this value does not exist." << endl;
	}
	void display()
	{
		inorder(root);
		cout << endl;
	}
	void bfsdisplay()
	{
		bfs();
		cout << endl;
	}
};