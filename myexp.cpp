#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

int main(int argc, char const *argv[])
{
    srand((int)time(0));
    ofstream fcout;
    fcout.open("result100.txt", ios::out | ios::trunc);
    if (!fcout.is_open())
    { // 判断文件是否打开失败
        cout << "文件打开失败！" << endl;
        system("pause");
        exit(-1);
    }
    vector<pair<string, string>> smps;
    for (int i = 0; i < 100; i++)
    {
        string s = "012345678";
        string t = "012345678";
        random_shuffle(s.begin(), s.end());
        random_shuffle(t.begin(), t.end());
        pair<string, string> sm(s, t);
        if (find(smps.begin(), smps.end(), sm) != smps.end())
        {
            i--;
            continue;
        }
        OPEN.clear();
        CLOSED.clear();
        smps.push_back(sm);
        fcout << "测试-" << i + 1 << endl;
        fcout << "Source: " << s << endl;
        fcout << "Target: " << t << endl;
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
        fcout << "---Start---" << endl;
        auto beforeTime = std::chrono::steady_clock::now();
        int e = FIND(src, target) - 1;
        auto afterTime = std::chrono::steady_clock::now();

        fcout << "总耗时: ";
        double duration_second = std::chrono::duration<double>(afterTime - beforeTime).count();
        fcout << duration_second << "秒" << endl;
        fcout << "迭代次数: " <<CLOSED.size()  << ' ' << (CLOSED.end()-1)->node() << endl;
        if (e == -1)
        {
            fcout << "求解失败\n" << endl;
            continue;
        }

        int step = 0;
        while (e != -1)
        {
            // result.push(CLOSED[e]);
            e = CLOSED[e].parent;
            step++;
        }

        fcout << "最少步骤：" << step << '\n' << endl;
    }
    fcout.close();
    return 0;
}
