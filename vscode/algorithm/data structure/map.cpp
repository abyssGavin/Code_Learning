#include<iostream>
#include<map>
#include<string>
using namespace std;

struct num
{
    int pos;
    int value;
};

map<int, int> N;

int main()
{
    num ele[5] = {1,11,2,22,3,33,4,44,5,55};
    int i;
    for(i = 0; i < 5; i++)
        N.insert(make_pair(ele[i].pos, ele[i].value)); 
    map<int, int>::iterator it;
    pair<int, int> a ;
    a = make_pair(6, 66);
    N.insert(a);
    it = N.find(2);
    cout << it->second << endl;
    cout<< N[6] << endl;
    return 0;
}