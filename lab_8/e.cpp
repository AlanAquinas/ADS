#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ll> hashes;
    for (int i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        hashes.push_back(k);
    }
    for (size_t i = 0; i < n; i++)
    {
        if (i)
        {
            cout << char((hashes[i] - hashes[i - 1]) / pow(2, i) + 97);
        }
        else
        {
            cout << char(hashes[i] / pow(2, i) + 97);
        }
    }
}