#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

static const uint32_t k_max_size = 1024;

int lcs(const vector<int>& lhs, const vector<int>& rhs) {
    uint32_t a[k_max_size][k_max_size] = {0};
    for(size_t i = 0; i < lhs.size(); ++ i) {
        for (size_t j = 0; j < rhs.size(); ++ j) {
            if (lhs[i] == rhs[j]) {
                a[i+1][j+1] = a[i][j] + 1;
            } else {
                a[i+1][j+1] = max(a[i][j+1], a[i+1][j]);
            }
        }
    }
#if 0
    for(size_t i = 0; i < lhs.size(); ++ i) {
        for (size_t j = 0; j < rhs.size(); ++ j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
#endif
    return a[lhs.size()][rhs.size()];
}

int main(){
    freopen("input.log", "r", stdin);
    int N(0);
    cin >> N;
    while (N--) {
        int m(0);
        cin >> m;
        vector<int> s1, s2;
        set<int> s;
        while(m--){
            int k(0);
            cin >> k;
            s1.push_back(k);
            s.insert(k);
        }
        for (set<int>::const_reverse_iterator it = s.rbegin(); it != s.rend(); ++ it) {
            s2.push_back(*it);
            //cout << *it << endl;
        }
        cout << lcs(s1, s2) << endl;
    }
}

