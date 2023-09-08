#include <iostream>
#include <stack>

using namespace std;

int main() 
{
    int n; cin >> n;
    int b[n];
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        while(!st.empty() && (b[i] < st.top())){
            st.pop();
        }
        if(st.empty()){
            cout << -1 << " ";
        } else{
            cout << st.top() << " ";
        }
        st.push(b[i]);
    }
    return 0;
}
