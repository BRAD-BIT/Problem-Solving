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
    int n,x; cin >> n; vector<int> a; vector<int> b; vector<int> c;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 0)c.push_back(x);else if (x>0)a.push_back(x);else b.push_back(x);
    }
    if (a.size() == 0&&b.size()%2!=0)
    {
        cout << b.size() - 2 << " "; for (int i = 0; i < b.size() - 2; i++)cout << b[i] << " "; cout << endl;
        cout << 2 << " "; for (int i = b.size() - 2; i < b.size(); i++)cout << b[i] << " "; cout << endl;
        cout << c.size() << " "; for (int i = 0; i < c.size(); i++)cout << c[i] << " "; cout << endl;
    }
    else
    if (a.size() == 0 && b.size() % 2 == 0)
    {
        cout << b.size() - 3 << " "; for (int i = 0; i < b.size() - 3; i++)cout << b[i] << " "; cout << endl;
        cout << 2 << " "; for (int i = b.size() - 3; i < b.size()-1; i++)cout << b[i] << " "; cout << endl;
        cout << c.size()+1 << " "; for (int i = 0; i < c.size(); i++)cout << c[i] << " "; cout<<b[b.size()-1] << endl;
    }
    else
    if (b.size()%2!=0)
    {
        cout << b.size() << " "; for (int i = 0; i < b.size(); i++)cout << b[i] << " "; cout << endl;
        cout << a.size() << " "; for (int i = 0; i < a.size(); i++)cout << a[i] << " "; cout << endl;
        cout << c.size() << " "; for (int i = 0; i < c.size(); i++)cout << c[i] << " "; cout << endl;
    }
    else
    if (b.size() % 2 == 0)
    {
        cout << b.size()-1 << " "; for (int i = 0; i < b.size()-1; i++)cout << b[i] << " "; cout << endl;
        cout << a.size() << " "; for (int i = 0; i < a.size(); i++)cout << a[i] << " "; cout << endl;
        cout << c.size() + 1 << " "; for (int i = 0; i < c.size(); i++)cout << c[i] << " "; cout << b[b.size() - 1] << endl;
    }
}