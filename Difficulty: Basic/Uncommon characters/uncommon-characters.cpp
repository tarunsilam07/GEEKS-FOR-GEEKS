//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            vector<int>hash1(26,0);
            vector<int>hash2(26,0);
            string s="";
            for(int i=0;i<A.size();i++)
            hash1[A[i]-'a']+=1;
            for(int i=0;i<B.size();i++)
            hash2[B[i]-'a']+=1;
            for(int i=0;i<26;i++)
            {
                if(hash1[i]>0 && hash2[i]>0)
                {
                    
                }
                else if((hash1[i]==0 && hash2[i]>=1) || (hash2[i]==0 && hash1[i]>=1))
                s+='a'+i;
            }
            if(s=="")
            return "-1";
            return s;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends