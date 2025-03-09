//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(ans.back()<arr[i]){
                ans.push_back(arr[i]);
            }
            else{
                int ind=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[ind]=arr[i];
            }
        }
        return ans.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends