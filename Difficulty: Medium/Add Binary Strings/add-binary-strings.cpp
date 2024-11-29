//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string ans = "";
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int i = 0,j = 0, carry = 0;
        while(i<s1.size() || j< s2.size() || carry){
            int sum = (i<s1.size() ? s1[i]-'0' : 0) + (j<s2.size() ? s2[j]-'0' : 0) + carry;
            carry = sum/2;
            sum = sum%2;
            ans+=(sum+'0');
            i++;
            j++;
        }
        reverse(ans.begin(),ans.end());
        while(ans.size() && ans[0] == '0'){
            ans.erase(ans.begin());
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends