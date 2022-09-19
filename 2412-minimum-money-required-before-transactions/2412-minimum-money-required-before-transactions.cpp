class Solution {
public:
    long long minimumMoney(vector<vector<int>>& t) {
        
        int n = t.size();
        long long loss = 0;
        int maxa = 0;
        for(int i = 0; i < n; i++) {
            if(t[i][0] > t[i][1]) {
                loss += t[i][0] -t[i][1];
                maxa = max(maxa,t[i][1]);
            }
            else maxa = max(maxa,t[i][0]);
        }
        
        return loss + (long long)maxa;
    }
};