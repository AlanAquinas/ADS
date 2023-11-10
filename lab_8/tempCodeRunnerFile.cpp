#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

long long rabin_karp(string s){
    const int p = 11;
    const int m = 1e9 + 7;
    long long hash_value = 0;
    long long p_pow = 1;
    for(char c : s){
        hash_value = (hash_value + (c - 47) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;

}

int main(){
    int n, counter = 0, cin >> n;
    int sx = 2 * n;
    vector<string> vec;
    unordered_map<string, long long> m;
    string t;
    while(sx--){
        cin >> t;
        vec.push_back(t);
        m[t] = -1;
    }

    for(auto i : vec){
        if (counter - n == 0) return 0;
        if (m[to_string(rabin_karp(i))] == -1)
        {
            cout << "Hash of string " << '"' << i << '"' << ' is ' << rabin_karp[i] << endl;
            counter++;
        }
                
    }
}