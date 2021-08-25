#include<iostream>
#include <cstring>
using namespace std;

int main(){
    int m = 3;
    int n = 4;
    int S[3] = {1,2,3};
    int t[5];
    for(int i=0; i<=n; i++)
        t[i] = 0;
    t[0] = 1;
    // cout<<"BEFORE"<<endl;
    // for(int i=0; i<=n; i++)
    //         cout<<t[i]<<" ";
    // cout<<endl;
    
    for(int i=0; i<m; i++){
        for(int j=1; j<=n; j++){
            if(S[i] <= j){
                t[j] = t[j-S[i]] + t[j];
            }
        }
    }
    // cout<<endl;
    // cout<<"After"<<endl;
    // for(int i=0; i<=n; i++)
    //         cout<<t[i]<<" ";
    // cout<<endl;
    
}