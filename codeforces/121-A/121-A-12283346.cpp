#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>v;
void lucky(string s)
{
    if (s.length() == 11)return;
    if (s != "")v.push_back(stoll(s));
    lucky(s + '4');
    lucky(s + '7');
}
int main()
{
    lucky("");
    sort(v.begin(), v.end());
    int l, r; cin >> l >> r; int last = l; long long sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] >= l&&v[i] <= r)
        {
            sum += (v[i] - last + 1)*v[i];
            last = v[i]+1;
        }
        else
        if (v[i]>=r)
        {
            sum += (r - last + 1)*v[i]; break;
        }
    }
    cout << sum << endl;
}