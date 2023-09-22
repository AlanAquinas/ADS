#include <bits/stdc++.h>
using namespace std;
bool Prime(int m){
    if(m == 0 || m == 1) return false;
    for(int i = 2; i * i <= m; i++){
        if(m % i == 0) return false;
    }
    return true;
}
int main(){
    int m; cin >> m;
    vector<int> a, b;
    a.push_back(0);
    for(int i = 0; i < 100000; i++){
        if(Prime(i)){
            a.push_back(i);
        }
    }
    for(int i = 0; i < a.size(); i++){
        if(Prime(i)){
            b.push_back(a[i]);
        }
    }
 
    cout << b[m-1];
}