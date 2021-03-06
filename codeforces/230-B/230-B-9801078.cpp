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
#include <stdio.h>
#include<fstream>
using namespace std;
inline bool IsPrime(int number)
{
    if (((!(number & 1)) && number != 2) || (number < 2) || (number % 3 == 0 && number != 3))
        return (false);

    for (int k = 1; 36 * k*k - 12 * k < number; ++k)
    if ((number % (6 * k + 1) == 0) || (number % (6 * k - 1) == 0))
        return (false);
    return true;
}
int main()
{
    int n;long double a=1000000000000; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (sqrt(a) != long long(sqrt(a)))cout << "NO" << endl;
        else
        {
            if (IsPrime(sqrt(a)))cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}