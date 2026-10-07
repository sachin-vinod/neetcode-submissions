class Solution {
private:
    class DSU{
        private:
            vector<int> parent;
        public:
            DSU(int n){
                for(int i=0;i<n;i++){
                    parent.push_back(i);
                }
            }

            int find(int v){
                if(parent[v]==v){
                    return v;
                }

                return parent[v]=find(parent[v]);
            }

            void merge(int x, int y){
                x=find(x);
                y=find(y);

                parent[y]=x;
            }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        DSU dsu(n);

        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=i;

                if(mp.find(nums[i]+1)!=mp.end()){
                    dsu.merge(mp[nums[i]+1],i);
                }

                if(mp.find(nums[i]-1)!=mp.end()){
                    dsu.merge(i,mp[nums[i]-1]);
                }
            }
        }   

        mp.clear();

        int ans=0;

        for(int i=0;i<n;i++){
            mp[dsu.find(i)]++;
            ans=max(ans,mp[dsu.find(i)]);
        }

        return ans;

    }
};
