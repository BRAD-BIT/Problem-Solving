#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int sumA = 0;
    int suma = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (islower(s[i]))
        {
            suma++;
        }
        else sumA++;
    }
    if (sumA == suma || suma>sumA)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!islower(s[i]))
            {
                s[i]=tolower(s[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (islower(s[i]))
            {
                s[i]=toupper(s[i]);
            }
        }
    }
    cout << s;
    
}
/*stringstream ss;
ss << int name;
string string name = ss.str();*/


//bool comp(structname a, structname b)
//{
//  return a.struct1 < b.struct2; or >for desc. or b to sort 3la b
//}andeha fe al sort