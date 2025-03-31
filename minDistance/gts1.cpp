#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool find(const vector<int> &v, const int &x)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
            return true;
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp;
            cin >> tmp;
            a[i][j] = tmp;
        }
    }
    vector<int> v;

    // push diem bat dau
    int start = m;
    int total_dis = 0;

    v.push_back(start);
    while (v.size() < n)
    {
        int min = INT_MAX;
        int tmp = -1;
        for (int i = 1; i <= n; i++)
        {
            // check trung ptu trong v
            if (find(v, i))
                continue;

            // tim min
            if (min > a[start][i])
            {
                min = a[start][i];
                tmp = i;
            }
        }
        v.push_back(tmp);
        start = tmp;
    }
    v.push_back(m);

    // sum chi phi

    freopen("output.txt", "w", stdout);

    // for (int i = 0; i < n - 1; i++)
    // {
    //     cout << a[i][i + 1] << "\n";
    // }

    cout << "Duong di ngan nhat: ";

    for (int i = 0; i < v.size(); i++)
    {

        cout << v[i] << " ";
    }

    cout << "\n";
    cout << "Quang duong di ngan nhat: ";
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << a[v[i]][v[i + 1]] << " ";
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        total_dis += a[v[i]][v[i + 1]];
    }
    cout << "\nQuang duong tong: " << total_dis;
    cout << "\n";
}