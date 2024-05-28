#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> requests(int wantedNums, int howMany, int groups, queue<int>& All)
{
    priority_queue<int, vector<int>, greater<int> > timeLimited;   // 10 9 8 7 6 5 4 3 2 1
    queue<int> Final;
    int size = 0;
    int numOfGroups = 0;
   
    while (size != -1)
    {
        if (size == howMany && !All.empty()) 
        {
            for (int i = 0; i < wantedNums; i++)
            {
                if (!timeLimited.empty())
                {
                    Final.push(timeLimited.top());
                    timeLimited.pop();
                }
                size--;
            }

            int cur = All.front(); 
            timeLimited.push(cur);
            All.pop();
            size = 1;

            numOfGroups++;
        }

        if (numOfGroups == groups)
        {
            size = -1;
            break;
        }
        else if (size != howMany && !All.empty())
        {
            int cur = All.front();
            timeLimited.push(cur);
            All.pop();
            size++;
        }
        if (All.empty())
        {
            while (numOfGroups != groups && timeLimited.size() >= wantedNums)
            {
                for (int k = 0; k < wantedNums; k++)
                {
                    Final.push(timeLimited.top());
                    timeLimited.pop();
                }
                numOfGroups++;
            }

            while (!timeLimited.empty())
            {
                timeLimited.pop();
            }
            size = -1;
        }
    }
    return Final;

}

int main()
{
    int wantedNums, howMany, groups, N, element;
    std::cin >> wantedNums >> howMany >> groups >> N;

    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        std::cin >> element;
        q.push(element);
    }

    queue<int> v = requests(wantedNums, howMany, groups, q);

    while (!q.empty())
        q.pop();

    int temp = v.size();

    for (int i = 0; i < temp; i++)
    {
        int cur = v.front();
        std::cout << cur << " ";
        v.pop();
    }

    return 0;
}
