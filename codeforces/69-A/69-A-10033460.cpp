#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int **a= new int*[n];
    int sum[3];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[3];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                sum[i] =a[j][i];
            }
            else
                sum[i] = sum[i] + a[j][i];
        }
    }
    bool test = true;
    for (int i = 0; i < 3; i++)
    {
        if (sum[i] != 0)
        {
            test = false;
            break;
        }
    }
    if (test)cout << "YES";
    else cout << "NO";
}