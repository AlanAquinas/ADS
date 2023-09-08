#include <iostream>

using namespace std;

bool isPrime(int num){
    for(int i = 2; i*i <= num; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

int findNthTermPrime(int num){
    int counter = 0;
    int prime;
    for (int i = 2; num > counter; i++)
    {
        if(isPrime(i)){
            counter++;
            prime = i;
        }
    }
    return prime;
}

int main(){
    int n;
    cin >> n;
    cout << findNthTermPrime(n);
}