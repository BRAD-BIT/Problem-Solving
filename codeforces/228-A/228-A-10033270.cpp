#include<iostream>
using namespace std;
int main()
{
    int a[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    int z = -1;
    int sum[] = { 0, 0, 0, 0 };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i]==a[i-1]||a[i]==a[i-2]||a[i]==a[i-3])break;
            if (a[i] == a[j])sum[i]++;
        }
    }
    /*cout << sum[0] << endl;
    cout << sum[1] << endl;
    cout << sum[2] << endl;
    cout << sum[3] << endl;*/
    if (sum[0] >= 1)sum[0]--;
    if (sum[1] >= 1)sum[1]--;
    if (sum[2] >= 1)sum[2]--;
    if (sum[3] >= 1)sum[3]--;
    int Sum = sum[0] + sum[1] + sum[2] + sum[3];
    cout << Sum;
}