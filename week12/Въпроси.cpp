#include <iostream>
#include <vector>
 
using namespace std;

class UnionFind
{
    std::vector<int> parent;
    std::vector<int> sizes;
 
    int getRoot(int n);
public:
    UnionFind(int n); //0...n-1
    bool areInOneSet(int n, int k);
    bool Union(int n, int k);
};
 
 
UnionFind::UnionFind(int n) : parent(n), sizes(n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sizes[i] = 1;
    }
}
int UnionFind::getRoot(int n)
{
    while (parent[n] != n)
        n = parent[n];
    return n;
}
bool UnionFind::areInOneSet(int n, int k)
{
    n--;
    k--;
    return getRoot(n) == getRoot(k);
}
bool UnionFind::Union(int n, int k)
{
    n--;
    k--;
    int root1 = getRoot(n);
    int root2 = getRoot(k);
    if (root1 == root2)
        return false;
    if (sizes[root1] > sizes[root2])
        std::swap(root1, root2);
 
    parent[root1] = root2;
    sizes[root2] += sizes[root1];
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    std::cin >> N;
    UnionFind f(N);
 
    int M;
    std::cin >> M;
    for(int i = 0; i < M; i++)
    {
        int start,end;
        std::cin >> start >> end;
  f.Union(start, end);
    }
 
    int S;
    std::cin >> S;
    for(int i = 0; i < S; i++)
    {
        int command;
        std::cin >> command;
        if(command == 1)
        {
            int v, u;
            std::cin >> v >> u;
 
            std::cout << f.areInOneSet(v, u);
        }
        else
        {
            int v, u;
            std::cin >> v >> u;
             f.Union(v, u);
        }
    }
 
 
}