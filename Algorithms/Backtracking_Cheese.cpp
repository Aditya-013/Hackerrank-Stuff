#include<iostream>
const int n=5, m=5;
int arr[n][m] = {{1,1,1,0,0},
                {1,0,1,1,0},
                {1,0,1,0,0},
                {1,0,1,1,1},
                {0,0,0,0,2}};

int Solution(int val, int row, int col, char prev_direction)
{
    if(row >= n || row < 0 || col >= m || col < 0)
    {
        return val + 100;
    }

    if(arr[row][col] == 1)
    {
        return val + 100;
    }

    if(arr[row][col] == 2)
    {
        std::cout<<"Found the cheese\n";
        return val;
    }

    if(prev_direction == 'd')
    {
        return std::min(Solution(val + 1, row + 1, col, 'd'), std::min(Solution(val + 1, row, col + 1, 'r'), Solution(val + 1, row, col - 1, 'l')));
    }
    else if(prev_direction == 'u')
    {
        return std::min(Solution(val + 1, row - 1, col, 'u'), std::min(Solution(val + 1, row, col + 1, 'r'), Solution(val + 1, row, col - 1, 'l')));        
    }
    else if(prev_direction == 'l')
    {
        return std::min(Solution(val + 1, row + 1, col, 'd'), std::min(Solution(val + 1, row - 1, col, 'u'), Solution(val + 1, row, col - 1, 'l')));        
    }
    else if(prev_direction == 'r')
    {
        return std::min(Solution(val + 1, row + 1, col, 'd'), std::min(Solution(val + 1, row, col + 1, 'r'), Solution(val + 1, row - 1, col, 'u')));        
    }
    else if(prev_direction == 'n')
    {
        return std::min(std::min(Solution(val + 1, row + 1, col, 'd'), Solution(val + 1, row, col + 1, 'r')), std::min(Solution(val + 1, row - 1, col, 'u'), Solution(val + 1, row, col - 1, 'l')));        
    }
    return 0;
}

int main()
{
    int val = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    int row1, col1;
    std::cout<<"Enter the row location of the player:: ";
    std::cin>>row1;
    std::cout<<"Enter the row location of the player:: ";
    std::cin>>col1;

    val = Solution(val, row1, col1, 'n');
    if(val > 100)
    {
        std::cout<<"Couldn't reach the cheese\n";
    }
    else
    {
        std::cout<<"The number of steps to the cheese is:: "<<val<<std::endl;
    }

    return 0;
}
