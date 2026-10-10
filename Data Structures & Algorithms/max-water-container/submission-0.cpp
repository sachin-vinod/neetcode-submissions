class Solution {
public:
    int maxArea(vector<int>& hei) {
        int ans=0;

        int leftIdx=0, rightIdx=hei.size()-1;
        while(leftIdx<rightIdx){
            ans=max(ans,(rightIdx-leftIdx)*(min(hei[leftIdx],hei[rightIdx])));

            if(hei[leftIdx]>=hei[rightIdx]){
                rightIdx--;
            }
            else{
                leftIdx++;
            }
        }    

        return ans;
    }
};
