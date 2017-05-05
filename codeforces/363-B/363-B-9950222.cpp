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
struct ma{ int sum, index; };
bool comp(ma a, ma b)
{
    return a.sum < b.sum;
}
int main()
{
    int n, k; cin >> n >> k; int *a = new int[n]; ma *b = new ma[n - k + 1]; for (int i = 0; i < n; i++){ cin >> a[i]; if (i < n - k + 1){ b[i].index = -1; b[i].sum = 0; } }
    int m = 0;
    int j = 1;
    int count = 0;
    for (int i = 0; i <n; i++)
    {
        if (count == k)
        {
            m++, j++; b[m].index = j, b[m].sum = a[i] + b[m - 1].sum - a[i - k];
        }
        if (m == 0)
        {
            b[m].index = j;
            b[m].sum += a[i];
            count++;
        }
        else{ count = k; }
    }
    sort(b, b + n - k + 1, comp);
    cout << b[0].index << endl;
}