//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void sums(vector<int>&arr,int n,int index,int sum,vector<int>&ds)
  {
      if(index==n)
      {
          ds.push_back(sum);
          return;
      }
      sums(arr,n,index+1,sum+arr[index],ds);
      sums(arr,n,index+1,sum,ds);
  }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>ds;
        sums(arr,n,0,0,ds);
        sort(ds.begin(),ds.end());
        return ds;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends