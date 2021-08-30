#include <iostream>
#include <cstring>

// Finding the number and Printing

int main(){
    char q[] = "abcdaf";
    char w[] = "acbcf";
    //abcf
    int n = sizeof(w);
    int m = sizeof(q);
    int t[n][m];
    memset(t, 0, sizeof(t));

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
    std::cout<<"\nString 1: ";
    for(int i=0; i<n; i++){
        std::cout<<w[i];
    }
    std::cout<<"\n";
    std::cout<<"String 2: ";
    for(int j=0; j<m; j++){
        std::cout<<q[j];
    }
    std::cout<<"\n\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cout<<t[i][j]<<"\t";
        }
        std::cout<<"\n";
    }

    std::string lcs;
    // char lcs[10];
    int k=0;
    int i=n-1;
    int j=m-1;
    while(i>=0 && j>=0){
        if(w[i-1] == q[j-1]){
            // lcs[k] = w[i-1];
            lcs.push_back(w[i-1]);
            k++;
            i--;
            j--;
        }
        else{
            if(t[i-1][j] <= t[i][j-1]){
                j=j-1;
            }
            else{
                i=i-1;
            }
        }
    }
    std::cout<<"\nSub Sequence::";
    for(int i=k-1; i>=0; i--){
        std::cout<<lcs[i];
    }
    std::cout<<std::endl<<std::endl;

}
