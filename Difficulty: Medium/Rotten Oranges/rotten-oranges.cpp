//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=(int)mat.size();
        int m=(int)mat[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,(int)(1e9)));
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==2)
                {
                    dp[i][j]=0;
                    pq.push({0,{i,j}});
                }
            }
        }
        while(!pq.empty())
        {
            auto it=pq.top();
            int d=it.first;
            int i=it.second.first;
            int j=it.second.second;
            pq.pop();
            if(d!=dp[i][j])
            continue;
            int a[]={-1,1,0,0};
            int b[]={0,0,-1,1};
            
            for(int k=0;k<4;k++)
            {
                int x=a[k]+i;
                int y=b[k]+j;
                if(x>=0 && y>=0 && x<n && y<m && (mat[x][y]==1))
                {
                    if(dp[x][y]>(d+1))
                    {
                        dp[x][y]=d+1;
                        pq.push({dp[x][y],{x,y}});
                    }
                }
            }
        }
        int minm=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    if(dp[i][j]==(int)(1e9))
                    return -1;
                    minm=max(minm,dp[i][j]);
                }
                
                
            }
        }
        return minm;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends