#include <iostream>
#include <climits>
#include <vector>
using namespace std;
 
 
struct Node
{
    int data;
    Node* left;
    Node* right;
 
    Node(int data) : data(data), left(nullptr), right(nullptr)
    {}
};
 
bool isBSTRec(Node* root, int min, int max)
{
    if (!root)
        return true;
    if (root->data < min || root->data > max)
        return false;
 
    return isBSTRec(root->left, min, root->data - 1) && isBSTRec(root->right, root->data + 1, max);
}
bool isBST(Node* root)
{
    return isBSTRec(root, INT_MIN, INT_MAX);
}
 
int main()
{
    int n;
    cin >> n;
 
    for(int i = 0; i < n; i++)
    {
        int size;
        cin >> size;
        std::vector<Node*> tree(size);
        for(int j = 0; j < size; j++)
            tree[j] = new Node(-99);
 
        for(int j = 0; j < size; j++)
        {
            int vertex;
            int left;
            int right;
            cin >> vertex >> left >> right;
 
            tree[j]->data = vertex;
            tree[j]->left = left == -1 ? nullptr : tree[left];
            tree[j]->right = right == -1 ? nullptr : tree[right];
        }
        cout << isBST(tree[0]) << endl;
    }
 
    return 0;
}
 