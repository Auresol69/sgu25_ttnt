// TH6-02.CPP
// Với 2 trạng thái bắt đầu và kết thúc được cho ngẫu nhiên.
// -Hãy tính giá trị độ đo ước lượng H1 của trạng thái ban đầu đối với trạng thái kết thúc.
// -Hãy tính giá trị độ đo ước lượng H2 của trạng thái ban đầu đối với trạng thái kết thúc.
// Ghi chú về H1 và H2:
// H1:
// Với độ ước lượng Trong đó = 0 nếu ai=bi và =1 nếu ai khác bi
// H2:
// Với hàm heuristic ; trong đó là số bước dịch chuyển (theo chiều ngang và
// chiều dọc) để đẩy ô ai về đúng vị trí ô bi.

#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

class status
{
private:
    vector<vector<int>> a;
    int n;

public:
    status()
    {
    }

    status(const int &n, const vector<vector<int>> &a)
    {
        this->n = n;
        this->a = a;
    }

    int getN() const
    {
        return n;
    }

    vector<vector<int>> getA() const
    {
        return a;
    }

    void setN(const int &n)
    {
        this->n = n;
    }

    void setA(const vector<vector<int>> &a)
    {
        this->a = a;
    }

    void input()
    {
        freopen("taci.txt", "r", stdin);
        int n;
        cin >> n;
        setN(n);
        vector<vector<int>> a;
        for (int i = 0; i < n; ++i)
        {

            vector<int> row;
            for (int j = 0; j < n; ++j)
            {
                int tmp;
                cin >> tmp;
                row.pb(tmp);
            }
            a.pb(row);
        }
        setA(a);
    }

    void print() const
    {
        for (auto row : a)
        {
            for (int i : row)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    status start;
    start.input();
    start.print();
    // H1

    // H2
    return 0;
}