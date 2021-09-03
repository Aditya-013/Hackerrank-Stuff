#include <bits/stdc++.h>
int main(){
    char w[] = "acbcf";
    char q[] = "abcdaf";
    std::string temp;
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
    std::cout<<"String 1::"<<w<<"\n";
    std::cout<<"String 2::"<<q<<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cout<<t[i][j]<<"\t";
        }
        std::cout<<"\n";
    }

    int i = n-1;
    int j = m-1;
    std::string temp2;
    while(i > 0 && j>0){
        if(w[i-1] == q[j-1]){
            temp.push_back(w[i-1]);
            temp2.push_back(w[i-1]);
            i--;
            j--;
        }
        else if(t[i-1][j] > t[i][j-1]){
                temp2.push_back(w[i-1]);
                i--;
            }
        else{
                temp2.push_back(q[j-1]);
                j--;
            }
        }
    reverse(temp2.begin(), temp2.end());
    std::cout<<"\n"<<temp2;
    std::cout<<std::endl;
    reverse(temp.begin(), temp.end());
    i=0;
    j=0;
    int k=0;
    while(i<n-1 || j<m-1){
        if(temp[k]==w[i] && temp[k]==q[j]){
            std::cout<<temp[k];
            k++;
            i++;
            j++;
        }
        else if(temp[k]!=w[i] && temp[k]!=q[j]){
            std::cout<<w[i];
            std::cout<<q[j];
            i++;
            j++;
        }
        else if(temp[k]!=w[i] && temp[k]==q[j]){
            std::cout<<w[i];
            i++;
        }
        else if(temp[k]==w[i] && temp[k]!=q[j]){
            std::cout<<q[j];
            j++;
        }
    }

    std::cout<<"\nLength of the LCS ::"<<t[n-1][m-1]<<"\n";
    return 0;
}