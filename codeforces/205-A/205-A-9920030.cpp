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
struct city{ll dis,index;};
bool comp(city a, city b){return a.dis < b.dis;}
int main()
{
    int n; cin >> n; city *a = new city[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].dis; a[i].index = i + 1;
    }
    sort(a, a + n, comp);
    for (int i = 0; i < n-1; i++)
    {
        if (a[0].dis == a[i + 1].dis){cout << "Still Rozdil" << endl; return 0;}
    }
    cout << a[0].index;
}