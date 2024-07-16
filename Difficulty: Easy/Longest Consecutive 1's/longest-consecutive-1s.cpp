//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    int maxConsecutiveOnes(int n)
    {
      string s="";
      for(int i=31;i>=0;i--)
      {
          int k=n>>i;
          if(k&1)
          s+="1";
          else s+="0";
      }
      int cnt=0;
      int maxi=0;
      for(int i=0;i<s.size();i++)
      {
         if(s[i]=='1')
         cnt++;
         maxi=max(cnt,maxi);
         if(s[i]=='0')
         cnt=0;
      }
      return maxi;
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends