#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> boris, nursik;
    int k;
    int long counter = 0;

    for(int i = 0; i < 5; i++){
        cin >> k;
        boris.push_back(k);
    }
    for(int i = 0; i < 5; i++){
        cin >> k;
        nursik.push_back(k);
    }
    while(!boris.empty() && !nursik.empty()){
        if(counter == 1000000){
            cout << "blin nichya";
            return 0;
        }
        int cur_b = boris.front();
        int cur_n = nursik.front();
        if(cur_b==0 && cur_n==9){
            boris.pop_front();
            nursik.pop_front();
            boris.push_back(0);
            boris.push_back(9);
            counter++;

        }else if(cur_b==9 && cur_n==0){
            boris.pop_front();
            nursik.pop_front();
            nursik.push_back(9);
            nursik.push_back(0);
            counter++;
        }else if(cur_b>cur_n){
            boris.pop_front();
            nursik.pop_front();
            boris.push_back(cur_b);
            boris.push_back(cur_n);
            counter++;
        }else{
            boris.pop_front();
            nursik.pop_front();
            nursik.push_back(cur_b);
            nursik.push_back(cur_n);
            counter++;
        }
    }
    if(boris.empty()){
        cout << "Nursik " << counter;
    }else{
        cout << "Boris " << counter;
    }
    return 0;
}