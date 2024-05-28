#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numOfEven(const int* arr, int N)
{
    int even = 0;
    for (int i = 0; i < N; i++)
        if (arr[i] % 2 == 0)
            even++;
    return even;
}

int numOfOdd(const int* arr, int N)
{
    int odd = 0;
    for (int i = 0; i < N; i++)
        if (arr[i] % 2 != 0)
            odd++;
    return odd;
}

bool isEven(int a)
{
    return a % 2 == 0;
        
}

int* newArray(const int* arr, int left, int right, int N) 
{
    int* newArrEven = new int[left + 1];
    int* newArrOdd = new int[right + 1];

    int j = 0, k = 0;
    for (int i = 0; i < N; i++)
    {
        if (isEven(arr[i]))
        {
            newArrEven[j] = i;
            j++;
        }
        else
        {
            newArrOdd[k] = i;
             k++;
        }
    }

    int* newArr = new int[N];
    int p = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        if (p < j)
        {
            newArr[i] = arr[newArrEven[p]];
            p++;
        }
        else
        {
            newArr[i] = arr[newArrOdd[n]];
            n++;
        }
    }

    return newArr;
}
 void printArray(const int* arr, int N)
{
for (auto i = 0; i < N; i++)
    std::cout << arr[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    std::cin >> N;
    int* array = new int[N];

    for (int i = 0; i < N; i++)
        std::cin >> array[i];

    int left = numOfEven(array, N);
    int right = numOfOdd(array, N);

    array = newArray(array, left, right, N);

    for (int i = 0; i < N; i++)
    std::cout << array[i] << "\n";
}