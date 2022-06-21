class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans;
        double mn(300.0), mx(0.0), mode;
        double sum = 0.0;
        
        int modecount = 0;
        int tc = accumulate(begin(count),end(count),0);
        int index1 = tc/2;
        int index2 = tc/2 + 1;
        int flag1(0), flag2(0);
        double first,second;
        //cout<<tc<<" ";
        double rr;
        for(int i = 0; i < 256; i++) {
            
            if(count[i] > 0) {
                mn = min(mn,(double)i);
                mx = max(mx,(double)i);
            }
            if(count[i] > modecount) {
                mode = (double)i;
                modecount = count[i];
            }
            if(i>0 and count[i]>0){
                
            rr = (double)count[i]/tc * i;
            //cout<<rr<<" ";
            sum += rr;}
            
            
            
            index1 -= count[i];
            if(index1 <=0 and !flag1) {
                 first = i;
                flag1 = 1;
            }
            index2 -= count[i];
            if(index2 <=0 and !flag2) {
                second = i;
                flag2= 1;
            }
            
        }
        //double mean = sum/double(tc);
        double median;
        if(tc %2 == 0) {
            median = (first+second)/2;
        }
        else median = second;
        ans = {mn,mx,sum,median,mode};
        return ans; 
        
        
    }
};