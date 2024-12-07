//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to merge two halves and count cross-inversions
    long long mergeAndCount(vector<int> &arr, int left, int mid, int right) {
        int n1 = mid - left + 1; // Size of left half
        int n2 = right - mid;    // Size of right half
        
        vector<int> leftArr(n1), rightArr(n2);
        for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
        for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];
        
        int i = 0, j = 0, k = left;
        long long inversions = 0;
        
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                inversions += (n1 - i); // All remaining elements in leftArr are greater than rightArr[j]
            }
        }
        
        while (i < n1) arr[k++] = leftArr[i++];
        while (j < n2) arr[k++] = rightArr[j++];
        
        return inversions;
    }
    
    // Function to recursively count inversions using merge sort
    long long mergeSortAndCount(vector<int> &arr, int left, int right) {
        long long inversions = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            // Count inversions in left and right halves
            inversions += mergeSortAndCount(arr, left, mid);
            inversions += mergeSortAndCount(arr, mid + 1, right);
            
            // Count cross-inversions during the merge step
            inversions += mergeAndCount(arr, left, mid, right);
        }
        return inversions;
    }
    
    // Main function to count inversions
    int inversionCount(vector<int> &arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends