//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        // 1 4 5 6 9  // 1 1 3
        // 2 3 4 4 8  // 4 5 6
        sort(a,a+n);
        sort(b,b+n);
        long long sum=0;
        int index=n-1;
        for(long long i=0;i<n;i++)
        {
           sum+=a[i]*b[index];
           index--;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}
// } Driver Code Ends