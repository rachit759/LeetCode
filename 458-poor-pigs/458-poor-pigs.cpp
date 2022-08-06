class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int shots = minutesToTest/minutesToDie + 1;
        int pigs  = 0;
        while(pow(shots,pigs) < buckets) pigs += 1;
        return pigs;
        
        
        
    }
};