#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;
 
struct Node
{
    long long data;
    Node* left;
    Node* right;
 
    Node(long long data) : data(data), left(nullptr), right(nullptr)
    {}
};
 
std::map<    long long,     long long> sums;
 
void f(Node* node,     long long n)
{
    if(node == nullptr)
        return;
 
     auto it = sums.find(n);
 
    if(it != sums.end())
    {
        (*it).second += node->data;
    }
    else
    {
        sums.insert({n, node->data});
    }
    f(node->left, n - 1);
    f(node->right, n + 1);
}
 
 
int main()
{
 
        long long size;
    cin >> size;
    std::vector<Node*> tree(size);
    for(int j = 0; j < size; j++)
        tree[j] = new Node(-99);
 
    for(int j = 0; j < size; j++)
    {
            long long vertex;
            long long left;
            long long right;
        cin >> vertex >> left >> right;
 
        tree[j]->data = vertex;
        tree[j]->left = left == -1 ? nullptr : tree[left];
        tree[j]->right = right == -1 ? nullptr : tree[right];
    }
    f(tree[0], 0);
    for(auto it = sums.begin(); it != sums.end(); it++)
        cout << (*it).second << " ";
 
    return 0;
}