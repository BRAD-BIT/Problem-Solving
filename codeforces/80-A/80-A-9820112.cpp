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
int a[25];
void runEratosthenesSieve(int upperBound)
{
    int v = 0;
    int upperBoundSquareRoot = (int)sqrt((double)upperBound);
    bool *isComposite = new bool[upperBound + 1];
    for (int i = 0; i <= upperBound; i++)isComposite[i] = false;
    for (int m = 2; m <= upperBoundSquareRoot; m++)
    {if (!isComposite[m]){a[v] = m; v++;for (int k = m * m; k <= upperBound; k += m){isComposite[k] = true;}}}
    for (int m = upperBoundSquareRoot; m <= upperBound; m++)
    {if (!isComposite[m]){ a[v] = m; v++; }}
    delete[] isComposite;
}
int main()
{
    runEratosthenesSieve(100); int n, m; cin >> n >> m;
    for (int i = 0; i < 24; i++)
    {
        if (n == a[i] && m == a[i + 1]){ cout << "YES" << endl; return 0; }
    }
    cout << "NO" << endl;
}