//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
        for(int i=0;i<patt.size();i++)
        {
            hash2[patt[i]-'a']+=1;
        }
        
        for(int i=0;i<str.size();i++)
        {
            if(hash2[str[i]-'a']>0)
            return i;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

// } Driver Code Ends