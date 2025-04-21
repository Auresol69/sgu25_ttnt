#include <bits/stdc++.h>
#define el cout << '\n'
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define pb push_back
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
const ll oo = LLONG_MAX >> 1;

struct node
{
    ll value, id;
    node() {}
    node(ll value, ll id) : value(value), id(id) {}
    bool operator<(const node &x) const
    {
        return value > x.value;
    }
};

ll n, m, st, ed;
set<ll> close;
priority_queue<node> open;
vector<ll> f, h, p, g, tour;
vector<vector<ll>> a;

void solve()
{
    g[st] = 0;
    f[st] = g[st] + h[st];
    open.push(node(f[st], st));

    while (!open.empty())
    {
        ll curr = open.top().id;
        open.pop();

        if (close.count(curr))
            continue;
        else
            close.insert(curr);

        if (curr == ed)
            break;

        f1(i, n) if (a[curr][i] != oo)
        {
            if (close.count(i))
                continue;
            if (g[i] > g[curr] + a[curr][i])
            {
                g[i] = g[curr] + a[curr][i];
                f[i] = g[i] + h[i];
                p[i] = curr;
                open.push(node(f[i], i));
            }
        }
    }
}

int main()
{
    freopen("graph2.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    cin >> n >> st >> ed;
    f.resize(n + 7, oo);
    g.resize(n + 7, oo);
    h.resize(n + 7, oo);
    p.resize(n + 7, -1);
    a.resize(n + 7, vector<ll>(n + 7, oo));

    f1(i, m)
    {
        ll u, v, k;
        cin >> u >> v >> k;
        a[u][v] = k;
        a[v][u] = k;
    }

    f1(i, n) f1(j, n)
    {
        cin >> a[i][j];
        if (a[i][j] == 0)
            a[i][j] = oo;
    }

    f1(i, n) cin >> h[i];
    solve();

    ll x = ed;
    while (p[x] != -1)
    {
        tour.pb(x);
        x = p[x];
    }

    tour.pb(x);
    reverse(all(tour));

    cout << g[ed], el;
    cout << tour.size(), el;
    for (ll x : tour)
        cout << x << ' ';

    return 0;
}
