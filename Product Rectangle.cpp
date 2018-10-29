#include<bits/stdc++.h>
using namespace std;
int agetMaxa(vector<long int> arr, int n, int start, int end){

	int max;
	int firstmax = arr[0];
	max = arr[0];
	for (int i = 1; i < n; i++){
		if (firstmax < 0){
			firstmax = arr[i];
			start = i;
		}
		else{
			firstmax += arr[i];
		}
		if (firstmax > max){
			max = firstmax;
			end = i;
		}
	}
	return max;

}

int main()
{
	int m, n, mx;
	long int x, y;
	cin >> n >> m;
	mx = max(n, m);
	vector<long int> v1(mx), v2(mx), v11(mx), v22(mx);
	for (int i = 0; i < n; i++){ cin >> x; v1[i] = x; v11[i] = -x; }
	for (int i = 0; i < m; i++){ cin >> y; v2[i] = y; v22[i] = -y; }
	long int a, b, a1, b1;
	a = agetMaxa(v1, mx, 0, 0);
	b = agetMaxa(v2, mx, 0, 0);
	a1 = agetMaxa(v11, mx, 0, 0);
	b1 = agetMaxa(v22, mx, 0, 0);
	cout << max(a*b, a1*b1) << endl;
	return 0;
}
