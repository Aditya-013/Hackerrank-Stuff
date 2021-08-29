#include<iostream>
int SubString_2(char *w, char *q, int n, int m, int val){
    if(n==-1 || m==-1)
        return val;
    if(w[n] == q[m])
        return SubString_2(w, q, n-1, m-1, val+1);
    else
        return std::max(SubString_2(w, q, n-1, m, 0), SubString_2(w, q, n, m-1, 0));
}

int main(){
    char w[] = "abcdfer";
    char q[] = "abc";
    int n = sizeof(w);
    int m = sizeof(q);
    std::cout<<std::endl;
    std::cout<<"Final value:: "<<SubString_2(w, q, n-2, m-2, 0)<<std::endl<<std::endl;

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
