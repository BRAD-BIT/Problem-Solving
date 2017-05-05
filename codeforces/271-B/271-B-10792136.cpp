#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
vector<int>prime;
void runEratosthenesSieve(int upperBound)
{
    int upperBoundSquareRoot = (int)sqrt((double)upperBound);
    bool *isComposite = new bool[upperBound + 1];
    memset(isComposite, 0, sizeof(bool)* (upperBound + 1));
    for (int m = 2; m <= upperBoundSquareRoot; m++)
    {
        if (!isComposite[m])
        {
            prime.push_back(m);
            for (int k = m * m; k <= upperBound; k += m)
            {
                isComposite[k] = true;
            }
        }
    }
    for (int m = upperBoundSquareRoot; m <= upperBound; m++)
    {
        if (!isComposite[m])
        {
            prime.push_back(m);
        }
    }
    delete[] isComposite;
}
inline bool IsPrime(int number)
{
    if (((!(number & 1)) && number != 2) || (number < 2) || (number % 3 == 0 && number != 3))
        return (false);

    for (int k = 1; 36 * k*k - 12 * k < number; ++k)
    if ((number % (6 * k + 1) == 0) || (number % (6 * k - 1) == 0))
        return (false);
    return true;
}
int Binary_search(int x)
{
    int low = 0, high = prime.size() - 1, mid; int ans;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (prime[mid] > x)
        {
            ans = prime[mid];
            high = mid - 1;
        }
        else
        if (prime[mid] < x)
        {
            low = mid + 1;
        }
    }
    return ans - x;
}
int a[507][507];
int main()
{
    runEratosthenesSieve(1000000);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
        cin >> a[i][j];
    }
    int MIN = 100000;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            if (!IsPrime(a[i][j]))
            {
                sum += Binary_search(a[i][j]);
            }
        }
        if (sum < MIN)MIN = sum;
    }
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (!IsPrime(a[i][j]))
            {
                sum += Binary_search(a[i][j]);
            }
        }
        if (sum < MIN)MIN = sum;
    }
    cout << MIN << endl;
}