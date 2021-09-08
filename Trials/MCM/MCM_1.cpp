#include<bits/stdc++.h>
int t[10][10];
int Solve(int arr[], int i, int j)
{
    int mn = INT_MAX;
    int k, temp;
    if(i == j)
    {
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    else
    {
        for(int k=i; k<j; k++)
        {
            temp = Solve(arr, i, k) + Solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
            if(temp < mn)
            {   
                mn = temp;   
            }
        }

        t[i][j] = mn;
    }
    return mn;
}
int main()
{
    memset(t, -1, sizeof(t));
    // for(int i=0; i<10; i++){
    //     for(int j=0; j<10; j++){
    //         std::cout<<t[i][j]<<"\t";
    //     }
    //     std::cout<<"\n";
    // }
    int arr[] = {10, 30, 5, 60};
    int count = sizeof(arr)/sizeof(int);
    std::cout<<"The final value is :: "<<Solve(arr, 1, count-1)<<"\n";
    return 0;
}