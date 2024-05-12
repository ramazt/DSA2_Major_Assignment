#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start;
    int end;
};

bool compareMeeting(Meeting a, Meeting b) {
    return a.end < b.end;
}

int maxMeetings(int start[], int end[], int n) {
    vector<Meeting> meetings;
    for(int i = 0; i < n; i++) {
        meetings.push_back({start[i], end[i]});
    }

    // Sort meetings based on end times
    sort(meetings.begin(), meetings.end(), compareMeeting);

    int count = 0;
    int last_end_time = 0;

    for(int i = 0; i < n; i++) {
        if(meetings[i].start > last_end_time) {
            count++;
            last_end_time = meetings[i].end;
        }
    }

    return count;
}

int main() {
    int starts1[] = {1, 3, 0, 5, 8, 5};
    int ends1[] = {2, 4, 6, 7, 9, 9};
    int n1 = sizeof(starts1) / sizeof(starts1[0]);

    cout << "Input: {" << starts1[0];
    for (int i = 1; i < n1; i++) cout << ", " << starts1[i];
    cout << "} {" << ends1[0];
    for (int i = 1; i < n1; i++) cout << ", " << ends1[i];
    cout << "}\nOutput: " << maxMeetings(starts1, ends1, n1) << endl;

    int starts2[] = {10, 12, 20};
    int ends2[] = {20, 25, 30};
    int n2 = sizeof(starts2) / sizeof(starts2[0]);

    cout << "Input: {" << starts2[0];
    for (int i = 1; i < n2; i++) cout << ", " << starts2[i];
    cout << "} {" << ends2[0];
    for (int i = 1; i < n2; i++) cout << ", " << ends2[i];
    cout << "}\nOutput: " << maxMeetings(starts2, ends2, n2) << endl;

return 0;
}

