#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'larrysArray' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY A as parameter.
 */

bool check(vector<int> A, vector<int> B)
{
    int n = A.size();
    for(int i=0; i<n; i++)
    {
        if(A[i] != B[i])
        {
            return false;
        }
    }
    return true;
}

bool middleend(int a, int b, int c)
{
    //if middle is in the end - largest is first
    if(c < a && b < a && c > b)
    {
        return true;
    }
    return false;    
}

bool middlefront(int a, int b, int c)
{
    //if middle is in the front - smallest  is in the end
    if(c < a && c < b && a < b)
    {
        return true;
    }
    return false;    
}

bool isSorted(int a, int b, int c)
{
    if(a > b && b > c && a > c)
    {
        return true;
    }
    return false;
}

bool done(vector<int> A)
{
    int n = A.size();
    for(int i=0; i<n-1; i++)
    {
        if(A[i] > A[i+1])
        {
            return true;
        }
    }
    return false;
}

string larrysArray(vector<int> A) {
    int n = A.size();
    vector<int> B;
    B = A;
    bool sorted = false;
    int i = 0;
    bool changed = false;
    //n - 3 + 1 number of groups
    
    while(done(A))
    {
        changed = false;
        if(middlefront(A[i], A[i+1], A[i+2]))
        {
            int smallest = A[i+2];
            int middle = A[i];
            int end = A[i+1];
            A[i+2] = end;
            A[i+1] = middle;
            A[i] = smallest;
        }
        else if(middleend(A[i], A[i+1], A[i+2]))
        {
            int end = A[i];
            int small = A[i+1];
            int middle = A[i+2];
            A[i+2] = end;
            A[i+1] = middle;
            A[i] = small;
        }
        else if(A[i] > A[i+1] && A[i+1] > A[i+2]) 
        {
            int smallest = A[i+2];
            int middle = A[i+1];
            int big = A[i];
            A[i] = smallest;
            A[i+1] = big;
            A[i+2] = middle;
        }
        else if(A[i] > A[i+1] && A[i+1] < A[i+2])
        {
            int small = A[i+1];
            int big = A[i+2];
            int middle = A[i];
            A[i] = small;
            A[i+1] = big;
            A[i+2] = middle;
        }
        
        i++;
        
        if(i == n-2)
        {
            for(int j=0; j<n; j++)
            {
                std::cout<<A[j]<<" ";
            }
            std::cout<<endl;
            if(check(A,B))
                {
                    return "NO";
                }
            i = 0;  
            B = A;
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split(rtrim(A_temp_temp));

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

        fout << result << "\n";
    }

    fout.close();

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
