class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> se;

        for(auto x:nums){
            if(se.find(x)!=se.end()){
                return true;
            }
            se.insert(x);
        }

        return false;
    }
};