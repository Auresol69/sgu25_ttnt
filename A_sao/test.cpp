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
    {
        this->f_score = f_score;
        this->g_score = g_score;
        this->index = index;
        this->node_father = node_father;
    }

    bool operator>(const Node &other) const
    {
        return f_score > other.f_score;
    }
};

class A_Star
{
private:
    int n, m, s, t;
    vector<vector<pair<int, int>>> adj; // Danh sách kề: {đỉnh, trọng số}
    vector<int> h;

public:
    int getN() const { return n; }
    int getM() const { return m; }
    int getS() const { return s; }
    int getT() const { return t; }
    vector<vector<pair<int, int>>> getAdj() const { return adj; }
    vector<int> getH() const { return h; }

    void ReadFile()
    {
        ifstream fin("graph1.txt");
        if (!(fin >> n >> m >> s >> t))
        {
            cerr << "Error: Khong the doc\n";
            exit(1);
        }

        cout << "Doc graph voi " << n << " dinh, " << m << " canh\n";
        cout << "Start: " << s << ", End: " << t << endl;

        adj.resize(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            fin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
};
