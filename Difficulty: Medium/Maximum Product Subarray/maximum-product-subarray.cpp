//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        if(n==0){
            return 0;
        }
        int maxP = arr[0];
        int minP = arr[0];
        int prodMax = arr[0];
        for(int i = 1; i < n; i++){
            int temp = maxP;
            if(arr[i]<0){
                maxP = minP;
                minP = temp;
            }
            maxP = max(arr[i], maxP*arr[i]);
            minP = min(arr[i], minP*arr[i]);
            prodMax = max(maxP,prodMax);
        }
        return prodMax;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends