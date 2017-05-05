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
    int n, x, l, r, sum = 0, v = 1;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        while (true)
        {
            v += x;
            if (v == l){ sum += (r - l +1); break; }
            else
            if (v >l)
            {
                v -= x;
                sum += (r - v+1);
                break;
            }
        }
        v = r+1;
    }
    cout << sum << endl;
}