#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num){
    for(int i = 2; i*i <= num; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

int findNthSuperprime(int n) {
    vector<int> superprimes;
    int candidate = 2;

    while (superprimes.size() < n) {
        if (isPrime(candidate)) {
            superprimes.push_back(candidate);
        }
        candidate++;
    }

    return superprimes.back(); // Return the nth superprime
}

int main(){
    int n;
    cin >> n;
    cout << findNthSuperprime(n);
}