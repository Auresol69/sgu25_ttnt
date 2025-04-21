#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Column
{
private:
    vector<int> arr;

public:
    Column()
    {
    }

    bool check(const int &x)
    {
        if (arr.size() == 0)
        {
            arr.push_back(x);
            return true;
        }
        if (arr[arr.size() - 1] > x)
        {
            arr.push_back(x);
            return true;
        }
        return false;
    }

    void setArr(const vector<int> &arr)
    {
        this->arr = arr;
    }
    vector<int> getArr() const
    {
        return this->arr;
    }

    void output()
    {
        if (arr.empty())
        {
            cout << 0 << endl;
            return;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    srand(time(NULL));

    vector<Column> v(3);

    int n = rand() % 14 + 3;

    vector<int> a_tmp;
    for (int i = n; i >= 1; i--)
    {
        a_tmp.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = rand() % 3;
        if (!v[tmp].check(a_tmp[i]))
        {
            i--;
        }
    }

    freopen("HNtower2.txt", "w", stdout);

    cout << n << endl;

    for (Column x : v)
    {
        x.output();
    }

    return 0;
}