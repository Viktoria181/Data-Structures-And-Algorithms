#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


bool isPositive(int num)
{
    return num > 0;
}

queue<int> battle(vector<int> people, int numOfPeople)
{
    stack<int> stk;
    queue<int> theOneThatWin;
    int index = 0;
    if (index == 0 && !isPositive(people[index]))
    {
        while (!isPositive(people[index]))
            theOneThatWin.push(people[index++]);
    }

    int counterForPositive = 0;

    while (index < numOfPeople)
    {
        if (isPositive(people[index]))
        {
            stk.push(people[index]);
            counterForPositive++;
            index++;
        }
        else if (!isPositive(people[index]) && counterForPositive != 0) 
        {
            int temp = people[index];
            temp = -temp;
            int stk_top = stk.top();
            // checks for battles
            if (stk_top > temp)
                index++;
            else if (temp > stk_top)
            {       
                stk.pop();
                counterForPositive--;
                if (counterForPositive == 0)
                {
                    theOneThatWin.push(people[index]);
                    index++;
                }
            }
            else if (temp == stk_top)
            {
                index++;
                stk.pop();
                counterForPositive--;
            }
        }
        else if (!isPositive(people[index]) && counterForPositive == 0)
        {
            theOneThatWin.push(people[index++]);
        }
    }

    int x = counterForPositive;
    int top = 0;
    stack<int> newStk;
    while (counterForPositive != 0)
    {
        top = stk.top();
        newStk.push(top);
        stk.pop();
        counterForPositive--;
    }

    while (x != 0)
    {
        top = newStk.top();
        theOneThatWin.push(top);
        newStk.pop();
        x--;
    }

    return theOneThatWin;
}


int main()
{
    int N;
    std::cin >> N;

    vector<int> arrOfPeople;
    int person;

    for (int i = 0; i < N; i++)
    {
        std::cin >> person;
        arrOfPeople.push_back(person);
    }

    queue<int> arrayOfPeople;
    arrayOfPeople = battle(arrOfPeople, N);

    stack<int> stk;
    int size = arrayOfPeople.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << arrayOfPeople.front() << " ";
        arrayOfPeople.pop();
    }

    return 0;
}


