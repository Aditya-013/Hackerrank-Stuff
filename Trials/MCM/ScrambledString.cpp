#include <bits/stdc++.h>
std::unordered_map<std::string, bool> mp;
// std::map<std::string, bool> mp;
bool Solve(std::string a, std::string b){
    int n = a.length();
    std::string key = a;
    key.push_back('$');
    key.append(b);
    if(mp.find(key) != mp.end()){
        return mp[key];
    }

    if(n != b.length()){
        return mp[key] = false;
    }
    if(n == 0){
        return mp[key] = true;
    }
    if(a == b){
        return mp[key] = true;
    }

    
    std::string copy_a = a, copy_b = b;
    sort(copy_a.begin(), copy_a.end());
    sort(copy_b.begin(), copy_b.end());

    if(copy_a != copy_b){
        return mp[key] = false;
    }

    if(n == 1 && a != b){
        return mp[key] = false;
    }
    for(int i=1; i<n; i++){

        // std::cout<<a.substr(0,i)<<" "<<a.substr(i, n)<<" "<<b.substr(0, i)<<" "<<b.substr(i, n)<<std::endl;
        // std::cout<<a.substr(0,i)<<" "<<a.substr(i, n-i)<<" "<<b.substr(0, i)<<" "<<b.substr(i, n-i)<<std::endl<<std::endl;
        //a.substr(start locatiton, size of the string needed);
        if (Solve(a.substr(0,i), b.substr(0,i)) && Solve(a.substr(i, n-i), b.substr(i, n-i))){
            return mp[key] = true;
        }
        if (Solve(a.substr(0,i), b.substr(n-i, i)) && Solve(a.substr(n-i, i), b.substr(0, i))){
            return mp[key] = true;
        }
    }
    return mp[key] = false;
}
int main(){
    std::string a = "coder";
    std::string b = "ocred";
    // std::string a = "hello";
    // std::string b = "hello";
    if(Solve(a,b)){
        std::cout<<"It is a scrambled string\n";
    }
    else{
        std::cout<<"It isn't a scrammbled string\n";
    }
}
