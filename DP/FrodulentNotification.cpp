#include<bits/stdc++.h>
using namespace std;
// int arr[] = {2, 1, 4, 3, 4};
int arr[] = {2, 3, 4, 2, 3, 6, 8, 4, 5};
int cnt[210];

int median(int d){
    int p = 0;
    for(int i=0; i<210; i++){
        p += cnt[i];
        if(2*p > d){
            return 2*i;
        }else if(2*p == d){
            for(int j=i+1;;j++){
                if(cnt[j] != 0){
                    return i + j;
                }
            }
        }
    }
}

int main(){
    int d = 5;
    int n = sizeof(arr)/sizeof(int);
    int count = 0;
    // int n, d;
    // std::cin>>n>>d;
    // int arr[n];
    // for(int i=0; i<n; i++){
    //     std::cin>>arr[i];
    // }
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++){
        if(i >= d){
            if(arr[i] >= median(d)){
                count++;
            }
            cnt[arr[i-d]]--;
        }
        cnt[arr[i]]++;
    }       
    std::cout<<count<<std::endl;
}
