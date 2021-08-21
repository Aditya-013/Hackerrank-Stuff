#include<iostream>
using namespace std;

int main(){
    unsigned int t[10][10];
    int m[2][2];
    int final[2][2];
    int val;

    for(int i=0; i<10;i++){
        for(int j=0; j<10; j++){
            t[i][j] = i*j;
        }
    }
    cout<<"Matrix 10x10 :: (Before)::\n";
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=1; i<3;i++){
        for(int j=1; j<3; j++){
            m[i-1][j-1] = i+j;
        }
    }    
    cout<<"Matrix 2x2 :: (Before)::\n";
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            for(int k=0; k<2; k++){
                for(int l=0; l<2; l++){
                    val = 0;
                    for(int z=0; z<2; z++){
                        val = val + t[i+k][j+z]*m[z][l];
                    }
                    t[i+k][j+l] = val;
                    //cout<<"i+k = "<<i+k<<"|j+l= "<<j+l<<"\\val= "<<val<<"\n";
                }
            }
            // cout<<"\n";
        }
    }

    cout<<"Matrix 10x10 :: (After)::\n";
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }



    // int val = 0;
    // for(int i =0; i<2;i++){
    //     for(int j = 0; j<2; j++){
    //         val = 0;
    //         for(int z=0; z<2; z++){
    //             val = val + m[i][z]*t[z][j];
    //         }
    //         final[i][j] = val;
    //     }
    // }

}