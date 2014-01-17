#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include <iostream>

using namespace std;

uint32_t M[30001][26] = {0};
uint32_t knapsack(const vector<uint32_t> &vv, const vector<uint32_t> &vp, const uint32_t N) {
    //vector<vector<uint32_t> > M;
    //i 钱
    //j 物品
    for (ssize_t i = 0; i <= N; ++ i) {
        //M.push_back(vector<uint32_t>());
        for (ssize_t j = 0; j <= vv.size(); ++ j) {
            //M[i].push_back(0);
            if (min(i, j) == 0)
                continue;
            const uint32_t v = vv[j-1];
            const uint32_t p = vp[j-1];
            if (v <= i) {
                M[i][j] = max(M[i-v][j-1] + v*p, M[i][j-1]);
            } else {
                M[i][j] = M[i][j-1];
            }
        }
    }
#if 0
    for (ssize_t i = 0; i <= N; ++ i) {
        for (ssize_t j = 0; j <= vp.size(); ++ j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
#endif
    return M[N][vp.size()];
}

int main() {
    //freopen("input.log", "r", stdin);
    int G(0);
    cin >> G;
    while (G --) {
        memset(M, 0, sizeof(M));
        int N(0), m(0);
        cin >> N >> m;
        vector<uint32_t> vv, vp;
        for (int i = 0; i < m; ++ i) {
            int v(0), p(0);
            cin >> v >> p;
            vv.push_back(v);
            vp.push_back(p);
        }
        cout << knapsack(vv, vp, N) << endl;
    }
    return EXIT_SUCCESS;
}
