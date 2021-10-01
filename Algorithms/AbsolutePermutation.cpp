#include <bits/stdc++.h>

/*
 * Complete the 'absolutePermutation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */

std::vector<int> absolutePermutation(int n, int k) 
{
    std::vector<int> arr;
    std::vector<int> retnon;
    retnon.push_back(-1);
    int val = 2*k;
    int temp = 0;
    if(k == 0)
    {
        for(int i=0; i<n; i++)
        {
            arr.push_back(i+1);
        }
        return arr;
    }
    else{
        temp = (n/(2*k));        
    }
    for(int i=0; i<temp; i++)
    {
        for(int j=1; j<val+1; j++)
        { 
            if(j > k)
            {
                arr.push_back((i*(2*k)) + ((j)-k));
            }
            else 
            {            
                arr.push_back((i*(2*k)) + (k+(j)));
            }
        }
    }
    if(arr.size() == n)
    {
        return arr;
    }
    return retnon;
}

int main()
{
    int t;
    std::cin>>t;
    for(int i=0; i<t; i++)
    {
        int n,val;
        std::cin>>n;
        std::cin>>val;
        std::vector<int> ans;
        ans = absolutePermutation(n, val);
        for(int j=0; j<ans.size(); j++)
        {
            std::cout<<ans[j]<<" ";
        }
        std::cout<<std::endl;
    }
}
