//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int total1=1;
        int total2=1;
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                total2*=arr[i];
            }
            total1*=arr[i];
            if(arr[i]==0)
            cnt++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                ans.push_back(total1/arr[i]);
            }
            else if(arr[i]==0 && cnt<=1){
                ans.push_back(total2);
            }
            else ans.push_back(0);
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends