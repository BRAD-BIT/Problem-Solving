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
    long long n;
    cin >> n;
    long long *a = new long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long max_diff = a[n - 1] - a[0];
    long long sum = 0;
    long long sum2 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == a[n - 1])
        {
            sum++;
        }
        else break;
    }
    if (a[0] == a[1])
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[0])
            {
                sum2++;
            }
            else break;
        }
        if (a[0] == a[n - 1])
        {
            long long sum3 = 0;
            for (int i = 0; i < n; i++)
            {
                sum3 = sum3 + (n - (i+1));
            }
            cout << max_diff << " " << sum3;
        }
        else 
        cout << max_diff << " " << sum*sum2;
    }
    else
    {
        if (a[0] == a[n - 1])cout << 0 << " " << 1;
        else cout << max_diff << " " << sum;
    }
}
/*stringstream ss;
ss << int name;
string string name = ss.str();*/


//bool comp(structname a, structname b)
//{
//  return a.struct1 < b.struct2; or >for desc. or b to sort 3la b
//}andeha fe al sort