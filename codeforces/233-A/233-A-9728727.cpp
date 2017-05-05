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
    if (n %2 !=0)cout << -1;
    else
    if (n % 2 == 0)
    {
        for (int i = n; i > 0; i--)
        {
            cout << i << " ";
        }
    }
}