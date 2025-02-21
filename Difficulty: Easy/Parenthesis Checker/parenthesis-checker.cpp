//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0){
                st.push(s[i]);
            }
            else if(s[i]=='[' || s[i]=='{' || s[i]=='(')
            st.push(s[i]);
            else{
                char top=st.top();
                if(s[i]=='}' && top=='{' || s[i]==']' && top=='[' || s[i]==')' && top=='(')
                st.pop();
                else return false;
            }
        }
        if(st.size()!=0)
        return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends