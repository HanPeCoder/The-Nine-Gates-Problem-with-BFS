#ifndef UTILS
#define UTILS

#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include "Snode.h"
using namespace std;


vector<Snode> OPEN;
vector<Snode> CLOSED;

stack<Snode> result; 

// Judge new node
bool isnew(const Snode& snode)  //判断是否为新节点
{
	if (find(OPEN.begin(), OPEN.end(), snode) != OPEN.end()) {
        return false;
    }
    if (find(CLOSED.begin(), CLOSED.end(), snode) != CLOSED.end()) {
        return false;
    }
    return true;
}


int FIND(Snode& src, Snode& target) {
    // static int dp[4] = { -3,-1,1,3 }; //-3上，-1左，1右，3下
    static int dp[4] = { -3,-1, 3, 1 }; // 上左下右
    int p = 1;
    OPEN.push_back(src);
    while(!OPEN.empty()) {
        Snode n = *OPEN.begin();
        CLOSED.push_back(n);
        OPEN.erase(OPEN.begin());
        
        if (n.node() == target.node()) {
            return CLOSED.size();
        } else {
            // 扩展节点
            int zero_index = n.zero_index();
            for (int i = 0; i < 4; i++) {
                if (zero_index == 0 && (i == 0 || i == 1))  continue;     
                if (zero_index == 1 && i == 0)         continue;
                if (zero_index == 2 && (i == 0 || i == 3))  continue;
                if (zero_index == 3 && i == 1)         continue;
                if (zero_index == 5 && i == 3)         continue;
                if (zero_index == 6 && (i == 1 || i == 2))  continue;
                if (zero_index == 7 && i == 2)         continue;
                if (zero_index == 8 && (i == 2 || i == 3))  continue;
                int pos = zero_index+dp[i];
                string map = n.node();
                swap(map[zero_index], map[pos]);
                Snode* child = new Snode;
                child->In(map);
                if(isnew(*child)) {
                    child->idx = p;
                    child->parent = n.idx;
                    OPEN.push_back(*child);
                    p++;
                }
            }
        }

    }
    return 0;
}

#endif