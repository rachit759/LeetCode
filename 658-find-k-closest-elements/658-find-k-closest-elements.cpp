class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();           // multiple approaches for this question 
                                      // binary search or priority queue
        int start = 0, end = n-1;
        
        while(end-start+1 > k) {
            
            if( abs(arr[start] - x) <= abs(arr[end] - x) ) end--;
            else start++;
                
        }
        return {arr.begin()+start, arr.begin()+end+1};
        
        
    }
};