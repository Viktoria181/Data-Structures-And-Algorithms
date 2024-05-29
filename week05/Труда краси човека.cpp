#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



long long smallestWork(vector<long long>& Arr, long long length, long long sizeOfArr)
{
    long long sum = 0, smallestone = 0, index = 0, counterLength = 0;
    long long dif = length - 1;
    long long indexOfSmallestEl = 0;
    while (true)
    {
        if (indexOfSmallestEl + 1 == sizeOfArr)
            break;

        if (indexOfSmallestEl < index || index == 0)
        {

            if (index + 1 > sizeOfArr)
                break;
            if (index == 0)
            {
                smallestone = Arr[index];
                indexOfSmallestEl = index;
            }
            else if (counterLength == 0)
            {
                smallestone = Arr[index];
                indexOfSmallestEl = index;
            }
            else if (Arr[index] < smallestone)
            {
                smallestone = Arr[index];
                indexOfSmallestEl = index;
            }

            if (counterLength < length)
            {
                counterLength++;
                index++;
            }

            if (counterLength == length)
            {
                sum += smallestone;
                counterLength = 0;
                index -= dif;
            }

        }
        else if (index + dif == sizeOfArr)
            break;
        else if (indexOfSmallestEl >= index && Arr[index + dif] < smallestone)
        {
            smallestone = Arr[index + dif];
            indexOfSmallestEl = index + dif;
            sum += smallestone;
            index++;
        }
        else
        {
            sum += smallestone;
            index++;
            if (index == sizeOfArr)
                break;
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;
    std::cin >> N >> K;
    vector<long long> Array;
    long long item;
    for (long long i = 0; i < N; i++)
    {
        std::cin >> item;
        Array.push_back(item);
    }
    std::cout << smallestWork(Array, K, N);
}