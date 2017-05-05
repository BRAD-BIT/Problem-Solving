#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *sum = new int[n];
    for (int m = 0; m < n; m++)
    {
        sum[m] = 0;
    }
    string *word = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> word[i];
    }
    for (int j = 0; j < n; j++)
    {
        sum[j] = word[j].length();
    }
    for (int k = 0; k < n; k++)
    {
        if (sum[k]>10)
            cout << word[k][0] << sum[k] - 2 << word[k][sum[k] - 1] << endl;
        else
            cout << word[k] << endl;
    }
}