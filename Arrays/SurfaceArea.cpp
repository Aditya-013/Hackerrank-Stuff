#include<iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(){
    // int n=10, m=1;
    int k=0;

    int n, m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }


    // int arr[n][m] = {{1,3,4},{2,2,3},{1,2,4}};
    // int arr[n][m] = {{51}, {32}, {28}, {49}, {28}, {21}, {98}, {56}, {99}, {77}};

    //After this
    unsigned int surfaceArea[n];
    memset(surfaceArea, 0, sizeof(surfaceArea));
    for(int i=0; i<n; i++){
        cout<<surfaceArea[i]<<"\t";
    }
    cout<<endl;
    //Top ka area calculation
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && i==n-1){
                surfaceArea[i] += 2*arr[i][j];
            }
            else if(i==0 || i==n-1){
                surfaceArea[i] += arr[i][j];
            }

            if(j==0){
                surfaceArea[i] += arr[i][j]; 
                surfaceArea[i] += 1; 
                k = arr[i][j];
            }
            else{
                surfaceArea[i] += abs(arr[i][j] - arr[i][j-1]);
                surfaceArea[i] += 1;
                k = arr[i][j];
            }
            
        }
        surfaceArea[i] += k;
        surfaceArea[i] += m;
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            surfaceArea[i] += abs(arr[i][j] - arr[i+1][j]);
        }
    }

    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<surfaceArea[i]<<"\t";
    }
    cout<<endl;
    int sum=0;
    for(int i=0; i<n; i++){
        sum += surfaceArea[i];
    }
    cout<<"Current Surface Area ::"<<sum<<endl;
}
