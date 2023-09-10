#include <iostream>
#include <string>
#include <deque>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    string str; cin >> str;
    map<char, int> added_votes, delete_votes;
    deque<int> dq;

    for (int i = 0; i < n; i++){
        dq.push_back(str[i]); 
        added_votes[dq[i]]++;
    }
    while(added_votes['K']>0 && added_votes['S']>0){
        if(delete_votes[dq.front()] > 0){
            added_votes[dq.front()]--;
            delete_votes[dq.front()]--;
            dq.pop_front();
        }else{
            if(dq.front() == 'S'){
                delete_votes['K']++;
            }else{
                delete_votes['S']++;
            }
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }

    if(added_votes['K'] != 0){
        cout << "KATSURAGI";
    }else cout << "SAKAYANAGI";

    return 0;
}
