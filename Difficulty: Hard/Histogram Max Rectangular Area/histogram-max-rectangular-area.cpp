//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        
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
    vector<long long> NextSmallerElement(long long heights[],int n)
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
    vector<long long> PreviousSmallerElement(long long heights[],int n)
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

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends