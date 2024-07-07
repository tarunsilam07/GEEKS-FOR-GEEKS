//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &mat, int n, int m)
        {
            int maxi=INT_MIN;
            int ans=-1;
            for(int i=0;i<n;i++)
            {
                int cnt=helper(i,m,mat);
                if(cnt>maxi)
                {
                    maxi=cnt;
                    ans=i;
                }
            }
            return ans;
        }
        int helper(int n,int m,vector<vector<int>>&mat)
        {
            int low=0;
            int high=m-1;
            int index=m;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(mat[n][mid]>=1)
                {
                    index=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }
            return m-index;
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends