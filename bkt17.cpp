// Tinca Matei VU Ansterdam
// BKT
#include <bits/stdc++.h>
 
std::ifstream fin("aventura.in");
std::ofstream fout("aventura.out");
void solve_test() {
    int N;
    fin >> N;
    std::vector<std::vector<int>> restr(1 + N);
    for (int i = 1; i <= N; i++) {
        int k;
        fin >> k;
        restr[i].resize(k);
        for (int j = 0; j < k; j++)
            fin >> restr[i][j];
    }
 
    std::vector<int> perm;
    for (int i = 1; i <= N; i++) perm.push_back(i);
 
    int res = 0;
    std::vector<bool> marked(1 + N);
    do {
        for (int i = 1; i <= N; i++)
            marked[i] = false;
 
        int solved = 0;
        for (auto it : perm) {
            marked[it] = true;
            for (auto x : restr[it])
                if (!marked[x])
                    marked[it] = false;
            if (marked[it])
                solved++;
        }
        res = std::max(res, solved);
    } while (std::next_permutation(perm.begin(), perm.end()));
 
    fout << res << "\n";
}
 
int main() {
    int T;
    fin >> T;
 
    while (T--) solve_test();
    return 0;
}