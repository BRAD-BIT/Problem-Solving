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
struct s
{
    int value;
    int index;
};
bool comp(s a, s b)
{
    return a.value < b.value;
}
int main()
{
    int n, k;
    cin >> n >> k;
    s *a = new s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].value;
        a[i].index = i + 1;
    }
    sort(a, a + n,comp);
    int sum1 = 0;
    int sum2 = 0;
    int index;
    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 + a[i].value;
        if (sum1 <= k)sum2++;
        else break;
        index = i;
    }
    cout << sum2 << endl;
    if (sum2 != 0)
    {
        for (int i = 0; i <= index; i++)
        {
            cout << a[i].index << " ";
        }
    }
}