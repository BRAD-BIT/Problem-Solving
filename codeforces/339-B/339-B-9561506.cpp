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
    long long n, m;
    cin >> n >> m;
    long long *a = new long long[m];
    for (long long i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    long long sum = 0;
    long long pos = 1;
    for (long long i = 0; i < m; i++)
    {
        if (a[i] != pos)
        {
            if (pos == n)
            {
                pos = 1;
                sum++;
                i--;
            }
            else
            {
                if (pos > a[i])
                {
                    sum = sum + (n - pos) + (a[i]);
                    pos = a[i];
                }
                else
                {
                    sum = sum + (a[i] - pos);
                    pos = a[i];
                }
            }
        }
    }
    cout << sum;
}
/*stringstream ss;
ss << int name;
string string name = ss.str();*/


//bool comp(structname a, structname b)
//{
//  return a.struct1 < b.struct2; or >for desc. or b to sort 3la b
//}andeha fe al sort