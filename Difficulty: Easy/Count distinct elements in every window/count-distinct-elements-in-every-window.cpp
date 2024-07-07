//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        vector<int>ans;
        int l=0;
        int r=k-1;
        unordered_map<int,int>mpp;
        for(int i=l;i<=r;i++)
        {
            mpp[arr[i]]++;
        }
        ans.push_back(mpp.size());
        r=k;
        while(r<n)
        {
           mpp[arr[r]]++;
           mpp[arr[l]]--;
           if(mpp[arr[l]]<1)
           mpp.erase(arr[l]);
           ans.push_back(mpp.size());
           r++;
           l++;
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends