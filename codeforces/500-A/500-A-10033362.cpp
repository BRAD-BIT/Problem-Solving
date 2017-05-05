#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int *a = new int[n];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    bool test = false;
    int z = 0;
    for (int i = 1; i < n; i++)
    {
        z = a[i] + i;
        if (z >= n)break;
        i = z - 1;
        if (z == m)
        {
            test = true;
            break;
        }
    }
    if (z == m)
    {
        test = true;
    }
    if (test)cout << "YES";
    else cout << "NO";
}