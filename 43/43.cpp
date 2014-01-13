#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<double> &v, vector<bool> &used, const ssize_t expect, const ssize_t size){
    cout << "size=" << size << endl;
    //加减乘除后的值总是放在最后
    if (size == 1) {
        if (fabs(v[v.size() - 1] - expect) > 1E-10)
            return true;
        else
            return false;
    }
    for (ssize_t i = 0; i < v.size(); ++ i) {
        if (used[i])
            continue;
        used[i] = true;
        for (ssize_t j = i; j < v.size(); ++ j) {
            if (used[j])
                continue;
            used[j] = true;
            //任意取两个元素做加减乘除,把加减乘除后的结果放到队尾
            //队列的size --
            v.push_back(0);
            double &top = v[v.size() -1];
            top = v[i] + v[j];
            if (dfs(v, used, expect, size-1)){
                return true;
            }
            top = v[i] * v[j];
            if (dfs(v, used, expect, size-1)){
                return true;
            }
            top = v[i] - v[j];
            if (dfs(v, used, expect, size-1)){
                return true;
            }
            top = v[j] - v[i];
            if (dfs(v, used, expect, size-1)){
                return true;
            }
            top = v[i]/v[j];
            if (dfs(v, used, expect, size-1)){
                return true;
            }
            top = v[j]/v[i];
            if (dfs(v, used, expect, size-1)){
                return true;
            }
            v.pop_back();
            used[j] = false;
        }
        used[i] = false;
    }
    return false;
}

int main(){
    freopen("input.log", "r", stdin);
    ssize_t C(0);
    cin >> C;
    while (C--){
        ssize_t M(0), N(0);
        vector<double> v;
        vector<bool> used;
        cin >> M >> N;
        v.resize(M, 0);
        used.resize(100, false);
        for (size_t i = 0; i < M; ++ i){
            cin >> v[i];
        }
        if (dfs(v, used, N, M))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return EXIT_SUCCESS;
}
