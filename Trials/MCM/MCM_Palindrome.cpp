#include<iostream>
#include<climits>
#include<cstring>
static int t[20][20];
bool isPalindrome(std::string s1, int i, int j){
    while(i<j && i!=j){
        if(s1[i] == s1[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

int Solve(std::string s1, int i, int j){
    int mn = INT_MAX, left, right;
    int temp = 0;
    if(i >= j){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    if(isPalindrome(s1, i, j)){
        return t[i][j] = 0;
    }else{
        for(int k=i; k<j; k++){
            if(t[i][k] != -1){
                left = t[i][k];
            }else{
                left = Solve(s1, i, k);
            }
            if(t[k+1][j] != -1){
                right = t[k+1][j];
            }else{
                right = Solve(s1, k+1, j);
            }
            temp = left + right + 1;
            if(temp < mn){
                mn = temp;
            }
        }
    }
    return t[i][j] = mn;
}

int main(){
    memset(t, -1, sizeof(t));  
    std::string s1 = "nitin";
    int n = s1.length();  
    int val = Solve(s1, 0, n-1);
    std::cout<<"The minimum number of partitions :: "<<val<<std::endl;
    return 0;
}
