//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.size()!=str2.size()) return false;
        if(str1.size()==1)
        {
            if(str1[0]==str2[0])
            return true;
            else return false;
        }
        string l=str2;
        int n=l.size();
        reverse(l.begin()+(n-2),l.end());
        reverse(l.begin(),l.end()-2);
        reverse(l.begin(),l.end());
        string k=str2;
        reverse(k.begin(),k.begin()+2);
        reverse(k.begin()+2,k.end());
        reverse(k.begin(),k.end());
        if(str1==l || str1==k)
        return true;
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends