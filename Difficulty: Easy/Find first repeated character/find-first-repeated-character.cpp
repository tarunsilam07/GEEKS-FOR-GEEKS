//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    unordered_map<char,int>mpp;
    string k="-1";
    for(int i=0;i<s.size();i++)
    {
        mpp[s[i]]++;
        if(mpp[s[i]]>1)
        {
            k=s[i];
            break;
        }
    }
    return k;
}