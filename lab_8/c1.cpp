#include<bits/stdc++.h>
#include<vector>
#include<set>

using namespace std;

#define ll long long
set<int> st;

vector<int> rabin_karp(string t, string s){
    int n = t.size();
    vector<int> vec;
    // считаем все степени р
    const int p = 31;
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (size_t i = 1; i < n; i++)
    {
        p_pow[i] = p_pow[i - 1] * p;
    }

    // считаем хэши от всех префиксов строки Т
    vector<ll> h (t.length());
    for (size_t i = 0; i < t.length(); i++)
    {
        h[i] = (t[i] - 'a' + 1) * p_pow[i];
        if(i) h[i] += h[i - 1];
    }

    // считаем хэш от сторки s
    ll h_s = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        h_s += (s[i] - 'a' + 1) * p_pow[i];
    }
    
    // перебираем все подстроки T длины |S| и сравниваем их
    for (size_t i = 0; i + s.length() - 1 < t.length(); i++)
    {
        ll cur_h = h[i + s.length() - 1];
        if(i) cur_h -= h[i-1];
        // приводим хэши к одной степени и сравниваем
        if (cur_h == h_s * p_pow[i])    
        {
            vec.push_back(i);
        }   
    }
    return vec;
}

int main(){
    string s; cin >> s;
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        string t; cin >> t;
        vector<int> vec = rabin_karp(s, t);

        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < t.size(); j++)
            {
                st.insert(vec[i]+j);
            }
        }
        
    }
    if (s.size() == st.size()) cout << "YES";
    else cout << "NO";
}