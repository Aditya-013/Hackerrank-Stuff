//Given String s="asdsdf" return only non-repeated characters
//af

#include <iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int ret_if_present(string temp, char c){
    int n = temp.length();
    for(int i=0; i<n; i++){
        if(temp[i] == c){
            return 0;
        }
    }
    return 1;
}

int main(){
  string s = "asdsdf";
  int n = s.length();
  int t[n+1][n+1];
  cout<<"Initital string:: "<<s<<"\n";
  memset(t, 0, sizeof(t));
  for(int i = 1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(s[i-1]==s[j-1] && i != j){
        t[i][j] = t[i][j-1] + 1;
      }
      else{
        t[i][j] = t[i][j-1];
      }
    }
  }

  string temp;
  for(int i = 1; i<=n; i++){
    if(t[i][n-1] > 0 && ret_if_present(temp, s[i-1])){
        temp.push_back(s[i-1]);
    }
  }
  cout<<"Recurring chars:: "<<temp<<endl;
}
