//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<k;i++){
            mpp[arr[i]]++;
        }
        ans.push_back(mpp.size());
        int n=arr.size();
        for(int i=k;i<n;i++){
            mpp[arr[i-k]]--;
            if(mpp[arr[i-k]]==0)
            mpp.erase(arr[i-k]);
            mpp[arr[i]]++;
            ans.push_back(mpp.size());
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends