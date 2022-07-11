class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int> &A, int B) {
            vector<int> ans;
            deque<int> l;
            int i = 0;
            int j = 0;
            while (j < A.size()) {
                while (l.size() > 0 and l.back() < A[j]) 
                    l.pop_back();

                l.push_back(A[j]);
                 if (j - i + 1 == B) {
                    ans.push_back(l.front());
                    if (l.front() == A[i])
                        l.pop_front();
                    i++;
                }
                j++;
            }
            return ans;
        }
};