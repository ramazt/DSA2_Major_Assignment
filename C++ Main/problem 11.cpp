#include <iostream>
#include <vector>

using namespace std;

bool isPossible(const vector<int>& A, int N, int M, int maxPages) {
    int students = 1;
    int pages = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > maxPages) 
            return false;
        if (pages + A[i] > maxPages) {
            students++;
            pages = A[i];
            if (students > M)
                return false;
        }
        else {
            pages += A[i];
        }
    }
    return true;
}

int findPages(int N, int A[], int M) {
    
    int low = A[0];  
    int high = 0; 
    for (int i = 0; i < N; i++) {
        high += A[i];
        low = max(low, A[i]);
    }

    int result = -1;

   
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(vector<int>(A, A + N), N, M, mid)) {
            result = mid;
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }

    return result;
}

int main() {
   
    int N1 = 4, M1 = 2;
    int A1[] = { 12, 34, 67, 90 };
    cout << "Minimum number of pages 1 : " << findPages(N1, A1, M1) << endl;

    int N2 = 3, M2 = 2;
    int A2[] = { 15, 17, 20 };
    cout << "Minimum number of pages 2: " << findPages(N2, A2, M2) << endl;

return 0;
}

