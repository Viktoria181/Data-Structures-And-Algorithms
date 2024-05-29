#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void permutations(int element, vector<int>& allPermuationsInBool, int size) 
{
    int lowerElement = element;
    int result = 0;

    while (lowerElement != 0)
    {
        result = element | lowerElement;
        
        if (result == element)
            allPermuationsInBool[lowerElement] = 1;

        lowerElement -= 1;

        if (lowerElement == 0)
        {
            result = element - 0;
            if (result == element)
                allPermuationsInBool[0] = 1;
        }
    }
}


int main()
{
    int n, num;
    std::cin >> n;
    vector<int> elements;

    int temp = n;
    int counter = 0, biggestOne = 0;

    while (temp--)
    {
        std::cin >> num;
        if (biggestOne < num)
            biggestOne = num;
        elements.push_back(num); //2 4 6
    }

    vector<int> allPermuations(biggestOne + 1);
    for (int j = 0; j < biggestOne + 1; j++)
        allPermuations[j] = -1;

    for (int i = 0; i < n; i++)
        permutations(elements[i], allPermuations, n);

    int size = allPermuations.size();
    
    while (size--)
        if (allPermuations[size] == 1)
            counter++;

    std::cout << counter;
}