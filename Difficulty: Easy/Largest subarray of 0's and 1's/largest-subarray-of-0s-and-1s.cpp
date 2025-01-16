//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n=arr.size(),sum=0,maxlen=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)if(arr[i]==0)arr[i]=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0)maxlen=max(maxlen,i+1);
            if(mp.find(sum)!=mp.end()){
                maxlen=max(maxlen,i-mp[sum]);
            }
            if(mp.find(sum)==mp.end())mp[sum]=i;
        }
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends