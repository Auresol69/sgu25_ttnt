// Input: 3 May P1, P2, P3
//  6 Cong viec J1, J2, J3, J4, J5, J6
//   Thoi gian  (2, 5 , 8,  1,  5,  1)
//   Phan cong  (J2,J5, J1, J4, J6, J3)
//  Giả sử vẫn cố định 3 máy

// 👉 Máy nào có tổng thời gian nhỏ nhất sẽ nhận công việc tiếp theo. << QUAN TRỌNG

// Output: Tim sum time done cong viec

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// struct Job        --> Khong toi uu nen bo <--
// {
//     int time;
//     int index;
//     Job(int time, int index)
//     {
//         this->time = time;
//         this->index = index;
//     }
// };

// bool find(queue<int> q, const int &target)
// {
//     while (!q.empty())
//     {
//         int tmp = q.front();
//         if (tmp == target)
//         {
//             return true;
//         }
//         q.pop();
//     }
//     return false;
// }

int main()
{
    if (!freopen("input.txt", "r", stdin))
    {
        cerr << "Lỗi mở file input.txt\n";
        return 1;
    }

    int n; // So cong viec
    cin >> n;

    int T[n + 1] = {0}; // Job's time

    // int L[] = {2, 5, 1, 4, 6, 3}; // Static vì quy trình công việc phải theo thứ tự nhất định

    for (int i = 1; i <= n; ++i)
    {
        cin >> T[i];
    }

    int may[3] = {0}; // Static vi de cho :))

    for (int i = 1; i <= n; ++i)
    {
        // Tim may co min time
        int min_idx = 0;
        for (int j = 0; j < 3; ++j)
        {
            if (may[min_idx] > may[j])
            {
                min_idx = j;
            }
        }

        may[min_idx] += T[i];
    }

    int max = INT_MIN;

    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; ++i)
    {
        if (max < may[i])
            max = may[i];
        cout << may[i] << " ";
    }
    cout << endl;
    cout << max << endl;

    return 0;
}