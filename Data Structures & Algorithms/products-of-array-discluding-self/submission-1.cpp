auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 1);
        int prefix = 1;
        for (int i = 0; i < len; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int i = len - 1; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }
};