#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<char>& v, int low, int high) {
    int pivot = v[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return i+1;
}

void quick_sort(vector<char>& v, int low, int high){
    if (low < high)         
    {
        int pi = partition(v, low, high);

        quick_sort(v, low, pi - 1);
        quick_sort(v, pi + 1, high);
    }
}

int main(){
    int n; cin >> n;
    string str; cin >> str;

    vector <char> vowels;
    vector <char> consonants;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' ||str[i] == 'i' ||str[i] == 'u' ||str[i] == 'o')
        {
            vowels.push_back(str[i]);
        } else {
            consonants.push_back(str[i]);
        }
    }

    quick_sort(vowels, 0, vowels.size() - 1);
    quick_sort(consonants, 0, consonants.size() - 1);

    for (int i = 0; i < vowels.size(); i++)
    {
        cout << vowels[i];
    }
    for (int i = 0; i < consonants.size(); i++)
    {
        cout << consonants[i];
    }
    
}