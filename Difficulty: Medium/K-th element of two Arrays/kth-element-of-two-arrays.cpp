//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
      int n=arr1.size();
      int m=arr2.size();
      if(n>m && n!=0){
        return kthElement(arr2,arr1,k);
      }
      int low=max(0,k-m);
      int high=min(k,n);
      int left=k;
      while(low<=high)
      {
          int mid1=low+(high-low)/2;
          int mid2=left-mid1;
          int l1=INT_MIN; int l2=INT_MIN;
          int r1=INT_MAX; int r2=INT_MAX;
          if(mid1<n) r1=arr1[mid1];
          if(mid2<m) r2=arr2[mid2];
          if(mid1-1>=0) l1=arr1[mid1-1];
          if(mid2-1>=0) l2=arr2[mid2-1];
          if(l2<=r1 && l1<=r2)
          {
              return max(l1,l2);
          }
          else if(l1>r2) high=mid1-1;
          else low=mid1+1;
      }
      return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends