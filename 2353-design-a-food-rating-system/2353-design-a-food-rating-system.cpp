class cmp {
public :
     bool operator()(const pair<int,string> &a, const pair<int,string> &b) const {
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};


class FoodRatings {
public:
    
    unordered_map<string,set<pair<int,string>>>  cus_rate;      // cuisine, set of food
    unordered_map<string,string>  food_cus;     // food, cusine
    unordered_map<string,int>  food_rate;     // food rating
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n(size(foods));
        for(int i = 0; i < n; i++) {
            cus_rate[cuisines[i]].insert({-ratings[i],foods[i]});
            food_cus[foods[i]] = cuisines[i];
            food_rate[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        
        cus_rate[food_cus[food]].erase({-food_rate[food],food});
        cus_rate[food_cus[food]].insert({-newRating,food});
        food_rate[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return begin(cus_rate[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */