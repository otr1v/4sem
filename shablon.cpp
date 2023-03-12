#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

template <typename T>
bool f1(vector<T> v, T x)
{
    bool flag = false;
    int size = v.size(); 
    for (int i = 0; i < size; i++)
    {
        if (v[i] == x)
        {
            flag = true;
        }
    }
    return flag;
}

//=============================
template <typename T1, typename T2, typename T3>
bool f1m(map<T1, T2> mp, T3 x)
{
    bool flag = false;
    for (auto i: mp)
    {
        if (i.first == x || i.second == x) flag = true;
    }
    return flag;
}

//==================================
template <typename T4, typename noname>

bool f2(vector<T4> v, noname no)
{
    bool flag = false;
    int size = v.size();
    if (size % 2 == 0) flag = true;
    return flag;
}

//======================================
template <typename T4, typename T5, typename n>

bool f2m(map<T4, T5> mp, n noname)
{
    bool flag = false;
    int size = mp.size();
    if (size % 2 == 0)  flag = true;
    return flag;
    
}

//===============================
class checker
{
    public:
        int counter = 0;
        template <typename foo, typename T6, typename container>

        void check(foo func, vector<container> m, T6 elem)
        {
            // flag = false;
            for (auto i: m)
            {
                if (func(i, elem) == true) counter++;
            }
            cout << counter << endl;
        }
};

int main()
{
    vector<vector<int>> v = {{1, 3, 44, 231}, {13, 48949, 4848843, 234, 211}, {1}};
    vector<map<string, string>> mp = {{{"vanya", "sosat"}, {"map", "sefds"}}, {{"auf", "vikativaet"}}};
    checker cl;
    cl.check(f1<int>, v, 3);
     cl.check(f2<int, int>, v, 3);
    cl.check(f1m<string, string, string>, mp, "va");
    cl.check(f2m<string, string, string>, mp, "vanya");
    return 0;
}
