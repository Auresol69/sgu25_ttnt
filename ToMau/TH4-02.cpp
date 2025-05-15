#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set> // Khong trung va tang dan
#include <algorithm>
#include <ctime>

// DSATUR

// Ý tưởng:
// Vẫn là chọn bậc cao nhất tô màu
// bậc vừa tô hạ độ bão hòa về 0
// các bậc hàng xóm -1
// thực hiện lại row 12
// khi độ bão hòa của tất cả đỉnh =0 nhưng vẫn còn đỉnh chưa tô lấy min màu tô

using namespace std;

class Solution
{
private:
    int n;                 // so luong dinh
    vector<vector<int>> c; // ma tran ke

    struct vertex
    {
        int id, degree, satur;  // id, bac, do bao hoa(giong bac nhung thay vi ha bac truc tiep)
        set<int> banned_colors; // mau CAM
        vertex(const int &id, const int &degree)
        {
            this->id = id;
            this->degree = degree;
            this->satur = degree;
        }
    };

public:
    void readFile()
    {
        ifstream fin("color1.txt");
        fin >> n;
        c.resize(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                fin >> c[i][j];
            }
        }
        fin.close();
    }

    bool AllStatured(const vector<vertex> &vertices)
    {
        for (auto &i : vertices)
        {
            if (i.satur > 0)
                return false;
        }
        return true;
    }

    int MinimumColor(const vector<vertex> &vertices, const int &vector_id)
    {
        int color = 1;
        const set<int> &banned_colors = vertices[vector_id].banned_colors;
        for (auto it = banned_colors.begin(); it != banned_colors.end(); ++it)
        {
            if (*it == color)
                color++;
            else
                break;
        }
        return color;
    }

    void PreventnSaturate(vector<vertex> &vertices, const int &vertex_id, const int &color)
    {
        for (int i = 0; i < n; ++i) // nghiem cam hang xom xai chung mau va -1 do bao hoa
        {
            if (c[vertex_id][vertices[i].id] && vertices[i].satur > 0)
            {
                vertices[i].satur = max(0, vertices[i].satur - 1);
                vertices[i].banned_colors.insert(color);
            }
        }
    }

    int Dsatur()
    {
        vector<vertex> vertices;
        for (int i = 0; i < n; ++i)
        {
            int degree = 0;
            for (int j = 0; j < n; ++j)
                if (c[i][j])
                    degree++;
            vertices.push_back(vertex(i, degree)); // dem bac va push sau vertices
        }
        vector<int> colors(n, 0); // 0 co nghia chua duoc to

        int max_color = 0; // output cua de bai

        while (!AllStatured(vertices))
        {
            int max_satur = 0, vertex_id = 0;
            for (int i = 0; i < n; ++i)
            {
                if (!colors[vertices[i].id])
                {
                    if (vertices[i].satur > max_satur) // Tim do bao hoa cao nhat
                    {
                        max_satur = vertices[i].satur;
                        vertex_id = vertices[i].id;
                    }
                }
            }

            int color = MinimumColor(vertices, vertex_id); // tim mau min nhat

            PreventnSaturate(vertices, vertex_id, color); //  nghiem cam hang xom xai chung mau va -1 do bao hoa

            colors[vertex_id] = color; // gan mau cho dinh dang xet
            vertices[vertex_id].satur = 0;
            max_color = max(max_color, color);
        }

        // xu ly truong hop dac biet khi tat ca dinh deu co do bao hoa = 0 nhung van chua duoc to mau
        for (int i = 0; i < n; ++i)
        {
            if (!colors[vertices[i].id])
            {
                int color = MinimumColor(vertices, vertices[i].id);
                colors[vertices[i].id] = color;
                PreventnSaturate(vertices, vertices[i].id, color);
                max_color = max(max_color, color);
            }
        }
        return max_color;
    }
};

int main()
{
    Solution solution;
    solution.readFile();
    cout << "Max color: " << solution.Dsatur() << endl;
    return 0;
}