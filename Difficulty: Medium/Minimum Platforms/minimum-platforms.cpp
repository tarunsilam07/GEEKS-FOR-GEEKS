//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        
    	sort(arr+0,arr+n);
    	sort(dep+0,dep+n);
    	int i=0;
    	int j=0;
    	int cnt=0;
    	int maxcnt=0;
    	while(i<n)
    	{
    	   if(arr[i]<=dep[j])
    	   
    	   {
    	       cnt=cnt+1;
    	       i=i+1;
    	   }
    	   else if(arr[i]>dep[j])
    	   {
    	       cnt=cnt-1;
    	       j=j+1;
    	   }
    	   maxcnt=max(cnt,maxcnt);
    	}
    	return maxcnt;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends