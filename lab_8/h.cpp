#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

bool rabin_karp(string t, string s)
{
    vector<int> vec;
    int n = t.size();
    int count = 0;
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    const int p = 31;
    for (size_t i = 1; i < n; i++)
    {
        p_pow[i] = p_pow[i - 1] * p;
    }

    vector<ll> h(n);
    for (size_t i = 0; i < n; i++)
    {
        h[i] = (t[i] - 'a' + 1) * p_pow[i];
        if (i)
            h[i] += h[i - 1];
    }

    ll h_s = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        h_s += (s[i] - 'a' + 1) * p_pow[i];
    }

    for (size_t i = 0; i + s.size() - 1 < n; i++)
    {
        ll cur_h = h[i + s.size() - 1];
        if (i)
            cur_h -= h[i - 1];
        if (cur_h == h_s * p_pow[i])
            return 1;
    }
    return 0;
}

string longest_common(vector<string> strs)
{
    string smallestString = *min_element(strs.begin(), strs.end());
    for (int i = smallestString.size() - 1; i > 0; i--)
    {
        for (int j = 0; j + i< smallestString.size(); j++)
        {
            bool equal = true;
            string s = smallestString.substr(j, i + 1);
            for (size_t k = 0; k < strs.size(); k++)
            {
                if (!rabin_karp(strs[k], s))
                {
                    equal = false;
                    break;
                }
            }
            if (equal)
                return s;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> strs;
    for (size_t i = 0; i < n; i++)
    {
        string k;
        cin >> k;
        strs.push_back(k);
    }
    cout << longest_common(strs);
}