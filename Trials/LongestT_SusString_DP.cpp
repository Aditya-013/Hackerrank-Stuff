// #include<iostream>
// #include<cstring>
#include <bits/stdc++.h>
int main(){
    clock_t start, end;
    start = clock();
    char w[] = "eefrabcd";
    char q[] = "eefrabc";
    int n = sizeof(w);
    int m = sizeof(q);
    int t[n-1][m-1];
    std::cout<<std::endl;    
    std::cout<<"The String 1:: ";
    for(int i=0; i<n; i++){
        std::cout<<w[i];
    }
    std::cout<<std::endl<<std::endl;

    std::cout<<"The String 2:: ";
    for(int i=0; i<m; i++){
        std::cout<<q[i];
    }
    std::cout<<std::endl<<std::endl;

    int arr[n-1][m-1];
    for(int i=0; i<=n; i++){
        arr[i][0] = 0;
    }
    for(int j=0; j<=m; j++){
        arr[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(w[i-1] == q[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else{
                arr[i][j] = std::max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            std::cout<<arr[i][j]<<"\t";
        }
        std::cout<<"\n";
    }

    std::cout<<"\nThe final value is ::"<<arr[n-1][m-1]<<std::endl;
    end = clock();    
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;
}