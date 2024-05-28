
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long unique(vector<long long>& arr, long long n)
{
    long long Size = 0;
    set<long long> uni;
    long long curSize = 0, index = 0;
    for (long long i = 0; i < n; i++)
    {
            if (uni.count(arr[i]) == 1) 
            {
                while (arr[index] != arr[i])
                    arr[index++] = -1;
                arr[index++] = -1;

                uni.clear();
                curSize = 0;
                i = index;
            }

            uni.insert(arr[i]);
            curSize = uni.size();
            if (Size < curSize)
                Size = curSize;
    }
    return Size;
}



 int main()
 {
    long long N = 0, num, size = 0;

        vector<long long> arr;
        std::cin >> N;
        long long temp = N;

        while (temp--)
        {
            std::cin >> num;
            arr.push_back(num);
        }
        size = unique(arr, N);
        std::cout << size;
 }
