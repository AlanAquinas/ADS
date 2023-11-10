#include <bits/stdc++.h>
using namespace std;
void print(vector<char> &v, int n){
    for(int i = 0; i < n; i++){
        cout << v[i];
    }
}

int partition(vector<char> & v, int low, int high){
    char pivot = v[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}


void quickSort(vector<char> & v, int low, int high){
    if(low < high){
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}


int main(){
    string s; cin >> s;
    vector<char> alhp;
    for(int i = 0; i < s.size(); i++){
        alhp.push_back(s[i]);
    }
    quickSort(alhp, 0, alhp.size() - 1);
    print(alhp, alhp.size());
}