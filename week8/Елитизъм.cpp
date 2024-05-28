#include <iostream>
#include<queue>
#include<vector>

using namespace std;


void median(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, int element, double& originalMedian)
{
    while (true)
    {
        if (maxHeap.size() - minHeap.size() == 0) //1 2 3 4 5 6 
        {
            if (element < originalMedian)
            {
                maxHeap.push(element);
                originalMedian = maxHeap.top();
                break;
            }
            else
            {
                minHeap.push(element);
                originalMedian = minHeap.top();
                break;
            }

        }
        else if (maxHeap.size() - minHeap.size() == -1)
        {
            if (element <= originalMedian)
                maxHeap.push(element);
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
            }
            originalMedian = (double)(minHeap.top() + maxHeap.top()) / 2;
            break;
        }
        else if (maxHeap.size() - minHeap.size() == 1) // 11 4  // 2 3 
        {
            if (element < originalMedian)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
            }
            else
                minHeap.push(element);

            originalMedian = (double)(minHeap.top() + maxHeap.top()) / 2;
            break;
        }
    }

}



int main()
{
    int N;
    std::cin >> N;
    int temp1 = N;
    double realMedian = 0;
    int el;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    while (temp1--)
    {
        std::cin >> el;
        median(maxHeap, minHeap, el, realMedian);
        printf("%.1lf\n", realMedian);
    }
}

