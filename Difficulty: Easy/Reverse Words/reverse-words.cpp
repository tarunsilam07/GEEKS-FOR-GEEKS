//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
       int n=s.size();
       reverse(s.begin(),s.end());
       s.insert(s.end(),'.');
       int i=0;
       for(int j=0;j<=n;j++)
       {
           if(s[j]=='.')
           {
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
               
           }
       }
       s.pop_back();
       return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends