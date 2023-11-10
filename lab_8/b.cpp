#include <bits/stdc++.h>

using namespace std;

#define x 256


int get_count(string s, string pattern){
    int mod = INT_MAX;
    int m = pattern.length();
    int n = s.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int count = 0;

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * x) % mod;
    }

    for (int i = 0; i < m; i++)
    {
        p = (x * p + pattern[i]) % mod;
        t = (x * t + s[i]) % mod;
    }
    
    for (int i = 0; i < n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (s[i + j] != pattern[j])
                {
                    break;
                }
            }
            if (j == m)         
            {
                count++;
            }
        }
        if (i < n - m)
        {
            t = (x * (t - s[i] * h) + s[i + m]) % mod;

            if (t < 0)
            {
                t = (t + mod);
            }
        }
    }
    return count;
}

int main(){
    string s1, s2, pattern;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, pattern);
    int count1 = get_count(s1, pattern);
    int count2 = get_count(s2, pattern);
    cout << min(count1, count2);
    return 0;
}