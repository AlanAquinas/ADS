#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int rabin_karp(string t, string s)
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
        if (cur_h == h_s * p_pow[i]) count++;
    }
    return count;
}

int main(){
    while (true)
    {
        int n; cin >> n;
        if(n == 0) break;
        vector<string> patterns;
        for (size_t i = 0; i < n; i++)
        {
            string s; cin >> s;
            patterns.push_back(s);
        }

        string t; cin >> t;
        vector<int> count_patterns(n);
        for (size_t i = 0; i < n; i++)
        {
            count_patterns[i] = rabin_karp(t, patterns[i]);
        }

        int max_count = *max_element(count_patterns.begin(), count_patterns.end());

        cout << max_count << endl;

        for (size_t i = 0; i < count_patterns.size(); i++)
        {
            if (count_patterns[i] == max_count) cout << patterns[i] << endl;
        }
    }
}