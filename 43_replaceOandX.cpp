class Solution{
private:
    void bfs(int row , int col , vector<vector<char>> &grid , vector<vector<int>>&vis){
        queue<pair<int,int>> q;
        q.push({row , col});
        vis[row][col] = 1;
        int n    = grid.size();
        int m    = grid[0].size();
        int dx[] = {-1 , 0 ,1 , 0};
        int dy[] = {0 , 1 , 0 , -1};
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x     = temp.first;
            int y     = temp.second;
            
            for(int i = 0 ;i < 4; i++){
                int nx= x + dx[i];
                int ny= y + dy[i];
                
                if( nx>=0 and ny >=0 and nx<n and ny<m and !vis[nx][ny] and grid[nx][ny] == 'O'){
                    vis[nx][ny] = 1;
                    q.push({nx , ny});
                }
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        vector<vector<int>> vis(n , vector<int>(m , 0));
        
        for(int row = 0 ;row < n ; row++){
            for(int col =0 ; col < m ; col++){
                if( (row == 0 || row == n-1 || col == 0 || col == m-1) and grid[row][col] == 'O' and !vis[row][col]){
                    bfs(row , col , grid , vis);
                }
            }
        }
        
        for(int row = 0 ; row < n ; row++){
            for(int col =0 ; col < m ; col++){
                if( !vis[row][col] and grid[row][col] == 'O'){
                    grid[row][col] = 'X';
                }
            }
        }
        
        return grid;
    }
};
