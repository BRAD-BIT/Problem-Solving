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
#include <stdio.h>
#include<fstream>
using namespace std;
int main()
{
    int n, s, sum = 0; cin >> n >> s; int *a = new int[n]; for (int i = 0; i < n; i++){ cin >> a[i]; sum += a[i]; }
    sort(a, a + n); sum -= a[n - 1];
    if (sum>s)cout << "NO" << endl; else cout << "YES" << endl;
}