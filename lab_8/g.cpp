#include <bits/stdc++.h>
#include <vector>
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
        if (cur_h == h_s * p_pow[i])
        {
            count++;
        }
    }
    return count;
}

int main(){
    string t; cin >> t;
    int n; cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        string s = "";
        int L, R;
        cin >> L;
        cin >> R;
        for (size_t i = L - 1; i < R; i++)
        {
            s += t[i];
        }
        cout << rabin_karp(t, s) << endl;
    }
}