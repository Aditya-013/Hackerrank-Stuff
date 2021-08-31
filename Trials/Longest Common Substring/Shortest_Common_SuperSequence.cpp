#include<iostream>
#include<cstring>
int main(){
    char w[] = "AGGTAB";
    char q[] = "GXTXAYB";
    int n = sizeof(w);
    int m = sizeof(q);
    std::cout<<n<<" "<<m<<"\n";
    int t[n][m];
    memset(t, 0, sizeof(t));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cout<<t[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(w[i-1] == q[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
            }
            else{
                t[i][j] = std::max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    std::cout<<std::endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cout<<t[i][j]<<"\t";
        }
        std::cout<<"\n";
    }

    std::cout<<"\nFinal Size of Sub Sequence :: "<<t[n-1][m-1]<<"\n";
    int final = (n-1) + (m-1) - t[n-1][m-1];
    std::cout<<"Lenth of the Super Subsequence :: "<<final<<"\n";
}