#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int x = 256;

int rabin_karp(string s, string pattern) {
    int mod = INT_MAX;
    int m = pattern.length();
    int n = s.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int count = 0;

    for (int i = 0; i < m - 1; i++) {
        h = (h * x) % mod;
    }

    for (int i = 0; i < m; i++) {
        p = (x * p + pattern[i]) % mod;
        t = (x * t + s[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (s[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                count++;
            }
        }
        if (i < n - m) {
            t = (x * (t - s[i] * h) + s[i + m]) % mod;

            if (t < 0) {
                t = (t + mod);
            }
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> vec;
    vector<int> maket(s.size(), 0);

    for (int i = 0; i < n; i++) {
        string s1;
        cin >> s1;
        vec.push_back(s1);
    }

    for (int i = 0; i < n; i++) {
        int index_found = rabin_karp(s, vec[i]);
        for (int j = index_found; j < i + vec[i].size() - 1; j++) {
            maket[j] = 1;
        }
    }

    for (int i = 0; i < maket.size(); i++) {
        if (maket[i] != 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
