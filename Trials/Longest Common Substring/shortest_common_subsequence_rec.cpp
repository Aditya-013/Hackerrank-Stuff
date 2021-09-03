#include<iostream>
#include<cstring>
// #include<algorithm>
int t[10][10];
int SubSequence(char w[], char q[], int n, int m){
    if(n==0||m==0){
        return 0;
    }
    else if(t[n][m] != 0){
        return t[n][m];
    }
    else if(w[n-1] == q[m-1]){
        return t[n][m] = SubSequence(w, q, n-1, m-1) + 1;
    }
    else{
        return t[n][m] = std::max(SubSequence(w, q, n-1, m), SubSequence(w, q, n, m-1));
    }
}
int main(){
    char w[] = "acbcf";
    char q[] = "abcdaf";
    memset(t, 0, sizeof(t));
    std::string temp;
    int n = sizeof(w)-1;
    int m = sizeof(q)-1;
    std::cout<<"The Shortest Common Subsequence is:: "<<SubSequence(w, q, n, m)<<"\n";
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            std::cout<<t[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    int i = n;
    int j = m;
    while(i>=0 && j>=0){
        if(w[i-1] == q[j-1]){
            temp.push_back(w[i-1]);
            i--;
            j--;
        }
        else if(t[i-1][j] > t[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    // reverse(temp.begin(), temp.end());
    std::cout<<"\nThe LCS string is:: "<<temp<<"\n";
}