#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    int p;
    cin >> p;
    int ap;
    for (int i = 0; i < p; i++)
    {
        cin >> ap;
        for (int j = 0; j < n; j++)
        {
            if (ap == a[j])
            {
                a[j] = 0;
            }
        }

    }
    int q;
    cin >> q;
    int aq;
    for (int i = 0; i < q; i++)
    {
        cin >> aq;
        for (int j = 0; j < n; j++)
        {
            if (aq == a[j])
            {
                a[j] = 0;
            }
        }
    }
    int sum = a[0];
    for (int i = 1; i < n; i++)
    {
        sum = sum + a[i];
    }
    if (sum == 0)cout << "I become the guy.";
    else cout << "Oh, my keyboard!";

}