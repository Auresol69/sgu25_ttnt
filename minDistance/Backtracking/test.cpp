#include <iostream>
#include <vector>

using namespace std;

// input : n
int Input()
{
    int num;
    cin >> num;
    return num;
}

// find x in array X

void Output(const vector<int> &X, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
}

// backtracking
void Try(int i, const int &n, vector<bool> &visited, vector<int> &X)
{
    for (int j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            visited[j] = true;
            X[i] = j;
            if (i == n)
            {
                Output(X, n);
            }
            else
            {
                Try(i + 1, n, visited, X);
            }
            visited[j] = false;
        }
    }
}

int main()
{
    int n = Input();
    vector<bool> visited(n + 1, false);
    vector<int> X(n + 1, -1);
    Try(1, n, visited, X);
    return 0;
}