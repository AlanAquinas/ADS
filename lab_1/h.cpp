#include <iostream>

using namespace std;

string isPrime(int n){
    if(n == 1){
        return "NO";
    }
    for(int i = 2; i*i <= n; i++){
        if(n%i==0){
            return "NO";
        }
    }
    return "YES";
}

int main(){
    int n;
    cin >> n;
    cout << isPrime(n);
}   