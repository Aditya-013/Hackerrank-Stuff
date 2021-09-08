#include<iostream>
#include<climits>
int n, m;
int CountVals(int* arr, int row, int col, int m){
    if(row < 0 || row > (n-1) || col<0 || col > (m-1) || *(arr + row*m +col) == -1 || *(arr + row*m +col) == 0){
        return 0;
    }
    else{
        *(arr + row*m +col) = -1;
        return 1 + CountVals(arr, row+1, col+1, m) + CountVals(arr, row, col+1, m) + CountVals(arr, row-1, col+1, m) + 
                    CountVals(arr, row+1, col-1, m) + CountVals(arr, row, col-1, m) + CountVals(arr, row-1, col-1, m) + 
                    CountVals(arr, row-1, col, m) + CountVals(arr, row+1, col, m);
    }
}

int FuncOne(int* arr, int n, int m){
    int min = INT_MIN, temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(*(arr + i*m +j) == 1){
                temp = CountVals((int *)arr, i, j, m);
                min = std::max(min, temp);
            }
        }
    }
    return min;
}
int main(){
    // n = 5;
    // m = 5;
    cin>>n>>m;
    int arr[n][m];// = {{1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,0,0,1},{0,1,0,1,1}};
    // {{1,1,1,0,0},
    //  {0,1,1,0,0},
    //  {0,0,1,0,1},
    //  {1,0,1,0,1},
    //  {0,1,0,1,1}};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cin>>arr[i][j];
        }
    }
    std::cout<<FuncOne((int*)arr, n, m)<<"\n";

}
