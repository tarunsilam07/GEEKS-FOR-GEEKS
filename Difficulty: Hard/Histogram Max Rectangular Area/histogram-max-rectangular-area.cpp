//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &heights) {
        int n=heights.size();
        vector<long long>next(n);
        next=NextSmallerElement(heights,n);
        vector<long long>prev(n);
        prev=PreviousSmallerElement(heights,n);
        long long area=-1;
        for(long long i=0;i<n;i++)
        {
            long long l=heights[i];
            if(next[i]==-1)
            next[i]=n;
            long long b=next[i]-prev[i]-1;
            long long new_area=l*b;
            area=max(area,new_area);
        }
        return area;
    }
    vector<long long> NextSmallerElement(vector<int> &heights,int n)
    {
        stack<long long>st;
        st.push(-1);
        vector<long long>ans(n);
        for(long long i=n-1;i>=0;i--)
        {
            long long curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr)
            st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<long long> PreviousSmallerElement(vector<int> &heights,int n)
    {
        stack<long long>st;
        st.push(-1);
        vector<long long>ans(n);
        for(long long i=0;i<n;i++)
        {
            long long curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr)
            st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends