#include<iostream>
using namespace std;
int main()
{
	int i, NN, ans, tempaa;
	cin >> NN;
	bool *Q = new bool[NN]();
	cout << 'Q';
	for (i = 0; i < NN; i++)
		cout << ' ' << Q[i];
	cout << '\n';
	cin >> ans;
	if (ans == 0)
	{
		cout << 'A';
		for (i = 0; i < NN; i++)
			cout << ' ' << !Q[i];
		cout << '\n';
	}
	if (ans == NN)
	{
		cout << 'A';
		for (i = 0; i < NN; i++)
			cout << ' ' << Q[i];
		cout << '\n';
	}
	for (int j = 0; j < NN; j++)
	{
		Q[j] = !Q[j];
		cout << 'Q';
		for (i = 0; i < NN; i++)
			cout << ' ' << Q[i];
		cout << '\n';
		cin >> tempaa;
		if (tempaa > ans)
			ans = tempaa;
		else
			Q[j] = !Q[j];
		if (ans == NN)
		{
			cout << 'A';
			for (i = 0; i < NN; i++)
				cout << ' ' << Q[i];
			cout << '\n';
		}
	}
	return 0;
}
