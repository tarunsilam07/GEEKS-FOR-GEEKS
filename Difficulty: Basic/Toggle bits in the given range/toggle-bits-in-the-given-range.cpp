//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int toggleBits(int n , int l , int r) {
        for(int i=l;i<=r;i++)
        {
            n=n^(1<<(i-1));
        }
        return n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,l,r;
        
        cin>>n>>l>>r;

        Solution ob;
        cout << ob.toggleBits(n,l,r) << endl;
    }
    return 0;
}
// } Driver Code Ends