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
int main()
{
    int n, m;
    set<int> s;
    cin >> n >> m;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = n - 1; j >= 0; j--)
    {
        s.insert(a[j]);
        b[j] = s.size();
    }
    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        cout << b[x - 1] << endl;
    }
}