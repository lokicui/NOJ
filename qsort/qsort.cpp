#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<typename T>
class TypeTraits {
private:
    template <class U> struct PointerTraits {
        enum {result = false};
        typedef U PointeeType;
    };
    template <class U> struct PointerTraits<U*> {
        enum {result = true};
        typedef U PointeeType;
    };
};
//从小到大

typedef class TNode {
public:
    TNode(): v(0.0) {}
    double v;
    double get_key() const {
        return v;
    }
}node_t;

template <typename T>
ssize_t partition(vector<T*> &v, ssize_t l, ssize_t r) {
    T* p = v[l];
    while (l < r) {
        while(l < r && p->get_key() <= v[r]->get_key())
            r --;
        if (l < r)
            swap(v[l], v[r]);
        while(l < r && v[l]->get_key() <= p->get_key())
            l ++;
        if (l < r)
            swap(v[l], v[r]);
    }
}

template <typename T>
ssize_t partition_inplace(vector<T*> &v, ssize_t l, ssize_t r, ssize_t p) {
    const T* pv = v[p];
    swap(v[p], v[r]);
    size_t idx = l;
    for (size_t i = l; i < r - 1; ++ i) {
        if (v[i]->get_key() < pv->get_key()) {
            swap(v[i], v[idx]);
            idx ++;
        }
    }
    swap(v[r], v[idx]);
    return idx;
}

template <typename T>
void quick_sort(vector<T*> &v, ssize_t l, ssize_t r) {
    if (v.empty() || r < l)
        return;
    if (r > l) {
        ssize_t p = partition(v, l, r);
        quick_sort(v, l, p - 1);
        quick_sort(v, p + 1, r);
    }
}

template <typename T>
void quick_sort(vector<T*> &v) {
    quick_sort(v, 0, v.size() - 1);
}

int main(){
    freopen("input.log", "r", stdin);
    vector<node_t*> v;
    int N(0);
    cin >> N;
    while (N--) {
        node_t *p = new node_t;
        cin >> p->v;
        v.push_back(p);
    }
    for (size_t i = 0; i < v.size();  ++ i) {
        cout << v[i]->v << endl;
    }
    cout << "------------------------------------" << endl;
    quick_sort<node_t>(v);
    for (size_t i = 0; i < v.size();  ++ i) {
        cout << v[i]->v << endl;
    }
}
