#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Street
{
    int start;
    int bestcost;
    vector<int> bestpath;
};

bool find(const vector<int> &d, const int &x)
{
    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] == x)
            return true;
    }
    return false;
}

void gts1(const int &n, vector<Street> &v, const vector<vector<int>> &a)
{
    for (int z = 1; z <= n; z++)
    {
        vector<int> d;
        int totalcost = 0;
        int start = z;
        d.push_back(z);

        while (d.size() < n)
        {
            int min = INT_MAX;
            int tmp = -1;

            for (int i = 1; i <= n; i++)
            {
                if (find(d, i))
                    continue;

                if (min > a[start][i])
                {
                    min = a[start][i];
                    tmp = i;
                }
            }

            if (tmp != -1)
                totalcost += min;

            d.push_back(tmp);
            start = tmp;
        }

        totalcost += a[d.back()][z]; // Quay lại điểm ban đầu
        d.push_back(z);

        Street street;
        street.start = z;
        street.bestcost = totalcost;
        street.bestpath = d;
        v.push_back(street);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<Street> v;
    gts1(n, v, a);

    int min_cost = INT_MAX;
    for (const auto &s : v)
    {
        if (min_cost > s.bestcost)
            min_cost = s.bestcost;
    }

    cout << min_cost << endl;

    return 0;
}
