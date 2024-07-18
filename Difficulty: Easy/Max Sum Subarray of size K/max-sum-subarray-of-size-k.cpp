//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        
        long long sum=0;
        long long maxsum=0;
        for(int i=0;i<k;i++)
        sum+=arr[i];
        maxsum=sum;
        int left=0;
        int right=k;
        while(right<n)
        {
            sum+=arr[right];
            sum-=arr[left];
            if(sum>maxsum)
            {
                maxsum=sum;
            }
            right++;
            left++;
        }
        return maxsum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends