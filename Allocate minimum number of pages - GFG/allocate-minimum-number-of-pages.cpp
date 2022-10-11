// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool ispossible(int a[], int M, int mid,int N)
    {
        int studentcount = 1;
        int pages = 0;
        for(int i=0;i<N;i++)
        {
            if(pages + a[i] <= mid)
            {
                pages+=a[i];
            }
            else
            {
                studentcount++;
                 if(studentcount>M)
              return false;
            
                pages = a[i];
            }
           
        }
        
        return true;
        
    }
    int findPages(int arr[], int N, int M) 
    {
        
        if(M>N) return -1;
        int low = arr[0];
        int high =0;
        for(int i=0;i<N;i++)
        {
            low = max(low,arr[i]);
            high+=arr[i];
        }
        
        int ans =-1;
        
        while(low<=high)
        {
            int mid = (low+high) / 2;
            if(ispossible(arr,M,mid,N))
            { 
                ans = mid;
                high = mid -1;
            }
            else
                low = mid + 1;
            
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends