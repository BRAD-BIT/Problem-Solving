#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
using namespace std;
void zort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j =i; j < n-1; j++)
		{
			if (a[j + 1]<a[j])swap(a[j + 1], a[j]);
		}
	}
}
int main()
{
	int n; cin >> n;
	if (n == 1 || n == 2)cout << -1;
	else
	{
		for (int i = n; i>0; i--)
		{
			cout << i << " ";
		}
	}
}