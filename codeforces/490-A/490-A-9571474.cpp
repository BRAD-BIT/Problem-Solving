#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
struct child
{
    int index;
    int num;
};
bool comp(child a, child b)
{
    return a.num < b.num;
}
int main()
{
    int n;
    cin >> n;
    child *a = new child[n];
    int sum[] = { 0, 0, 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].num;
        a[i].index = i + 1;
        if (a[i].num == 1)sum[0]++;
        if (a[i].num == 2)sum[1]++;
        if (a[i].num == 3)sum[2]++;
    }
    int min = sum[0];
    for (int i = 0; i < 3; i++)
    {
        if (sum[i]<min)min = sum[i];
    }
    sort(a, a + n, comp);
    int **b = new int*[min + 1];
    for (int i = 1; i <= min; i++)
    {
        b[i] = new int[4];
    }
    int m = 0;
    for (int i = 1; i <4; i++)
    {
        for (int j = 1; j <=min; j++)
        {
            if (a[m].num == i)
            {
                b[j][i] = a[m].index;
                m++;
            }
            else
            {
                m++;
                j--;
            }
        }
    }
    cout << min << endl;
    for (int i = 1; i <= min; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}