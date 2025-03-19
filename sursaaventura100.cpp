// OJI 2025 11-12 Ivan Andrei
// Aventura ASSERT 1+2+3+4
#include <bits/stdc++.h>

using namespace std;

const int max_size = 5e5 + 5;

vector <int> nxt[max_size];
int deg[max_size];
queue <int> q;

void solve ()
{
    int n;
    cin >> n;
    assert(n <= 500000);
    for (int i = 1; i <= n; i++)
    {
        nxt[i].clear();
    }
    int sumk = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        sumk += k;
        if (k == 0)
        {
            q.push(i);
        }
        deg[i] = k;
        assert(deg[i] >= 0);
        while (k--)
        {
            int x;
            cin >> x;
            nxt[x].push_back(i);
            assert(x != i);
        }
    }
    assert(sumk <= 4 * n);
    int ans = 0;
    while (!q.empty())
    {
        int nod = q.front();
        q.pop();
        ans++;
        for (auto f : nxt[nod])
        {
            deg[f]--;
            if (deg[f] == 0)
            {
                q.push(f);
            }
        }
    }
    cout << ans;
    cout << '\n';
}

int main ()
{
    #ifdef LOCAL
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #else
        freopen("aventura.in", "r", stdin);
        freopen("aventura.out", "w", stdout);
    #endif
    int t;
    cin >> t;
    assert(t <= 5);
    while (t--)
    {
        solve();
    }
    return 0;   
}