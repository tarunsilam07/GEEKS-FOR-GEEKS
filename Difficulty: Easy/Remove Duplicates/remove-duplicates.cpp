//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string s) 
	{
	    unordered_map<char,int>mpp;
	    string l="";
	    for(int i=0;i<s.size();i++)
	    {
	        char ch=s[i];
	        if(mpp[ch]==0)
	        l+=ch;
	        mpp[ch]++;
	        
	    }
	    return l;
	}
};

//{ Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends