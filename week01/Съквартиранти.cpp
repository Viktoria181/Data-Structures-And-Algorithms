#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int numDeleted(char* arr, int size)
{
    int deleted = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == 0 && arr[i] == arr[i + 1])
            deleted++;
        else if (i + 1 > size)
            break;
        else if (arr[i] == arr[i + 1])
            deleted++;
    }
    return deleted;
}

int main()
{
    int Q = 0;
    int len = 0;

    std::cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        std::cin >> len;
        char* str = new char[len];
         
        for (int j = 0; j < len; j++)
            std::cin >> str[j];

        std::cout << numDeleted(str, len);
        std::cout << std::endl;
    }

}