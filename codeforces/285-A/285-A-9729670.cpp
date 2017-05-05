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
    int n, k;
    cin >> n >> k;
    int l = 0;
    for (int i = n; i > 0; i--)
    {
        if (l == k)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j << " ";
            }
            break;
        }
        else
        {
            cout << i << " ";
            l++;
        }
    }
}