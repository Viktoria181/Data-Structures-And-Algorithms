#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int crypto(const int* array, int N)
{
    bool isEnd = false;
    int i = 0;
    int minus = 0;
    int buy = 0;
    int sell = 0;
    while (!isEnd)
    {
        if (minus == 0 && array[i] < array[i + 1])
        {
            minus++;
            buy -= array[i];
            sell = array[i + 1];
            if (i == N - 2)
                buy += sell;
        }
        else if (minus != 0 && array[i] < array[i + 1])
        {
            sell = array[i + 1];
            if (i == N - 2)
                buy += sell;
        }
        else if (minus != 0 && array[i] > array[i + 1])
        {
            minus = 0;
            sell = array[i];
            buy += sell;
        }

        if(i == N - 2)
            isEnd = true;
        i++;
    }
    return buy;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    std::cin >> N;
    int* arr = new int[N];

    for (int i = 0; i < N; i++)
        std::cin >> arr[i];

    std::cout << crypto(arr, N);

    delete[] arr;
}