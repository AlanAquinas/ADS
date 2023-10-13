#include <iostream>

using namespace std;

int dic_bin_search(int arr[], int target, int size){
    int l = 0, r = size - 1;
    
    while(l <= r){
        int mid = l +(r - l)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if (arr[mid] < target){
            r = mid - 1;
        } else{
            l = mid + 1; 
        }
    }
    return -1;
}

int inc_bin_search(int arr[], int target, int size){
    int l = 0, r = size - 1;
    
    while(l <= r){
        int mid = l + (r - l)/2;
        if(arr[mid]==target){
            return mid;
        }
        if (arr[mid] < target){
            l = mid + 1; 
        } else{
            r = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k, m;
    cin >> k >> m;
    int b[k][m];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int x, y; bool pass = false;
        for (int j = 0; j < k; j++)
        {
            if(j % 2 == 0){
                x = dic_bin_search(b[j], a[i], m);
                y = j;
            }else{
                x = inc_bin_search(b[j], a[i], m);
                y = j;
            }
            if(x != -1){
                cout << y << " " << x << "\n";
                pass = true;
                break;
            }
        }
        if(pass == false) cout << -1 << "\n";
    }
}