#include <iostream>
#include <cstdlib> // cho rand(), srand()
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// TH6-01.CPP
// Tạo file ngẫu nhiên taci.txt; có cấu trúc như sau:
// -Dòng đầu ghi số n (với 3<=n<=99).
// -Trong n dòng tiếp theo; mỗi dòng ghi n số; các số cách nhau ít nhất một khoảng trắng. Yêu
// cầu giá trị các số từ 0 đến n^2 -1 và mỗi giá trị chỉ xuất hiện một lần trên bàn TACI.

int main()
{

    srand(time(NULL));
    int n = 3 + rand() % 97; // 3 <= n <= 99
    cout << n << endl;
    vector<int> a;
    for (int i = 0; i < n * n; ++i)
    {
        a.push_back(i);
    }
    random_shuffle(a.begin(), a.end());
    freopen("taci.txt", "w", stdout);
    cout << n << "\n";
    for (int i = 0; i < n * n; ++i)
    {
        cout << a[i] << " ";
        if ((i + 1) % n == 0)
            cout << endl;
    }
    return 0;
}