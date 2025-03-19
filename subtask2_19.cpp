// OJI 2025 11-12 Ivan Andrei 
// Aventura 19 Subtask 2 
#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>  
    
#pragma GCC optimize("O3")  
#pragma GCC optimize("unroll-loops")  
#pragma GCC target("avx2")  
    
using namespace std;  
using namespace __gnu_pbds;  
    
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>  
#define lsb(x) (x & (-x))  
    
const long long mod = 1e9 + 7, max_size = 3e5 + 20;  
  
int adj[2005][2005], bad[2005]; 
vector <int> mc[max_size]; 
  
void dfs (int nod) 
{ 
    bad[nod] = 1; 
    for (auto f : mc[nod]) 
    { 
        if (bad[f] == 0) 
        { 
            dfs(f); 
        } 
    } 
} 
  
void solve()  
{  
    int n; 
    cin >> n; 
    assert(n <= 2000); 
    for (int i = 1; i <= n; i++) 
    { 
        bad[i] = 0; 
        mc[i].clear(); 
        for (int j = 1; j <= n; j++) 
        { 
            adj[i][j] = 0; 
        } 
    } 
    for (int i = 1; i <= n; i++) 
    { 
        int k; 
        cin >> k; 
        while(k--) 
        { 
            int x; 
            cin >> x; 
            assert(i != x); 
            adj[x][i] = 1; 
            mc[x].push_back(i); 
        } 
    } 
    for (int i = 1; i <= n; i++) 
    { 
        if (bad[i] == 1) 
        { 
            continue; 
        } 
        for (int j = 1; j <= n; j++) 
        { 
            if (adj[i][j] == 1 && adj[j][i] == 1) 
            { 
                dfs(i); 
                break; 
            } 
        } 
    } 
    int ans = 0; 
    for (int i = 1; i <= n; i++) 
    { 
        if (bad[i] == 0) 
        { 
            ans++; 
        } 
    } 
    cout << ans << '\n'; 
} 
    
signed main()  
{  
#ifdef LOCAL  
    freopen("test.in", "r", stdin);  
    freopen("test.out", "w", stdout);  
#else  
    freopen("aventura.in", "r", stdin);  
    freopen("aventura.out", "w", stdout);  
#endif // LOCAL  
    ios_base::sync_with_stdio(false);  
    cin.tie(0);  
    cout.tie(0);  
    long long tt;  
    cin >> tt;  
    //tt = 1;  
    while (tt--)  
    {  
        solve();  
    }  
    return 0;  
}