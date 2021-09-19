#include<iostream>
#include<cstring>
int t[10][10];
int count = 0;
void PrintSubArray(int arr[], int n, int start, int end){
    if(end > n-1 || start > n-1){
        return;
    }
    if(t[start][end] != -1){
        return;
    }
    if(start == end){
        t[start][end] = 0;
        std::cout<<"[";
        count++;
        for(int i=start; i<=end; i++){
            std::cout<<arr[i];
        }
        std::cout<<"]"<<std::endl;
        PrintSubArray(arr, n, start, end + 1);
    }
    if(start > end){
        t[start][end] = 0;
        PrintSubArray(arr, n, start, end + 1);
    }
    if(start < end){
        count++;
        t[start][end] = 0;
        std::cout<<"[";
        for(int i=start; i<=end; i++){
            std::cout<<arr[i];
            if(i != end){
                std::cout<<",";
            }
        }
        std::cout<<"]"<<std::endl;
        PrintSubArray(arr, n, start + 1, end);     
        PrintSubArray(arr, n, start, end + 1);        
    }
}

void SubArrayPart2(int arr[], int n, int start, int end){
    if(end > n-2 || start > n-2){
        return;
    }
    if(start == 1 && end == n-2){
        return;
    }
    if(t[start][end] != -1){
        return;
    }
    if(start == end){
        t[start][end] = 0;
        count++;
        std::cout<<"["<<arr[0]<<",";
        for(int i=start; i<=end; i++){
            std::cout<<arr[i];
        }
        std::cout<<","<<arr[n-1]<<"]"<<std::endl;
        SubArrayPart2(arr, n, start, end + 1);
        SubArrayPart2(arr, n, start + 1, end + 1);
    }
    if(start > end){
        t[start][end] = 0;
        SubArrayPart2(arr, n, start, end + 1);
    }
    if(start < end){
        count++;
        t[start][end] = 0;
        std::cout<<"["<<arr[0]<<",";
        for(int i=start; i<=end; i++){
            std::cout<<arr[i];
            if(i != end){
                std::cout<<",";
            }
        }
        std::cout<<","<<arr[n-1]<<"]"<<std::endl;
        SubArrayPart2(arr, n, start + 1, end);     
        SubArrayPart2(arr, n, start, end + 1);        
    }

}

int main(){
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    std::cout<<"\nThe Output's below\n";
    std::cout<<"[]\n";
    memset(t, -1, sizeof(t));
    PrintSubArray(arr, n, 0, 0);
    std::cout<<"["<<arr[0]<<","<<arr[n-1]<<"]\n";
    count = count + 2;
    memset(t, -1, sizeof(t));
    SubArrayPart2(arr, n, 1, 1);
    std::cout<<"Total count:: "<<count<<"\n";
}
