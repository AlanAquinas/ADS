#include <iostream>
#include <deque>
using namespace std;

int main () {

    char s;
    int x;
    bool b = true;
    deque<int> dq;
    while (b) {
        cin >> s;

        if (s == '+') {
            cin >> x;
            dq.push_front(x);
        }
        if (s == '-') {
            cin >> x;
            dq.push_back(x);
        }
        if (s == '*') {
            if (dq.empty()) {
                cout << "error" <<endl;
            }
            else {
            cout << dq.front() + dq.back() << endl;
            if (!dq.empty()) dq.pop_front();
            if (!dq.empty()) dq.pop_back();
        }

        }
        if (s == '!') {
            b = false;
        }
    }
}