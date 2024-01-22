#ifndef SNODE
#define SNODE


#include <iostream>
using namespace std; 


class Snode
{
private:
    string map;
    int max;
public:
    int parent;
    int idx;
    Snode& operator= (const Snode& rt);
    const string node() const { return map; }
    int zero_index();
    void In(string d);
    void Out();
    Snode(/* args */);
    Snode(string d);
    Snode(const Snode& snode);
    ~Snode();
};

Snode::Snode(/* args */)
    :map(""), max(9), idx(-1)
{
}

Snode::Snode(string d) {
    map = d;
}

Snode::Snode(const Snode& snode) {
    map = snode.map;
    parent = snode.parent;
    max = snode.max;
    idx = snode.idx;
}

Snode::~Snode()
{
}

inline void Snode::In(string d) {
    map = d;
}

inline void Snode::Out() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << map[3*i+j] << ' ';
        }
        cout << endl;
    }
}

inline int Snode::zero_index() {
    for (int i = 0; i < max; i++) {
        if (map[i] == '0') {
            return i;
        }
    }
    return -1;
}


inline Snode& Snode::operator=(const Snode& rt) {
    if (this == &rt) { // 先判断是否相等，避免重复赋值
        return *this;
    }
    map = rt.map;
    max = rt.max;
    parent = rt.parent;
    idx = rt.idx;
    return *this;
}

bool operator==(const Snode& lt, const Snode& rt){
    if (lt.node() == rt.node()) {
        return true;
    }
    return false;
}

#endif