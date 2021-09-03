#include<iostream>
#include<cstring>
int main(){
    char w[] = "agbcba";
    int n = sizeof(w);
    char q[n];
    for(int i=n-2, j=0; i>=0; i--,j++){
        q[j] = w[i];
    }
    std::cout<<"\n";
    std::cout<<"String 1 :: ";
    for(int i=0; i<n-1; i++){
        std::cout<<q[i];
    }
    std::cout<<std::endl;

    std::cout<<"String 2 :: ";
    for(int i=0; i<n-1; i++){
        std::cout<<w[i];
    }
    std::cout<<"\n";
    std::cout<<std::endl;

    int t[n][n];
    memset(t, 0, sizeof(t));
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(w[i] == q[j]){
                t[i][j] = t[i-1][j-1] + 1;
            }
            else{
                t[i][j] = std::max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout<<t[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    std::cout<<std::endl;
    std::cout<<"The minimum insertiton/deletions are :: "<<(n-1) - t[n-1][n-1]<<std::endl;
    
}