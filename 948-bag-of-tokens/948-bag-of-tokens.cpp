class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        
        int n = token.size();
        
        if( n==1) return token[0]>power ? 0 : 1 ;
        
        sort(begin(token),end(token));
        
        int score = 0;
        
        int i = 0;
        int j = n-1;
        int maxi =0;
        while(i <= j) {
            
            if(token[i]<=power) {
                score +=1;
                power-=token[i];
                i++;
            }
            else if (token[i]>power and score ==0) break;
            else  {
                if (score>0) {
                power+=token[j];
                score-=1;
                j--;
                }
            }
            
            maxi= max(maxi,score);
        } 

        return maxi;
    }
};