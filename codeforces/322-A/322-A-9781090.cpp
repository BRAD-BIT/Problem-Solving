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
    int n, m; cin >> n >> m;
    cout << n + m - 1 << endl;
        int n1 = 1; int m1 = 1;
        while (n1 != n + 1)
        {
            cout << n1 << " " << m1 << endl;
            n1++;
        }
        n1 = 1,m1 = 2;
        while (m1 != m + 1)
        {
            cout << n1 << " " << m1 << endl;
            m1++;
        }
}