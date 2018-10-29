#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int pos;
bool win;

void cal(int begin, int ter, int *a, int *b, bool *readed, int *roll, int N)
{
	roll[pos++] = begin;
	for (int i = 0; i < N; i++)
	{
		if (readed[i] == 1)
			continue;
		if (win == 1)
			return;
		if (a[i] == begin)
		{
			readed[i] = 1;
			if (b[i] == ter)
			{
				win = 1;
				roll[pos++] = ter;
				return;
			}
			cal(b[i], ter, a, b, readed, roll, N);
		}
		if (win == 1)
			return;
		if (b[i] == begin)
		{
			readed[i] = 1;
			if (a[i] == ter)
			{
				win = 1;
				roll[pos++] = ter;
				return;
			}
			cal(a[i], ter, a, b, readed, roll, N);
		}
		if (win == 1)
			return;
	}
	pos--;
}
int main()
{
	int N, M, begin, ter, val;
	cin >> N >> M;
	int *a = new int[N - 1];
	int *b = new int[N - 1];
	int *vall = new int[N]();
	bool *readed = new bool[N - 1]();
	int *roll = new int[N - 1];
	for (int i = 0; i < N - 1; i++)
		cin >> a[i] >> b[i];

	for (int i = 0; i < M; i++)
	{
		pos = 0; win = 0;
		cin >> begin >> ter >> val;
		if (begin == ter)
			roll[pos++] = begin;
		else
			cal(begin, ter, a, b, readed, roll, N - 1);
		for (int j = 0; j < pos; j++)
			vall[roll[j]] += val;
		memset(readed, 0, (N - 1) * sizeof(bool));
	}
	auto maxx = max_element(vall, vall + N);
	cout << *maxx;
}
