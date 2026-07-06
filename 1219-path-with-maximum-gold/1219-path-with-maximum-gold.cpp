class Solution {
public:
    int mg=0;
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    maxgold(i,j,0,grid);
                }
            }
        }
        return mg;
    }
    void maxgold(int i,int j,int cg, vector<vector<int>>& grid){
        if(i<0 || j<0 ||i==grid.size() || j==grid[i].size() || grid[i][j]==0){
            return;
        }
        cg+=grid[i][j];
        mg=max(cg,mg);
        int rob=grid[i][j];
        grid[i][j]=0;
        maxgold(i-1,j,cg,grid);
        maxgold(i,j+1,cg,grid);
        maxgold(i+1,j,cg,grid);
        maxgold(i,j-1,cg,grid);
        grid[i][j]=rob;
    }
};