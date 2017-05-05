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
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 0; i < 1000; i++)
    {
        if (i % 2 == 0)
        {
            n1--;
            if (n1 == 0){ cout << "Second"; return 0; }
        }
        else
        {
            n2--;
            if (n2 == 0){ cout << "First"; return 0; }
        }
    }
}