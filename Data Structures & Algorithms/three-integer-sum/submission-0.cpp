class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto x:nums){
            mp[x]++;
        }

        int n=nums.size();
        set<vector<int>> se;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]]--;
                mp[nums[j]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }

                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }

                if(mp.find(-1*(nums[i]+nums[j]))!=mp.end()){
                    vector<int> temp={nums[i],nums[j],-1*(nums[i]+nums[j])};
                    sort(temp.begin(),temp.end());
                    se.insert(temp);
                }

                mp[nums[i]]++;
                mp[nums[j]]++;
            }
        }

        vector<vector<int>> ans;

        while(se.size()){
            vector<int> temp=*(se.begin());
            ans.push_back(temp);
            se.erase(temp);
        }

        return ans;
    }
};
