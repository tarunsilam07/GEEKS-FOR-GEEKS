//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int evaluate(vector<string>& arr) {
        stack<int> st;
        for(string s: arr){
            if(s == "-" or s == "+" or s == "*" or s == "/"){
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();
                if(s == "-") st.push(x - y);
                else if(s == "+") st.push(x + y);
                else if(s == "*") st.push(x * y);
                else if(s == "/") st.push(x / y);
            }
            else st.push(stoi(s));
        }
        return st.top();
     }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends