// So nguoi tho bang so cong viec, cong viec la cot doc
// Tim tong chi phi
// Y tuong tim max
// chon lay max neu chua phan cong

#include <iostream>
#include <vector>
#include <climits>

int n;

using namespace std;

int main()
{

    cin >> n;

    int a[n][n];
    vector<bool> congviec(n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> phancong;

    for (int i = 0; i < n; i++)
    {
        int tmp = -1;
        int max = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            if (!congviec[j] && max < a[i][j])
            {
                max = a[i][j];
                tmp = j;
            }
        }
        if (tmp != -1)
        {
            phancong.push_back(max);
            congviec[tmp] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << congviec[i] << " ";
    }

    cout << endl;

    cout << phancong.size() << endl;
    for (int i : phancong)
    {
        cout << i << " ";
    }

    return 0;
}