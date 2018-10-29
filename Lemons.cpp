#include<iostream>
using namespace std;

int main(){
	int N,M,S;
	int mid;
	int start = 1;
	cin>>N>>M>>S;
	int sum = 0;
	while(true)
	{
		if((N-start)%2 == 0)
			mid = (N-start)/2;
		else
			mid = (N-start)/2+1;
		sum = sum + mid*M+S;
		start += mid;
		if(start == N)
			break;
	}	
	cout<<sum<<endl;

}
