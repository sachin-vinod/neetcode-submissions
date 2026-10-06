class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> suff(n,0);

        suff[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]*nums[i];
        }

        int currPro=1;

        vector<int> ans;

        for(int i=0;i<n-1;i++){
            ans.push_back(currPro*suff[i+1]);
            currPro*=nums[i];
        }

        ans.push_back(currPro);

        return ans;
    }
};
