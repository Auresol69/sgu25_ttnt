#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Node
{
public:
    int f_score, g_score, index, node_father;

    Node(int f_score, int g_score, int index, int node_father)
        : f_score(f_score), g_score(g_score), index(index), node_father(node_father) {}

    // Toán tử so sánh để priority_queue sắp xếp theo f_score nhỏ nhất
    bool operator>(const Node &other) const
    {
        return f_score > other.f_score;
    }
};

class A_Star
{
public:
    int n, m, s, t;
    vector<vector<pair<int, int>>> adj; // Danh sách kề: {đỉnh, trọng số}
    vector<int> h;                      // Hàm heuristic

    void ReadFile()
    {
        ifstream fin("graph4.txt");
        if (!fin)
        {
            cerr << "Error: Không thể mở graph1.txt\n";
            exit(1);
        }

        fin >> n >> m >> s >> t;
        cout << "Doc graph voi " << n << " dinh, " << m << " canh\n";
        cout << "Start: " << s << ", End: " << t << endl;

        adj.resize(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            if (!(fin >> u >> v >> w))
            {
                cerr << "Lỗi đọc " << i + 1 << endl;
                exit(1);
            }
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        h.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (!(fin >> h[i]))
            {
                cerr << "Lỗi đọc heuristic " << i << endl;
                exit(1);
            }
        }
        cout << "Success!\n";
    }

    vector<int> A_Star_Search(const int &start, const int &end)
    {
        priority_queue<Node, vector<Node>, greater<Node>> openSet;

        vector<int> g(n + 1, INT_MAX);   // Chi phí từ start đến đỉnh hiện tại
        vector<int> cameFrom(n + 1, -1); // Đỉnh liền trước trong đường đi tối ưu

        g[start] = 0;
        openSet.push(Node(h[start], 0, start, -1));

        while (!openSet.empty())
        {
            Node current = openSet.top();
            openSet.pop();

            if (current.index == end)
            {
                // Tạo đường đi
                vector<int> path;
                for (int at = end; at != -1; at = cameFrom[at])
                {
                    path.push_back(at);
                }
                reverse(path.begin(), path.end());
                return path;
            }

            if (current.g_score > g[current.index])
                continue;
            cameFrom[current.index] = current.node_father;

            for (const auto &edge : adj[current.index])
            {
                int neighbor = edge.first;
                int weight = edge.second;

                int tentative_g = g[current.index] + weight;
                if (tentative_g < g[neighbor])
                {
                    cameFrom[neighbor] = current.index;
                    g[neighbor] = tentative_g;
                    int f_score = tentative_g + h[neighbor];
                    openSet.push(Node(f_score, tentative_g, neighbor, current.index));
                }
            }
        }

        return {}; // Không tìm thấy đường đi
    }
};

int main()
{
    A_Star a_star;
    a_star.ReadFile();

    // Gọi thuật toán A* để tìm đường đi
    vector<int> path = a_star.A_Star_Search(a_star.s, a_star.t);

    if (path.empty())
    {
        cout << "No tim thay duong di tu " << a_star.s << " den " << a_star.t << endl;
    }
    else
    {
        // Tính chiều dài đường đi
        int length = 0;
        for (size_t i = 0; i < path.size() - 1; ++i)
        {
            int u = path[i];
            int v = path[i + 1];
            // Tìm trọng số cạnh u-v trong danh sách kề
            for (const auto &edge : a_star.adj[u])
            {
                if (edge.first == v)
                {
                    length += edge.second;
                    break;
                }
            }
        }

        // In kết quả
        cout << "Duong di tu " << a_star.s << " den " << a_star.t << ":" << endl;
        cout << "- Chieu dai: " << length << endl;
        cout << "- Cac dinh: ";
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}