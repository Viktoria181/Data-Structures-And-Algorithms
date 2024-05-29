#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    std::string input;
    cin >> input;
 
    std::vector<int> bigLetters(26, -1);
    std::vector<int> smallLetters(26, -1);
    std::vector<int> numbers(26, -1); 
 
    for(int i = 0; i < input.size(); i++)
    {
        if(isupper(input[i]))
        {
            int ind = input[i] - 'A';
            if(bigLetters[ind] == -1)
                bigLetters[ind] = i;
            else
                bigLetters[ind] = -2;
        }
        else if(islower(input[i]))
        {
            int ind = input[i] - 'a';
            if(smallLetters[ind] == -1)
                smallLetters[ind] = i;
            else
                smallLetters[ind] = -2;
        }
        else if(isdigit(input[i]))
        {
            int ind = input[i] - '0';
            if(numbers[ind] == -1)
                numbers[ind] = i;
            else
                numbers[ind] = -2;
        }
    }
 
    std::vector<int> res;
    for(int i = 0; i < 26; i++)
    {
        if(smallLetters[i] >= 0)
            res.push_back(smallLetters[i]);
        if(bigLetters[i] >= 0)
            res.push_back(bigLetters[i]);
    }
 
    for(int i = 0; i < 10; i++)
    {
        if(numbers[i] >= 0)
            res.push_back(numbers[i]);
    }
 
    std::sort(res.begin(), res.end());
 
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
 
    return 0;
}