#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

// Input:
// 5 2 // số đỉnh n=5, số cụm k=2
// 2 3 // tọa độ mỗi đỉnh
// 7 5
// 4 2
// 8 4
// 2 0
// 2 3 //tâm cụm 1
// 4 2 //tâm cụm 2

// Khởi tạo số cụm K (số cụm cần phân chia).

// Chọn ngẫu nhiên K điểm làm tâm cụm ban đầu (centroids).

// Phân cụm:

// Gán mỗi điểm dữ liệu vào cụm có tâm gần nhất (dùng khoảng cách Euclidean).

// Cập nhật:

// Tính lại tâm cụm mới bằng trung bình tất cả các điểm thuộc cụm đó.

// Lặp lại bước 3 và 4 cho đến khi:

// Không có sự thay đổi trong phân cụm (hội tụ), hoặc

// Đạt đến số lần lặp tối đa.

using namespace std;

class Point2D
{
public:
    int x;
    int y;
    Point2D *centroid = nullptr;
    vector<Point2D *> belong;
    bool isCentroid = false;

    Point2D(const int &x, const int &y, const bool &isCentroid)
    {
        this->x = x;
        this->y = y;
        this->isCentroid = isCentroid;
    }

    void setCentroid(Point2D *p)
    {
        this->centroid = p;
    }

    bool hasCentroid()
    {
        return centroid != nullptr;
    }

    void updateCentroid()
    {
        if (belong.empty() || !isCentroid)
        {
            cout << "Warning: Centroid (" << x << ", " << y << ") has no assigned points.\n";
            return;
        }

        double sum_x = 0, sum_y = 0;
        for (Point2D *p : belong)
        {
            sum_x += p->x;
            sum_y += p->y;
        }

        x = sum_x / belong.size();
        y = sum_y / belong.size();
    }

    double distance(const Point2D *p)
    {
        return sqrt(pow(this->x - p->x, 2) + pow(this->y - p->y, 2));
    }

    void printMean(int index = -1)
    {
        if (isCentroid)
        {
            if (index != -1)
                cout << "Cluster " << index << " centroid: (" << x << ", " << y << ")\n";
            else
                cout << "Centroid: (" << x << ", " << y << ")\n";

            for (Point2D *p : belong)
            {
                cout << "    Point: (" << p->x << ", " << p->y << ")\n";
            }
        }
    }
};

vector<Point2D> points;

vector<Point2D> centroids;

void readFile(int &n, int &k)
{
    FILE *file = freopen("input.txt", "r", stdin);
    if (!file)
    {
        cerr << "Không mở được file input.txt\n";
        exit(1);
    }

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {

        int a, b;
        cin >> a >> b;
        points.push_back(Point2D(a, b, false));
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        centroids.push_back(Point2D(a, b, true)); // centroid
    }
}

void K_means(const int &n, const int &maxIterations = 100)
{
    for (int iter = 0; iter < maxIterations; iter++)
    {
        bool changed = false;

        for (int i = 0; i < centroids.size(); i++)
            centroids[i].belong.clear();
        for (int i = 0; i < n; i++)
        {
            double minDist = std::numeric_limits<double>::infinity();
            Point2D *closet = nullptr;
            for (int j = 0; j < centroids.size(); j++)
            {
                double dist = points[i].distance(&centroids[j]);
                if (dist < minDist)
                {
                    minDist = dist;
                    closet = &centroids[j];
                }
            }

            if (points[i].centroid != closet)
            {
                changed = true;
                points[i].setCentroid(closet);
            }
            closet->belong.push_back(&points[i]);
        }

        if (!changed)
            break;

        for (int i = 0; i < centroids.size(); i++)
        {
            centroids[i].updateCentroid();
        }
    }
}

int main()
{
    int n, k;
    readFile(n, k);
    fclose(stdin); // đóng file input

    K_means(n, 100);

    freopen("output.txt", "w", stdout);
    for (int j = 0; j < centroids.size(); j++)
    {
        centroids[j].printMean(j + 1);
    }
    fclose(stdout); // đóng file output
}
