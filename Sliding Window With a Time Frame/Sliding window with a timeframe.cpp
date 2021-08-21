// Online C++ compiler to run C++ program online
#include <iostream>
#include<time.h>
using namespace std;

void swapping(int* slot, int value, int r){

    for(int i = 1; i <r; i++){
        slot[i-1] = slot[i];
    }
    slot[r-1] = value;
}

void sliding_window(int r, int s, int n, int* arr){
    int slots = r;
    int j = 0;
    string str[n];
    int slot[r];
    if(r == 0 || n == 0){
        return;
    }
    if(n < r){
        for(int i =0; i<n;i++)
            cout<<arr[i]<<" is Allowed\n";
        exit(0);
    }
    
    for(int i =0; i<n;i++)
        str[i] = "Blocked";
    
    // for(int i =0; i<n;i++)
    //     cout<<arr[i]<<" is "<<str[i]<<"\n";
        
    for(int i = 0; i < n; i++){
        if(i == 0 && slots > 0){
            slots--;
            str[i] = "Allowed";
            slot[j] = arr[i];
            j++;
        }
        else if(slots > 0){
                slots--;
                slot[j] = arr[i];
                j++;
                str[i] = "Allowed";
            }
        else if(arr[i] - slot[0] > s){
            swapping(slot, arr[i], r);
            str[i] = "Allowed";
        }
        }
    for(int i =0; i<n;i++)
        cout<<arr[i]<<" is "<<str[i]<<"\n";
}

int main() {
    int r, s, n, temp;
    int flag;
    int* arr;
    cout<<"Do you want to enter the elements yourself?(Yes = 1; No - !(1) )\n";
    cin>>flag;
    
    if (flag != 1){
        
        // ___________ UNCOMMENT EVERYTHING ON BOTTOM
        srand(time(0));
        n = rand()%100;
        // arr = (long long*)malloc(n*sizeof(long long));
        arr=(int *) malloc(n * sizeof(int));
        for(int i = 0; i<n; i++){
            arr[i] = rand();
        }
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n;j++){
                if(arr[i] > arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    
        // ___________ UNCOMMENT EVERYTHING ON TOP
    }
    
    else{
        cout<<"Enter the number of UNIX timeframes (n)\n";
        cin>>n;
        arr=(int *) malloc(n * sizeof(int));
        int i = 0;
        while(i < n){
            cout<<"Enter element "<<i+1<<"::";
            cin>>arr[i];
            i++;
        }
    }
    
    cout<<"\nEnter the maximum number of requests (R)\n";
    cin>>r;
    cout<<"Enter the Sliding Window Period (S)\n";
    cin>>s;
    
    sliding_window(r, s, n, arr);    
    return 0;
    
    // new Date(Math.abs(new Random().nextLong()) % new Date().getTime())
    // cout<<Date;
    
    // long epoch1 = 1582341584;
    // long epoch2 = 1156879329;
    // long randomEpoch = epoch1 + Math.abs(new Random().nextLong()) % (epoch2-epoch1);
    // cout<<randomEpoch<<"\n";
    
    // r = 2;
    // s = 5;
    // n = 8;
    // arr[0] = 1;
    // arr[1] = 2;
    // arr[2] = 4;
    // arr[3] = 5;
    // arr[4] = 6;
    // arr[5] = 7;
    // arr[6] = 8;
    // arr[7] = 9;
    
}