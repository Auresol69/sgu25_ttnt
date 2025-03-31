//  Lập trình giải bài toán Sequencing Problem N jobs on 2 Machines (Bài toán gia công trên
//  2 máy)
//  Tìm lịch gia công; từ đó tìm thời gian hoàn thành tất cả các công việc.

// tach thanh 2 array
// B1:
// array 1 : p[i]1 < p[i]2
// array 2 : p[i]2 < p[i]1

// B2:
// sort array 1 tang dan
// sort array 2 giam dan

// B3:
// ghep 2 array 1 va 2 lai

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int, int>> A;
    vector<pair<int, int>> B;

    // Input thay

    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] <= b[i])
            A.push_back(pair<int, int>(a[i], b[i]));
        else
            B.push_back(pair<int, int>(a[i], b[i]));
    }

    // [Capture](Parameters) -> ReturnType { FunctionBody }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), [](pair<int, int> x, pair<int, int> y)
         { return x.second > y.second; });

    vector<pair<int, int>>
        schedule = A;
    for (auto &p : B)
    {
        schedule.push_back(p);
    }

    int time_a = 0, time_b = 0;

    for (auto &job : schedule)
    {
        time_a += job.first;
        time_b = max(time_a, time_b) + job.second;
    }

    int total_time = time_b;

    freopen("output.txt", "w", stdout);
    cout << total_time << endl;
    for (auto &job : schedule)
    {
        cout << job.first << " " << job.second << endl;
    }

    return 0;
}