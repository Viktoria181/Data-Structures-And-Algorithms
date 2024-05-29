#include <iostream>
#include <vector>

using namespace std;

const long long N = 1000001;
vector<long long> Tree[N];

//long long index = 0;
void dfs(long long v, vector<long long>& TimeIn, vector <long long>& TimeOut, long long& index)
{

        TimeIn[v] = index;
        index++;

    for (int i = 0; i < Tree[v].size(); i++)
        dfs(Tree[v][i], TimeIn, TimeOut, index);

        TimeOut[v] = index;
        index++;

}

int main()
{
    long long n;
    cin >> n;


    vector<long long> TimeIn(N);
    vector<long long> TimeOut(N);


    long long a, b;
    long long temp = n - 1;

    while (temp--)
    {
        cin >> a >> b;
        Tree[a].push_back(b);
    }

   /* for (long long i = 0; i < n; i++)
    {
       TimeIn[i] = -1;
       TimeOut[i] = -1;
    }*/
    long long index = 0;
    dfs(0, TimeIn, TimeOut, index);

    long long x, y;
    long long size;

    std::cin >> size;

    bool* isParent = new bool[size];
    long long Index = 0;

    for (long long j = 0; j < size; j++)
    {
        std::cin >> x >> y;

        if (TimeIn[x] < TimeIn[y] && TimeOut[x] > TimeOut[y])
        {
            isParent[Index] = true;
            Index++;
        }
            
        else
        {
            isParent[Index] = false;
            Index++;
        }
            

    }
    for (long long i = 0; i < Index; i++)
    {
        if (isParent[i])
            std::cout << "YES" << "\n";
        else
            std::cout << "NO" << "\n";
    }
 
    return 0;
}




