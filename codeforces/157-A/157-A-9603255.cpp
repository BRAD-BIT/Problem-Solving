#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int **a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int rowsum = 0;
    int colsum = 0;
    int s1 = 0;
    int s2 = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s1 = 0;
            s2 = 0;
            rowsum = 0;
            colsum = 0;
            while (s1<n&&s2<n)
            {
                rowsum = rowsum + a[i][s1];
                colsum = colsum + a[s2][j];
                s1++;
                s2++;
            }
            if (colsum > rowsum)sum++;
        }
    }
    cout << sum;
}