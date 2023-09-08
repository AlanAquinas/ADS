#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    stack<char> stack1, stack2;
    for (int i = 0; i < s1.length(); i++) {
        char s = s1[i];
        if (s != '#') {
            stack1.push(s);
        } else if (!stack1.empty()) {
            stack1.pop();
        }
    }
    for (int i = 0; i < s2.length(); i++) {
        char s = s2[i];
        if (s != '#') {
            stack2.push(s);
        } else if (!stack2.empty()) {
            stack2.pop();
        }
    }

    if(stack2==stack1){
        cout << "Yes";
    }else{
        cout << "No";
    }
}