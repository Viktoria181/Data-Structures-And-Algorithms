#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void mergeTwoSortedArrays(vector<string>& str, vector<int>& array, int left, int middle, int right) 
{

    vector<int> leftArray, rightArray;
    vector<string> leftString, rightString;
    int l = left;
    while (l <= right)
    {
        if (l <= middle)
        {
            leftArray.push_back(array[l]);
            leftString.push_back(str[l]);
        }

        else
        {
            rightArray.push_back(array[l]);
            rightString.push_back(str[l]);
        }

        l++;
    }

    int leftIndex = 0, rightIndex = 0;
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size())
    {
        if (leftArray[leftIndex] > rightArray[rightIndex])
        {
            array[left] = leftArray[leftIndex];
            str[left] = leftString[leftIndex];
            leftIndex++;
            left++;
        }
        else if (leftArray[leftIndex] < rightArray[rightIndex])
        {
            array[left] = rightArray[rightIndex];
            str[left] = rightString[rightIndex];
            rightIndex++;
            left++;
        }
        else if (leftArray[leftIndex] == rightArray[rightIndex])
        {
            if (leftString[leftIndex] > rightString[rightIndex])
            {
                array[left] = rightArray[rightIndex];
                str[left] = rightString[rightIndex];
                rightIndex++;
                left++;
            }
            else if (leftString[leftIndex] < rightString[rightIndex])
            {
                array[left] = leftArray[leftIndex];
                str[left] = leftString[leftIndex];
                leftIndex++;
                left++;
            }
            else if (leftString[leftIndex] == rightString[rightIndex])
            {
                array[left] = leftArray[leftIndex];
                str[left] = leftString[leftIndex];
                leftIndex++;
                left++;
            }
        }
    }

    while (leftIndex < leftArray.size())
    {
        array[left] = leftArray[leftIndex];
        str[left] = leftString[leftIndex];
        left++;
        leftIndex++;
      
    }

    while (rightIndex < rightArray.size())
    {
        array[left] = rightArray[rightIndex];
        str[left] = rightString[rightIndex];
        left++;
        rightIndex++;
        
    }

}

void mergeSort(vector<string>& str, vector<int>& array, int left, int right) {

    if (left >= right)
        return;

    int middle = left + (right - left) / 2;

    mergeSort(str, array, left, middle);
    mergeSort(str, array, middle + 1, right);

    mergeTwoSortedArrays(str, array, left, middle, right);

}


int main()
{
    int N;
    std::cin >> N;

    std::vector < std::string > inputt;
    std::string word;

    for (int j = 0; j < N; j++)
    {
        std::cin >> word;
        inputt.push_back(word);
    }

    std::vector < int > integer;
    int input;

    for (int k = 0; k < N; k++)
    {
        std::cin >> input;
        integer.push_back(input);
    }

    mergeSort(inputt, integer, 0, N - 1);

    for (int i = 0; i < N; i++)
        std::cout << inputt[i] << " " << integer[i] << " \n";
}

