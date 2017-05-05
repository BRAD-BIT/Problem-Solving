#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
using namespace std;
struct ass
{
    int value;
    int pos;
};
bool comp(ass a, ass b)
{
    return a.value < b.value;
}
int main()
{
    int n, k;
    cin >> n >> k;
    ass *a = new ass[n];
    int max = 0;
    int min = 1000000;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].value;
        if (max < a[i].value)max = a[i].value;
        if (min > a[i].value)min = a[i].value;
        a[i].pos = i;
    }
    sort(a, a + n, comp);
    int **b = new int *[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = new int[a[i].value + 1];
    }
    int z = max - min;
    int f = n;
    if (z <= k)
    {
        cout << "YES" << endl;
        int v = 0;
        int p = 0;
        int l = 0;
        while (n != 0)
        {
            l = 0;
            int m = 1;
            b[v][0] = a[v].pos;
            for (int i = 0; i <= a[v].value; i++)
            {
                if (i == 0)
                {
                    for (int j = 1; j <= min; j++)
                    {
                        b[v][j] = m;
                        i = j + 1;
                    }
                    if (v != 0)
                    {
                        b[v][i] = 1;
                        i++;
                        m++;
                    }
                }
                if (i > a[v].value)
                {
                    break;
                }
                if (1 == l)
                {
                    l = 0;
                    m++;
                }
                b[v][i] = m;
                l++;
            }
            n--;
            v++;
        }
        int m = 0;
        for (int x = 0; x < f; x++)
        {
            while (x != b[m][0])
            {
                m++;
            }
            for (int i = 1; i <= a[m].value; i++)
            {
                cout << b[m][i] << " ";
            }
            cout << endl;
            m = 0;
        }
    }
    else cout << "NO";
}