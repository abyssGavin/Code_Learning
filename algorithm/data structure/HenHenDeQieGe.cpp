//狠狠的切割
#include<iostream>
#include<map>
#include<set>
using namespace std;

int read()
{
    int i = 0, minus = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') minus = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {i = i * 10 + (ch - '0'); ch = getchar();}
    return i * minus;
}

int main()
{
    multimap<int, int> mp;
    set<int> st;
    int n1, n2, i, j, num, count = 1;
    multimap<int, int>::iterator it_mp = mp.begin();
    set<int>::iterator it_st_f, it_st_n;
    pair<multimap<int, int>::iterator, multimap<int, int>::iterator> re;
    n1 = read(); n2 = read();
    for(i = 1; i <= n1; i++)
    {
        num = read();
        mp.insert(make_pair(num, i));
    }   
    for(i = 1; i <= n2; i++)
    {
        num = read();
        re = mp.equal_range(num);
        for(it_mp = re.first; it_mp != re.second; it_mp++)
            st.insert(it_mp->second);
    }
    if(*st.begin() == 1) count--;
    if(*(st.rbegin()) == n1) count--;
    for(it_st_n = st.begin(), it_st_f = ++st.begin(); it_st_f != st.end(); it_st_n = it_st_f++)
        if(*it_st_f == *it_st_n || *it_st_f == *it_st_n + 1) st.erase(it_st_n);
    cout << st.size() + count;
}