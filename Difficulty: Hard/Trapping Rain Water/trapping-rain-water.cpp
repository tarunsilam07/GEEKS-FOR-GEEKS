//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &height) {
       int n=height.size();
       long long left=0;
       long long right=n-1;
       long long maxleft=0;
       long long maxright=0;
       long long ans=0;
       while(left<=right)
       {
        if(height[left]<=height[right])  // 1+1+2+1+1
        {
            if(height[left]>=maxleft) 
            maxleft=height[left];
            else
            ans+=maxleft-height[left];
            left++;
        }
        else
        {
            if(height[right]>=maxright)
            maxright=height[right];
            else
            ans+=maxright-height[right];
            right--;
        }
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends