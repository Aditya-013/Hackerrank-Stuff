#include<iostream>
using namespace std;
int max(int a, int b){
    if(a>b) return a;
    return b;
}
int findCount(int arr[], int n, int sum){
    int t[n+1][sum+1]; 
    for(int j = 0; j< n+1; j++)
        t[j][0] = 1;
    for(int i = 1; i<sum+1; i++)
        t[0][i] = 0;

    for(int j = 1; j <n+1; j++){
        for(int i = 1; i < sum+1; i++){
            if(arr[j-1] > i)
                t[j][i] = t[j-1][i];
            
            else
                t[j][i] = t[j-1][i-arr[j-1]] + t[j-1][i];
            
        }
    }
    
    for(int j=0; j<n+1; j++){
        for(int i=0; i<sum+1; i++){
            cout<<t[j][i]<<" ";
        }
        cout<<"\n";
    }
    
    return t[n][sum];
}
int main(){
    int arr[] = { 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = 0;
    cout<<"Enter the value to check -"<<endl;
    cin>>val;
    val = findCount(arr, n, val);
    cout<<"Value is :: "<<val<<endl;
    return 0;
}