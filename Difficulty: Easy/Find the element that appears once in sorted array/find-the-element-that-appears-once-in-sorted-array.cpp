//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
            {
                ans=arr[mid];
                break;
            }
            if(mid%2==1)
            {
                if(arr[mid]==arr[mid-1])
                {
                    low=mid+1;
                }
                else if(arr[mid]!=arr[mid-1])
                {
                    high=mid-1;
                }
            }
            else
            {
               if(arr[mid]==arr[mid+1])
               {
                   low=mid+1;
               }
               else high=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends