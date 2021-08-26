#include<iostream>
using namespace std;
int main(){
    int arr[3] = {1,2,3};
    int m = 5;
    int n = sizeof(arr)/sizeof(int);
    unsigned int t[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0||j==0){
                t[i][j] = 0;
            }
            else if(arr[i-1] > j){
                t[i][j] = t[i-1][j];
            }
            else{
                t[i][j] = t[i][j-arr[i-1]] + 1;
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout<<t[i][j]<<" ";
        }   
        cout<<"\n";
    }
}