#include<bits/stdc++.h>
#pragma warning(disable:4996)

using namespace std;


bool cal(string str, int pos, int res,map<char,int> map)
{
	int a = 0, b = 0, c = 0, d = 0;//()[]
	for (int i = pos + 1; i < str.size(); i++){
		if (str[i] == '('){
			a++;
		}
		else if (str[i] == ')')
		{
			b++;
		}
		else if (str[i] == '[')
		{
			c++;
		}
		else{
			d++;
		}
	}

	auto it = map.find('(');
	if (it != map.end()){
		a += it->second;
	}
	it = map.find(')');
	if (it != map.end()){
		b += it->second;
	}
	it = map.find('[');
	if (it != map.end()){
		c += it->second;
	}
	it = map.find(']');
	if (it != map.end()){
		d += it->second;
	}

	if (min(a, b) * 2 + min(c, d) * 2 >= res){
		return true;
	}
	else{
		return false;
	}
}


bool cal2(string str, int pos, int res, map<char, int> map)
{
	int a = 0, b = 0, c = 0, d = 0;//()[]
	stack<char> s1;//()
	stack<char> s2;//[]
	vector<char> data1;
	vector<char> data2;
	auto it = map.find('(');
	if (it != map.end()){
		a += it->second;
	}
	int tmp = a;
	while (tmp--)
	{
		data1.push_back('(');
	}


	it = map.find(')');
	if (it != map.end()){
		b += it->second;
	}
	tmp = b;
	while (tmp--)
	{
		data1.push_back(')');
	}


	it = map.find('[');
	if (it != map.end()){
		c += it->second;
	}
	tmp = c;
	while (tmp--)
	{
		data2.push_back('[');
	}



	it = map.find(']');
	if (it != map.end()){
		d += it->second;
	}
	tmp = d;
	while (tmp--)
	{
		data2.push_back(']');
	}


	for (int i = pos + 1; i < str.size(); i++){
		if (str[i] == '('){
			a++;
			data1.push_back(str[i]);
		}
		else if (str[i] == ')')
		{
			data1.push_back(str[i]);
			b++;
		}
		else if (str[i] == '[')
		{
			c++;
			data2.push_back(str[i]);
		}
		else{
			data2.push_back(str[i]);
			d++;
		}
	}


	int aa = 0, bb = 0;
	for (int i = 0; i < data1.size(); ++i)
	{
		if (!s1.empty()){
			if (s1.top() == ')')
			{
				//s1.pop();
				s1.push(data1[i]);
			}
			else{
				if (data1[i] == ')'){
					s1.pop();
					aa += 2;
				}
				else{
					s1.push(data1[i]);
				}
			}
		}
		else{
			s1.push(data1[i]);
		}
	}

	for (int i = 0; i < data2.size(); i++)
	{
		if (!s2.empty()){
			if (s2.top() == ']')
			{
				//s2.pop();
				s2.push(data2[i]);
			}
			else{
				if (data2[i] == ']'){
					s2.pop();
					bb += 2;
				}
				else{
					s2.push(data2[i]);
				}
			}
		}
		else{
			s2.push(data2[i]);
		}
	}


	if (aa + bb >= res){
		return true;
	}
	else{
		return false;
	}
}




bool isTrue(string str)
{
	int a = 0, b = 0, c = 0, d = 0;//()[]
	stack<char> s1;//()
	stack<char> s2;//[]
	vector<char> data1;
	vector<char> data2;
	for (int i = 0; i < str.size(); i++){
		if (str[i] == '('){
			data1.push_back(str[i]);
			a++;
		}
		else if (str[i] == ')')
		{
			data1.push_back(str[i]);
			b++;
		}
		else if (str[i] == '[')
		{
			data2.push_back(str[i]);
			c++;
		}
		else{
			data2.push_back(str[i]);
			d++;
		}
	}

	for (int i = 0; i < data1.size(); ++i)
	{
		if (!s1.empty()){
			if (s1.top() == ')')
			{
				return false;
			}
			else{
				if (data1[i] == ')'){
					s1.pop();
				}
				else{
					s1.push(data1[i]);
				}
			}
		}
		else{
			s1.push(data1[i]);
		}
	}
	
	for (int i = 0; i < data2.size(); ++i)
	{
		if (!s2.empty()){
			if (s2.top() == ']')
			{
				return false;
			}
			else{
				if (data2[i] == ']'){
					s2.pop();
				}
				else{
					s2.push(data2[i]);
				}
			}
		}
		else{
			s2.push(data2[i]);
		}
	}

	if (a == b && c == d && s1.empty() && s2.empty()){
		return true;
	}
	else{
		return false;
	}
}

#define LOCAL

int main()
{
#ifdef LOCAL
	freopen("datain", "r", stdin);
#endif
	string data;

	cin >> data;

	if ((data.size() / 2) % 2 == 1)
	{
		cout << "impossible" << endl;
		return 0;
	}

	//判断impossible
	if (!isTrue(data)){
		cout << "impossible" << endl;
		return 0;
	}


	int resB = data.size() / 2;
	map<char, int> map;
	for (int i = 0; i < data.size(); ++i)
	{
		if (cal2(data, i, resB, map)){
			cout << 1 << " ";
		}
		else{
			map[data[i]]++;
			cout << 2 << " ";
		}
	}

	return 0;
}




