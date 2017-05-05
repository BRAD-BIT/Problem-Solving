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
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    int sum = 0;
    int i = 0;
    int j = n - 1;
    int x = 0;
    int y = 0;
    int c;
    int d;
    bool test1 = true;
    bool test2 = true;
    while (true&&i!=n&&j!=-1)
    {
        if (a[i] != b[i] && test1)
        {
            x = i;
            test1 = false;

        }
        if (a[j] != b[j] && test2)
        {
            y = j;
            test2 = false;
        }
        if (!test1&&!test2)break;
        i++;
        j--;
    }
    reverse(a+x, a+y+1);
    bool test = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            test = false;
            break;
        }
    }
    if (test&&test1&&test2)cout << "yes" << endl << 1 << " " << 1;
    else 
    if (test)cout << "yes" << endl << x+1 << " " << y+1;
    else
        cout << "no";
}