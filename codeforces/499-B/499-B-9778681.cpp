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
struct word
{
    string word1;
    string word2;
};
int main()
{
    int n, m;
    cin >> n >> m;
    word *a = new word[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].word1 >> a[i].word2;
    }
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s == a[j].word1)
            {
                if (s.length() <= a[j].word2.length())cout << s << " ";
                else cout << a[j].word2 << " ";
                break;
            }
        }
    }
    cout << endl;
}