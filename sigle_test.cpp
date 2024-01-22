#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

int main(int argc, char const *argv[])
{
    srand((int)time(0));

    string s = "207856341";  
    string t = "581340267";
    cout << "Source: " << s << endl;
    cout << "Target: " << t << '\n'
         << endl;
    Snode src;
    src.In(s);
    src.parent = -1;
    src.idx = 0;
    Snode target;
    target.In(t);
    target.parent = -1;
    cout << "---Start---" << endl;
    auto beforeTime = std::chrono::steady_clock::now();
    int e = FIND(src, target) - 1;
    auto afterTime = std::chrono::steady_clock::now();

    cout << "总耗时: ";
    double duration_second = std::chrono::duration<double>(afterTime - beforeTime).count();
	cout << duration_second << "秒" << endl;
    cout << "迭代次数: " <<CLOSED.size()  << ' ' << (CLOSED.end()-1)->node() << endl;
    if(e == -1) {
        cout << "求解失败\n" << endl;
        return -1;
    }
    int step = 0;
    while (e > -1)
    {
        // result.push(CLOSED[e]);
        e = CLOSED[e].parent;
        step++;
    }

    cout << "最少步骤：" << step << endl;
    return 0;
}
