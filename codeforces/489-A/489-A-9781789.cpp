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
struct swap1
{
    int index1;
    int index2;
};
int main()
{
    int n; cin >> n; int *a = new int[n]; for (int i = 0; i < n; i++){ cin >> a[i]; }
    swap1 c[10000];
    int sum = 0;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int min1 = a[i];
        int v = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (min1>a[j])
            {
                min1 = a[j];
                v = j;
            }
        }
        if (v != -1)
        {
            sum++;
            swap(a[i], a[v]);
            c[m].index1 = i;
            c[m].index2 = v;
            m++;
        }
    }
    cout << sum << endl;
    for (int i = 0; i < sum; i++)
    {
        cout << c[i].index1 << " " << c[i].index2 << endl;
    }
}