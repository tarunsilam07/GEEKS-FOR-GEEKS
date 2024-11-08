//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        int cnt=0;
        string add=s1;
        while(s1.size()<s2.size()){
            s1+=add;
            cnt++;
        }
        if (s1.find(s2) != std::string::npos)
        return cnt+1;
        
        s1+=add;
        if (s1.find(s2) != std::string::npos)
        return cnt+2;
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends