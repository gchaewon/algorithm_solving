#include <bits/stdc++.h>
using namespace std;
int n;
char arr[101][101];
string s;
string q(int y, int x, int size)
{
	if(size==1) return string(1,arr[y][x]);
	string ret;
	char b = arr[y][x];
	for(int i=y; i<y+size; i++)
	{
		for(int j=x; j<x+size; j++)
		{
			if(b != arr[i][j])
			{
				ret += '(';
				ret += q(y,x,size/2);
				ret += q(y,x+size/2,size/2);
				ret += q(y+size/2,x,size/2);
				ret += q(y+size/2,x+size/2,size/2);
				ret += ')';
				return ret;
			}
		}
	}
	return string(1,arr[y][x]);
}
int main()
{
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> s;
		for(int j=0; j<n; j++)
		{
			arr[i][j] =s[j];
		}
	}
	cout << q(0,0,n);
	return 0;
}