#include<iostream>
#include<cstring>
const int n=5, m=5;
int t[n][m];
int arr[n][m] = {{0,0,0,0,0},
                {1,0,1,0,0},
                {1,0,0,0,0},
                {1,0,1,1,1},
                {0,0,0,0,2}};

int Solution(int val, int row, int col)
{

    if(row >= n || row < 0 || col >= m || col < 0)
    {
        return val + 100;
    }

    if(arr[row][col] == 1)
    {
        return val + 100;
    }

    if(t[row][col] != -1)
    {
        return val + 100;
    }
    t[row][col] = 0;

    if(arr[row][col] == 2)
    {
        std::cout<<"Found the cheese\n";
        return val;
    }


    return std::min(std::min(Solution(val + 1, row + 1, col), Solution(val + 1, row, col + 1)), std::min(Solution(val + 1, row - 1, col), Solution(val + 1, row, col - 1)));        
}

int main()
{
    int val = 0;
    memset(t, -1, sizeof(t));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    int row1 = 0, col1 = 0;

    // std::cout<<"Enter the row location of the player:: ";
    // std::cin>>row1;
    // std::cout<<"Enter the row location of the player:: ";
    // std::cin>>col1;

    val = Solution(val, row1, col1);
    if(val >= 100)
    {
        std::cout<<"Couldn't reach the cheese\n";
    }
    else
    {
        std::cout<<"The number of steps to the cheese is:: "<<val<<std::endl;
    }

    return 0;
}
