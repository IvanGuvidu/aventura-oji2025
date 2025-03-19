// Ivan Andrei OJI 11-12 2025
#include <bits/stdc++.h>

using namespace std;

const int max_size = 5e5 + 20;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// subtask 1 bkt
// subtask 2 Ciclii din graf au lungime maxim 2
// subtask 3 n^2
// subtask 4 full

vector <int> req[max_size];

void genfull (int n)
{
    vector <int> v;
    for (int i = 2; i <= n; i++)
    {
        v.push_back(i);
        req[i].clear();
    }
    shuffle(v.begin(), v.end(), rng);
    vector <int> ccl;
    for (int i = 0; i < n / 2; i++) 
    {
        ccl.push_back(v.back());
        v.pop_back();
    }
    uniform_int_distribution<int> dist(1, n);
    vector <int> arb;
    arb.push_back(1);
    arb.push_back(v.back());
    v.pop_back();
    int x = dist(rng) % v.size() + 1;
    for (int i = 1; i <= x; i++)
    {
        arb.push_back(v.back());
        v.pop_back();
    }
    for (int i = 2; i < arb.size() - 1; i++)
    {
        req[arb[i]].push_back(arb[dist(rng) % i]);
        req[arb.back()].push_back(arb[i]);
    }
    for (int i = 0; i < ccl.size(); i++)
    {
        req[ccl[i]].push_back(ccl[(i + 1) % ccl.size()]);
        if (i % 4 == 0)
        {
            req[ccl[i]].push_back(arb[dist(rng) % arb.size()]);
        }
    }
    for (auto f : v)
    {
        req[f].push_back(ccl[dist(rng) % ccl.size()]);
        req[f].push_back(arb[dist(rng) % arb.size()]);
        ccl.push_back(f);
    }
    cout << n << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << req[i].size();
        for (int j = 0; j < req[i].size(); j++)
        {
            cout << " " << req[i][j];
        }
        if (i < n)
        {
            cout << '\n';
        }
    }
}

void genarb (int n)
{
    vector <int> v;
    for (int i = 2; i <= n; i++)
    {
        v.push_back(i);
        req[i].clear();
    }
    shuffle(v.begin(), v.end(), rng);
    uniform_int_distribution<int> dist(1, n);
    vector <int> arb;
    arb.push_back(1);
    arb.push_back(v.back());
    v.pop_back();
    int x = v.size();
    for (int i = 1; i <= x; i++)
    {
        arb.push_back(v.back());
        v.pop_back();
    }
    for (int i = 2; i < arb.size(); i++)
    {
        req[arb[i]].push_back(arb[dist(rng) % i]);
    }
    int bl = dist(rng) % (x/ 2) + 1;
    for (int i = 1; i <= x; i++)
    {
        if (i % bl == 0 && req[arb[i]][0] != 1)
        {
            req[req[arb[i]][0]].push_back(arb[i]);
            i++;
        }
    }
    cout << n << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << req[i].size();
        for (int j = 0; j < req[i].size(); j++)
        {
            cout << " " << req[i][j];
        }
        if (i < n)
        {
            cout << '\n';
        }
    }
}

void genlant (int n)
{
    for (int i = 1; i <= n; i++)
    {
        req[i].clear();
    }
    req[n].push_back(1);
    req[2].push_back(1);
    for (int i = n; i > 2; i--)
    {
        req[i - 1].push_back(i);
        req[2].push_back(i);
    }
    cout << n << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << req[i].size();
        for (int j = 0; j < req[i].size(); j++)
        {
            cout << " " << req[i][j];
        }
        if (i < n)
        {
            cout << '\n';
        }
    }
}

void solve (int n, int subtask)
{
    if (subtask == 1 || subtask == 3 || subtask == 4)
    {
        genfull(n);
    }
    if (subtask == 2)
    {
        genarb(n);
    }
    if (subtask == 5)
    {
        genlant(n);
    }
}

int main (int argc, char *argv[])
{
    int t = atoi(argv[1]), n = atoi(argv[2]), subtask = atoi(argv[3]);
    cout << t << '\n';
    for (int i = 1; i <= t; i++)
    {
        if (i == t && subtask == 4)
        {
            subtask++;
        }
        solve(n, subtask);
        cout << '\n';
    }
    return 0;
}