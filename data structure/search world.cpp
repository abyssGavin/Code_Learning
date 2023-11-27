#include<iostream>
#include<map>
#include<set>
#include<string>
#include<fstream>
using namespace std;

struct Word
{
    string wd;
    int num;
};

struct Rule
{
    bool operator()(const Word &w1, const Word &w2) const
    {
        if(w1.num == w2.num) return w1.wd.length() > w2.wd.length();
        return w1.num > w2.num;
    }
};

int main()
{
    ifstream in("D:\\vscode\\r.txt", ios::in);
    if(!in)
        cout << "ERROR";
    string s;
    map<string, int> mp;
    Word word;
    set<Word, Rule> st;
    while(getline(in, s))
        ++mp[s];
    in.close();
    map<string, int>::iterator it_mp;
    for(it_mp = mp.begin(); it_mp != mp.end(); it_mp++)
    {
        word.num = it_mp->second;
        word.wd = it_mp->first;
        st.insert(word);
    }
    set<Word, int>::iterator it_st;
    for(it_st = st.begin(); it_st != st.end(); it_st++)
        std::cout << it_st->wd << " " << it_st->num << endl;
    return 0;
}