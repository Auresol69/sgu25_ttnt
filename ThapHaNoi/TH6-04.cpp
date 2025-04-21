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

    Column a, b, c;

    int n = rand() % 14 + 3;

    vector<int> a_tmp;
    for (int i = 1; i <= n; i++)
    {
        a_tmp.push_back(i);
    }
    random_shuffle(a_tmp.begin(), a_tmp.end());
    for (int i = 0; i < n; i++)
    {
        if (!a.check(a_tmp[i]))
        {
            if (!b.check(a_tmp[i]))
            {
                c.check(a_tmp[i]);
            }
        }
    }

    cout << n << endl;

    a.output();
    b.output();
    c.output();

    return 0;
}