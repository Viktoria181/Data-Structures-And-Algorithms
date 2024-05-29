#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sameLongestString(vector<char>& firstString, vector<char>& secondString)
{
    int counter = 0, maxCounter = 0;
    int temp = 0;
    for (int i = firstString.size() - 1; i > 0; i--)
    {        
        temp = i; 
        // iktoria
        // ikriaiktoria
        for (int j = secondString.size() - 1; j > -1; j--)
        {
            if (firstString[i] == secondString[j])
            {
                counter++;
                i--;
            }
            else
            {
                if (maxCounter < counter)
                {
                    maxCounter = counter;
                }
                i = temp;
                counter = 0;
            }
            
        }
        
        if (maxCounter < counter)
        {
            maxCounter = counter;
            counter = 0;
        }
        counter = 0;
        firstString.pop_back();
        if (maxCounter > firstString.size())
            break;
        i = temp;
    }
    return maxCounter;
}


int main()
{
    string s1, s2;
    vector<char> S;
    vector<char> SS;
    std::cin >> s1;
    std::cin >> s2;

    int tempS1 = s1.size();
    int tempS2 = s2.size();

    for (int i = 0; i < tempS1; i++)
    {
        S.push_back(s1.back());
        s1.pop_back();
    }

    for (int i = 0; i < tempS2; i++)
    {
        SS.push_back(s2.back());
        s2.pop_back();
    }
    if (S.size() > SS.size())
        std::cout << sameLongestString(S, SS);
    else
        std::cout << sameLongestString(SS, S);

}

