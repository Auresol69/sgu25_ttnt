#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

struct Point
{
    double x, y;
    int cluster = -1; // cụm ban đầu
};

// Hàm tính khoảng cách Euclidean
double distance(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Tính tâm cụm mới
Point computeCentroid(const vector<Point> &points, int cluster_id)
{
    double sumX = 0, sumY = 0;
    int count = 0;
    for (const auto &p : points)
    {
        if (p.cluster == cluster_id)
        {
            sumX += p.x;
            sumY += p.y;
            count++;
        }
    }
    if (count == 0)
        return {0, 0};
    return {sumX / count, sumY / count};
}

int main()
{
    // Đọc từ file input.txt
    freopen("input.txt", "r", stdin);

    int n, k;
    cin >> n >> k;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;

    vector<Point> centroids(k);
    for (int i = 0; i < k; ++i)
        cin >> centroids[i].x >> centroids[i].y;

    bool changed = true;
    int iterations = 0;

    while (changed && iterations < 100)
    {
        changed = false;
        // Gán cụm gần nhất
        for (int i = 0; i < n; ++i)
        {
            double minDist = numeric_limits<double>::max();
            int bestCluster = -1;
            for (int j = 0; j < k; ++j)
            {
                double dist = distance(points[i], centroids[j]);
                if (dist < minDist)
                {
                    minDist = dist;
                    bestCluster = j;
                }
            }
            if (points[i].cluster != bestCluster)
            {
                points[i].cluster = bestCluster;
                changed = true;
            }
        }

        // Cập nhật lại tâm cụm
        for (int i = 0; i < k; ++i)
        {
            centroids[i] = computeCentroid(points, i);
        }

        iterations++;
    }

    // In kết quả
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < n; ++i)
    {
        cout << "Diem (" << points[i].x << ", " << points[i].y << ") thuoc cum " << points[i].cluster + 1 << endl;
    }

    return 0;
}
