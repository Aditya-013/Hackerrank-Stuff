#include<iostream>
using namespace std;
void hello(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int max(int a, int b){ return(a>b)  ?   a:  b;}

int maximizeTheCuts(int n, int x, int y, int z)
    {
    cout<<"hello"<<endl;
        int val[3];
        val[0] = x;
        val[1] = y;
        val[2] = z;
        int t[n+1];
        t[0] = -1;
        for(int i=1; i<=n; i++){
            t[i] = 0;
        }
        for(int j=0; j<3; j++){
            for(int i=1; i<=n; i++){
                if(val[j] <= i){
                    if(t[i - val[j]] == -1){
                        t[i] = max(1,t[i]);
                        // hello(t,8);
                    }
                    else if(t[i- val[j]] > 0){
                        t[i] = t[i-val[j]] + 1;
                        // hello(t,8);
                    }
                }
            }
        }
        for(int i=0; i<=n; i++){
            cout<<t[i]<<" ";
        }
        cout<<"\n";
        return t[n];
    }

int main() {    
    int n = 88;
    int x = 11,y = 88,z = 49;
    cout<<maximizeTheCuts(n,x,y,z)<<endl;
	return 0;
}
