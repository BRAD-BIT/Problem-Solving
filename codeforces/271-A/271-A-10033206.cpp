#include<iostream>
#include<string>
#include<sstream>
using namespace std;
bool isdistict(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        for (int j = i + 1; j < x.length(); j++)
        {
            if (x[i] == x[j])return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    while (true)
    {
        n = n + 1;
        stringstream ss;
        ss << n;
        string x = ss.str();

        if (isdistict(x))
        {
            cout << n;
            break;
        }
    }
}