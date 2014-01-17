#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<double> &v, vector<bool> &used, ssize_t top, const ssize_t expect, const ssize_t size){
    //cout << "size=" << size << endl;
    //加减乘除后的值总是放在最后,标记为top
    if (size == 1) {
        if (fabs(v[top] - expect) < 1E-5){
            //cout << "top=" << v[top] << ",expect=" << expect << endl;
            return true;
        } else {
            return false;
        }
    }
    for (ssize_t i = 0; i <= top; ++ i) {
        if (used[i])
            continue;
        used[i] = true;
        for (ssize_t j = i; j <= top; ++ j) {
            if (used[j])
                continue;
            used[j] = true;
            //任意取两个元素做加减乘除,把加减乘除后的结果放到队尾
            //队列的size --
            double a = v[i], b = v[j];
            double &topv = v[++ top];
            topv = a + b;
            if (dfs(v, used, top, expect, size-1)){
                return true;
            }
            topv = a * b;
            if (dfs(v, used, top, expect, size-1)){
                return true;
            }
            topv = a - b;
            if (dfs(v, used, top, expect, size-1)){
                return true;
            }
            topv = b - a;
            if (dfs(v, used, top, expect, size-1)){
                return true;
            }
            topv = a / b;
            if (dfs(v, used, top, expect, size-1)){
                return true;
            }
            topv = b / a;
            if (dfs(v, used, top, expect, size-1)){
                return true;
            }
            topv = 0;
            top -- ;
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
        v.resize(M*10, 0);
        used.resize(M*10, false);
        for (size_t i = 0; i < M; ++ i){
            cin >> v[i];
        }
        if (dfs(v, used, M - 1, N, M))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return EXIT_SUCCESS;
}
