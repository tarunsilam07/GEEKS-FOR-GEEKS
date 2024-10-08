//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int maxi=0;
        std::priority_queue<int>maxHeap;
        maxHeap.push(arr[0]);
        for(int i=1;i<arr.size();i++){
            int sum=arr[i]+maxHeap.top();
            if(sum>maxi)
            maxi=sum;
            maxHeap.push(arr[i]);
        }
        return maxi;
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
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends