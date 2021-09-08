#include<iostream>
#include<climits>
#include<cstring>
int n, m;
int t[100][100];
int CountVals(int* arr, int row, int col){
    if(row < 0 || row > (n-1) || col<0 || col > (m-1) || *(arr + row*m +col) == -1 || *(arr + row*m +col) == 0){
        return 0;
    }
    if(t[row][col] != -1){
        return t[row][col];
    }
    else{
        *(arr + row*m +col) = -1;
        return t[row][col] = 1 + CountVals(arr, row+1, col+1) + CountVals(arr, row, col+1) + CountVals(arr, row-1, col+1) + 
                    CountVals(arr, row+1, col-1) + CountVals(arr, row, col-1) + CountVals(arr, row-1, col-1) + 
                    CountVals(arr, row-1, col) + CountVals(arr, row+1, col);
    }
}

int FuncOne(int* arr, int n, int m){
    int min = INT_MIN, temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(*(arr + i*m +j) == 1){
                temp = CountVals((int *)arr, i, j);
                min = std::max(min, temp);
            }
        }
    }
    return min;
}
int main(){
    n = 5;
    m = 5;
    // cin>>n>>m;
    memset(t,-1,sizeof(t));
    int arr[n][m] = {{1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,1,0,1},{0,1,0,1,1}};
    // {{1,1,1,0,0},
    //  {0,1,1,0,0},
    //  {0,0,1,0,1},
    //  {1,0,1,0,1},
    //  {0,1,0,1,1}};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // std::cin>>arr[i][j];
        }
    }
    std::cout<<"The number of 1's are :: "<<FuncOne((int*)arr, n, m)<<"\n";

}
