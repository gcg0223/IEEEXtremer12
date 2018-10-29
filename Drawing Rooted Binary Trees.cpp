#include<iostream>
#include<bits/stdc++.h>
#define LEN 27
using namespace std;
class node
{
public:
	node *l_tree;
	node *r_tree;
	char name;
};
node *dizhi[LEN];
int deepp[LEN], pos, deepest;

int find(char *arr, char target)
{
	for (unsigned int i = 0; i < strlen(arr); i++)
	if (arr[i] == target)
		return(i);
	return(-1);
}
node *creatree(char *pre, char *in)
{
	int temp2;
	if (pre[pos] == 0)
		return NULL;
	int temp, temp1;
	temp = find(in, pre[pos]);
	if (temp == -1)
		return NULL;
	temp1 = strlen(in);
	char *l_in = new char[temp + 1]();
	for (int i = 0; i < temp; i++)
		l_in[i] = in[i];
	char *r_in = new char[temp1 - temp]();
	for (int i = 0; i < temp1 - temp - 1; i++)
		r_in[i] = in[i + temp + 1];
	dizhi[pos] = new node;
	dizhi[pos]->name = pre[pos];
	temp2 = pos;
	pos = pos + 1;
	dizhi[temp2]->l_tree = creatree(pre, l_in);
	dizhi[temp2]->r_tree = creatree(pre, r_in);
	delete l_in;
	delete r_in;
	return dizhi[temp2];
}
void deep(node *tree, int de, char *in)
{
	if (tree == NULL)
	{
		return;
	}
	if (de > deepest)
		deepest = de;
	deepp[find(in, tree->name)] = de;
	deep(tree->l_tree, de + 1, in);
	deep(tree->r_tree, de + 1, in);
	return;
}
int main()
{
	int i, j;
	char preorder[LEN], inorder[LEN];
	while (cin >> inorder >> preorder)
	{
		int lenth;
		lenth = strlen(preorder);
		pos = 0, deepest = 0;
		creatree(preorder, inorder);
		deep(dizhi[0], 0, inorder);
		char **a = new char*[deepest + 1];
		for (i = 0; i < deepest + 1; i++)
		{
			a[i] = new char[lenth + 1];
			for (j = 0; j < lenth + 1; j++)
				a[i][j] = ' ';
			a[i][strlen(preorder)] = '\0';
		}
		for (i = 0; i < lenth; i++)
			a[deepp[i]][i] = inorder[i];
		for (i = 0; i < deepest + 1; i++)
			cout << a[i] << '\n';

		//memset(preorder, 0, sizeof(char)* LEN);
		//memset(inorder, 0, sizeof(char)* LEN);

		for (int i = 0; i < LEN; i++){
			preorder[i] = 0;
			inorder[i] = 0;
		}
		for (i = 0; i < deepest + 1; i++)
			delete[]a[i];
		a = NULL;
		for (i = 0; i < lenth; i++)
			delete dizhi[i];
	}
}
