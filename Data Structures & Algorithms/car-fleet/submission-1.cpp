class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int,int>> vals;

        for(int i=0;i<pos.size();i++){
            vals.push_back({pos[i],speed[i]});
        }

        sort(vals.begin(),vals.end());

        stack<double> st;

        for(int i=vals.size()-1;i>=0;i--){
            double val = ((target-vals[i].first)*1.0)/(vals[i].second*1.0);

            if(st.size()==0 || st.top()<val){
                st.push(val);
            }
        }

        return st.size();

        
    }
};