class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        map<int,set<char>> row, clm;
        map<pair<int,int>,set<char>> subBox;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]!='.'){
                    if(row[i].find(b[i][j])!=row[i].end()
                        || clm[j].find(b[i][j])!=clm[j].end()
                        || subBox[{i/3,j/3}].find(b[i][j])!=subBox[{i/3,j/3}].end()
                    ){
                        return false;
                    }
                    row[i].insert(b[i][j]);
                    clm[j].insert(b[i][j]);
                    subBox[{i/3,j/3}].insert(b[i][j]);
                }
            }
        }

        return true;
    }
};
