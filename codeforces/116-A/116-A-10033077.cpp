#include<iostream>
using namespace std;
int main()
{
    int n;
    int now;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int j = 0; j < n; j++)
    {
        if (j == 0)
        {
            now = b[j];
            max = now;
        }
        else
            now = now - a[j] + b[j];
        if (now>max)max = now;
    }
    cout<< max;

}