class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int freq[100000+1]={0};
        for(int &e :costs)
            freq[e]++;
        
        int cnt=0;
        for(int i=1;i<=100000;++i)
        {
            if(freq[i])
            {
                int curr=1LL*i*freq[i];
                if(curr<=coins)
                {
                    cnt+=freq[i];
                    coins-=curr;
                }
                else
                {
                    cnt+=(coins/i);
                    break;
                }
            }
        }
        return cnt;
    }
};