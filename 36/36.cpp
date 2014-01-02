#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <map>
#include <list>

using namespace std;

static const uint32_t k_max_size = 1024;

int lcs(const string& lhs, const string& rhs) {
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

int lcs_op(const string& lhs, const string& rhs) {
    uint32_t a[k_max_size] = {0};
    for(size_t i = 0; i < lhs.size(); ++ i) {
        for (ssize_t j = rhs.size(); j >= 0; -- j) {
            if (lhs[i] == rhs[j]) {
                a[j+1] = a[j];
                //a[i+1][j+1] = a[i][j] + 1;
            } else {
                a[j+1] = max(a[j+1], a[j]);
                //a[i+1][j+1] = max(a[i][j+1], a[i+1][j]);
            }
        }
    }
    //return a[lhs.size()][rhs.size()];
    return a[rhs.size()];
}

int main(){
    freopen("input.log", "r", stdin);
    int N(0);
    cin >> N;
    while (N--) {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        cout << lcs(s1, s2) << endl;
    }
}

