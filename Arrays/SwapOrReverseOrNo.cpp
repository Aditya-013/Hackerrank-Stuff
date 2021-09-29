#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int checkreverse(vector<int> arr, int start, int end)
{
    if(end - start == 1)
    {
        return -1;
    }
    for(int i=start; i<end; i++)
    {
        if(arr[i] < arr[i+1])
        {
            return -1;
        }
    }
    return 1;
}

int checkswap(vector<int> arr, int start, int end)
{
    int temp;
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    int n = arr.size();
    for(int i=1; i<n; i++)
    {
        if(arr[i] < arr[i-1])
            return -1;
    }
    
    return 1;
}

int checkno(vector<int> arr, int start, int end)
{
    return 1;    
}

void almostSorted(vector<int> arr) 
{
    int n = arr.size();
    int start = 0, end = n-1;
    int big = INT_MIN, bigIndex, small = INT_MAX, smallIndex;
    
    // std::cout<<arr[175]<<" "<<arr[188]<<std::endl;
    if(arr[start] > arr[end])
    {
        bigIndex = start;
        smallIndex = end;
    }
    else
    {
        for(int i=0; i<n-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                bigIndex = i;
                break;
            }
        }
        
        for(int i=n-1; i>0; i--)
        {
            if(arr[i] < arr[i-1])
            {
                smallIndex = i;
                break;
            }
        }
    }   
    if(checkswap(arr, bigIndex, smallIndex) == 1)
    {
        std::cout<<"yes\nswap "<<bigIndex+1<<" "<<smallIndex+1;
        exit(0);
    }
    if(checkreverse(arr, bigIndex, smallIndex) == 1)
    {
        std::cout<<"yes\nreverse "<<bigIndex+1<<" "<<smallIndex+1;
        exit(0);
    }
    std::cout<<"no";
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
