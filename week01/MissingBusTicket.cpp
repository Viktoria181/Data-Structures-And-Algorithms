#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lostTicket(int* arr, int N)
{
    int value = 0, nextValue = 0;

    for (int i = 0; i < N; i++) 
    {
        if (arr[i] > N || arr[i] <= 0)
            continue;
        
        value = arr[i];

        while (arr[value - 1] != value) 
        {
            nextValue = arr[value - 1];
            arr[value - 1] = value;
            value = nextValue;
            
            if (value > N || value <= 0)
                break;
        }
    }
    for (int i = 0; i < N; i++) 
        if (arr[i] != i + 1) 
            return i + 1;
    
    return N + 1;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    int* array = new int[N];

    for (int i = 0; i < N; i++)
        std::cin >> array[i];

    std::cout << lostTicket(array, N);

    delete[] array;
}
