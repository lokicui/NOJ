#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <vector>

using namespace std;


int levenshtein_dis(const string &a, const string &b) {
    vector< vector<int> > lev;
    for (int i = 0; i <= a.size(); ++ i) {
        lev.push_back(vector<int>());
        for (int j = 0; j <= b.size(); ++ j) {
            lev[i].push_back(0);
            if (min(i, j) == 0) {
                lev[i][j] = max(i, j);
            } else {
                char ac = a[i-1];
                char bc = b[j-1];
                //lev[i][j-1]   deletion
                //lev[i-1][j]   insertion
                //lev[i-1][j-1] match or mismatch
                int match = (ac == bc ? 0 : 1);
                lev[i][j] = min(lev[i-1][j] + 1, min(lev[i][j-1] + 1, lev[i-1][j-1] + match));
            }
        }
    }
    for (int i = 0; i <= a.size(); ++ i) {
        for (int j = 0; j <= b.size(); ++ j) {
                cout << lev[i][j] << " ";
        }
        cout << endl;
    }
    return lev[a.size()][b.size()];
}

int main(){
    freopen("input.log", "r", stdin);
    string a,b;
    cin >> a >> b;
    cout << "len(a)=" << a.size() << endl;
    cout << "len(b)=" << b.size() << endl;
    int total_len = a.size() + b.size();
    int diff_len = levenshtein_dis(a, b);
    int sim_len = total_len - 2 * diff_len;
    cout << "levenshtein_dis(" << a << ", " << b << ")=" << diff_len << ",sim_ratio=" << sim_len / float(total_len) << endl;
    return EXIT_SUCCESS;
}
