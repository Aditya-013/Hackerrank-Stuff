#include<iostream>
#include<cstring>
#include<climits>
int vis[100][100];
int TotalValues = 0, n, m;

// int dx[] = {1,1,1,0,-1,-1,-1,0};
// int dy[] = {1,0,-1,-1,-1,0,1,1};

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int arr[5][5] = {{1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,0,0,1},{0,1,0,1,1}};

bool check(int x, int y){
    if (x < 0 && x >= n && y < 0 && y >= m)
        return false;
    
    return true;
}

void dfs(int x, int y){
    TotalValues++;
    std::cout<<"arr["<<x<<"]["<<y<<"] = "<<arr[x][y]<<std::endl;
    vis[x][y] = 1;
    int row, col;  
    for(int i=0; i<8; i++){
        row = x + dx[i];
        col = y + dy[i];
        if(row >= 0 && row < n && col >= 0 && col < m && arr[row][col] == 1 && vis[row][col] == 0){
            dfs(row,col);
        }
    }
}

int main(){
    n = 5;
    m = 5;
    int min = INT_MIN;
    memset(vis, 0, sizeof(vis));
    std::cout<<"The array is:: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cout<<arr[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    std::cout<<std::endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1 && vis[i][j] == 0){
                dfs(i, j);
                std::cout<<"Total Values = "<<TotalValues<<std::endl<<std::endl;
                if(TotalValues > min){
                    min = TotalValues;
                }
                TotalValues = 0;
            }
        }
    }
    std::cout<<"The Max total number of 1's in a region are:: "<<min<<"\n";
    return 0;
}
