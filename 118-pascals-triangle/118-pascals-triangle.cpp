class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> pas;
        
        for(int i=0;i<n;i++)
        {
            int icj=1;
            vector<int> v;
            for(int j=0;j<=i;j++)
            {
                 v.push_back(icj);
                int icjp1= icj * (i-j)/(j+1);
                icj=icjp1;
            }
            pas.push_back(v);
        }
        return pas;
    }
};