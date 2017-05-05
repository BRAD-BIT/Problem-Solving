#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
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
using namespace std;
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")0
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
int main()
{
    runEratosthenesSieve(2000);
    vector<int>sum;
    for (int i = 0; i < prime.size()-1; i++)
    {
        if (IsPrime(prime[i] + prime[i + 1] + 1))sum.push_back(prime[i] + prime[i + 1]+1);
    }
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < sum.size() - 1; i++)
    {
        int d = sum[i];
        if (sum[i] <= n)ans++;
        else break;
    }
    if (ans >= k)cout << "YES\n"; else cout << "NO\n";
}