#include<iostream>
#include<cstring>
int static t[10][10];
int SubString_2(char *w, char *q, int n, int m, int val){
    if(n==-1 || m==-1){
        return val;
    }
    if(t[n][m] != -1){
        return t[n][m];
    }
    if(w[n] == q[m]){
        return t[n][m] = SubString_2(w, q, n-1, m-1, val+1);
    }
    else
        return t[n][m] = std::max(SubString_2(w, q, n-1, m, 0), SubString_2(w, q, n, m-1, 0));
}

int SubString_3(char *w, char *q, int n, int m){
    if(n==-1 || m==-1){
        return 0;
    }
    if(t[n][m] != -1){
        return t[n][m];
    }
    if(w[n] == q[m]){
        return (t[n][m] = 1 + SubString_3(w, q, n-1, m-1));
    }
    else
        return t[n][m] = std::max(SubString_3(w, q, n-1, m), SubString_3(w, q, n, m-1));
}


int main(){
    memset(t, -1, sizeof(t));    
    char w[] = "abasd";
    char q[] = "asdabasdca";
    int n = sizeof(w);
    int m = sizeof(q);
    int t[n-1][m-1];
    std::cout<<std::endl;
    // int final_value = SubString_2(w, q, n-2, m-2, 0);
    int final_value = SubString_3(w, q, n-2, m-2);
    std::cout<<"Final value:: "<<final_value<<std::endl<<std::endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            std::cout<<t[i][j]<<"\t";
        }
        std::cout<<"\n";
    }

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
}
