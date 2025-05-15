#include <iostream>
#include <vector>
#include <algorithm>
#define maxN 10000
using namespace std;

int n;
vector<int> v[maxN];
vector<int> color(maxN, 0);

// Đọc ma trận kề
void input()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                v[i].push_back(j);
            }
        }
    }
}

bool check(int u, int c)
{
    for (int neighbor : v[u])
    {
        if (color[neighbor] == c)
            return false;
    }
    return true;
}

vector<int> sortVerticesByDegree()
{
    vector<pair<int, int>> degree;
    for (int i = 0; i < n; i++)
    {
        degree.push_back({v[i].size(), i});
    }
    sort(degree.rbegin(), degree.rend());
    vector<int> sortedVertices;
    for (auto &p : degree)
    {
        sortedVertices.push_back(p.second);
    }
    return sortedVertices;
}

void output()
{
    for (int i = 0; i < n; i++)
    {
        cout << "Dinh " << i << ": Mau " << color[i] << endl;
    }
}

int main()
{
    freopen("color1.txt", "r", stdin);
    cin >> n;
    input();

    vector<int> sortedVertices = sortVerticesByDegree();

    int mau = 1;
    while (true)
    {
        bool found = false;
        for (int i : sortedVertices)
        {
            if (color[i] == 0 && check(i, mau))
            {
                color[i] = mau;
                found = true;
            }
        }
        if (!found)
            break;
        mau++;
    }

    output();
    cout << "Max: " << mau;

    return 0;
}
