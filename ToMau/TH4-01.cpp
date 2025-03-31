#include <iostream>
#include <vector>
#include <algorithm>
#define maxN 10000

using namespace std;

int n, m;
vector<int> v[maxN];
int color[maxN] = {0};

// Hàm nhập đồ thị
void input(vector<int> *v, const int &n, const int &m)
{
    for (int i = 0; i < m; i++)
    {
        int u, w;
        cin >> u >> w;
        v[u].push_back(w);
        v[w].push_back(u);
    }
}

// Kiểm tra xem màu có hợp lệ với đỉnh u không
bool check(int u, int c)
{
    for (int tmp : v[u])
    {
        if (color[tmp] == c)
            return false;
    }
    return true;
}

// Tô màu cho đỉnh nếu hợp lệ
int ToMau(int u, int mau)
{
    if (!color[u] && check(u, mau))
    {
        color[u] = mau;
        return 1;
    }
    return 0;
}

// Hàm sắp xếp đỉnh theo bậc giảm dần
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

// Xuất kết quả tô màu
void output()
{
    for (int i = 0; i < n; i++)
    {
        cout << "Dinh " << i << ": Mau " << color[i] << endl;
    }
}

int main()
{
    cin >> n >> m;
    input(v, n, m);

    // Sắp xếp đỉnh theo bậc giảm dần
    vector<int> sortedVertices = sortVerticesByDegree();

    int colored = 0, mau = 1;
    while (colored < n)
    {
        for (int i : sortedVertices)
        {
            colored += ToMau(i, mau);
        }
        mau++;
    }

    output();
    return 0;
}
