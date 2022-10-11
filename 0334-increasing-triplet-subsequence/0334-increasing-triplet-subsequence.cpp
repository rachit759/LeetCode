class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3) return false;
        
        int low, mid;
        low = mid = INT_MAX;
        
        for(int i = 0; i < n; i++) {

            if(nums[i] > mid) return true;
            if(nums[i] < low) low = nums[i];
            else if (nums[i] > low and nums[i] < mid) mid = nums[i];
        }
        
        return false;
        
        
    }
};




// To solve this question, we can use a greedy approach. First, note that if our array has less than 3 elements, it is not possible to have a strictly increasing subsequence of size 3, since we have less than 3 elements to even choose from.

// Now, let's keep track of the lowest and middle element in our subsequence as we go along. First, note that we are choosing these elements such that the middle element will always be greater than the lowest element. Now, if we find an element such that the element is greater than the middle element, we know that we have found an increasing subsequence of length 3. This is because the low < mid < high, which is guaranteed by how we are choosing our elements, and the index of low < index of mid < index of high.

// Otherwise, consider the updates we can perform to our low and mid. If the current element is smaller than our lowest element, then we have found a new lowest element, so we can update our lowest element. We do not update our mid to reflect this, even though the element stored in low now has a higher index than the element stored at mid, which violates the condition that the elements must be in order. The reason why is that the mid element still has information about elements which are less than it in the array. If we ever find an element that is greater than mid before finding an element that is between low and mid, we know that a subsequence exists, regardless of the value of low, since mid was greater than low and "ordered" at some point during our traversal.

// In another case, if we find an element that is greater than our low but less than our mid, we update our mid to be this element, since we want to store the smallest element at any point that provides us with the highest chance of finding an element greater than it.

// We can illustrate this with an example. Let's say our array is [2,3,1,4,5]. After our first iteration, we will update low = 2. After our second iteration, we will update mid = 3. After the third iteration, we reach an interesting junction in the traversal. Note that low = 1 will be updated, but mid = 3 remains, and will not change. Now, on the fourth iteration, we see that 4 > mid = 3, so we return true. This highlights why we do not update mid when we change low, but instead only proceed greedily. Even if we don't find a new value for mid after finding a new value for low, we know that at some point earlier (aka when low = 2 and mid = 3), mid exceeded low and was ordered correctly; otherwise, it would not have its present value. As a result, we can confidently say that there is some increasing subsequence in the array, and return since we have found an element that exceeded mid.

// The space complexity of this solution is constant, and the time complexity of this solution is linear.