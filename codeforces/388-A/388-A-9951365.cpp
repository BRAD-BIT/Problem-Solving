#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int n, x; cin >> n; vector<int> a; for (int i = 0; i < n; i++){ cin >> x; a.push_back(x); }sort(a.begin(), a.end());
    int sum = 0, zum = 0;
    while (a.size() != 0)
    {
        a.erase(a.begin()); zum++;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] >= zum){ a.erase(a.begin() + i); zum++; i = -1; }
        }
        zum = 0;
        sum++;
    }
    cout << sum << endl;
}