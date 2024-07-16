//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> a, int n, vector<int> b, int m) 
    {
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        mpp[a[i]]++;
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            if(mpp.find(b[i])!=mpp.end())
            {
                while(mpp[b[i]]!=0)
                {
                    ans.push_back(b[i]);
                    mpp[b[i]]--;
                }
                if(mpp[b[i]]==0)
                mpp.erase(b[i]);
            }
        }
        for(auto it:mpp)
        {
            while(it.second>0)
            {
                ans.push_back(it.first);
                it.second--;
            }
        }
        return ans;
        
    } 
};

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 

// } Driver Code Ends