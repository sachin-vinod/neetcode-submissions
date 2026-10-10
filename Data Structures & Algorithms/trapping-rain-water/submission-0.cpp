class Solution {
public:
    int trap(vector<int>& hei) {
        int leftMa=0, rightMa=0, currLeft=0, currRight=hei.size()-1;
        int ans=0;
        while(currLeft<currRight){
            leftMa=max(leftMa,hei[currLeft]);
            rightMa=max(rightMa,hei[currRight]);

            if(leftMa>rightMa){
                ans+=max(0,rightMa-hei[currRight]);
                currRight--;
            }
            else{
                ans+=max(0,leftMa-hei[currLeft]);
                currLeft++;
            }

        }

        return ans;
    }
};
