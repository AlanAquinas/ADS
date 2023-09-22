#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    vector<string>::iterator ip;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    auto it = unique(v.begin(), v.end());

    v.resize(distance(v.begin(), it));
    cout << "All in all: " << v.size() << '\n';
    cout << "Students: \n";
    for (it = v.begin(); it!=v.end(); ++it)
        cout << *it << '\n';
}