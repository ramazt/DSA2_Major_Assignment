#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Job {
    int id;
    int deadline;
    int profit;
};


bool comparator(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
   
    sort(arr, arr + n, comparator);
    
    vector<bool> slots(n,false);

    int count = 0;
    int profit = 0;
   
    for (int i = 0; i < n; i++) {
        
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slots[j]) {
                slots[j] = true; 
                count++;
                profit += arr[i].profit;
                break;
            }
        }
    }

    return { count, profit };
}

int main() {
   
    Job jobs1[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    int n1 = sizeof(jobs1) / sizeof(jobs1[0]);
    vector<int> result1 = JobScheduling(jobs1, n1);
    cout << "Input: " << "{(1,4,20),(2,1,10),(3,1,40),(4,1,30)}" << endl;
    cout << "Output: " << result1[0] << " " << result1[1] << endl;

    Job jobs2[] = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    int n2 = sizeof(jobs2) / sizeof(jobs2[0]);
    vector<int> result2 = JobScheduling(jobs2, n2);
    cout << "Input: " << "{(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}" << endl;
    cout << "Output: " << result2[0] << " " << result2[1] << endl;

return 0;
}

