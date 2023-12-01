#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define value 15, 0, 62, 91, 56, 77

struct rule
{
	int operator()(const int& a, const int& b) const
	{
		return a % 10 < b % 10;
	}
};

int main()
{
	int a[6] = {value};
	int i;
	multiset<int, rule> st;

	for(i = 0;i < 6; i++)
		st.insert(a[i]);
	multiset<int>::iterator it;
	for(it = st.begin(); it != st.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << binary_search(st.begin(), st.end(), 11) << endl;
	cout << *(lower_bound(st.begin(), st.end(), 11)) << endl;
	cout << *st.find(22) << " " << *st.find(33) << endl;
	st.erase(st.begin());
	for(it = st.begin(); it != st.end(); it++)
		cout << *it << " ";
	cout << endl;
	#ifdef value
		cout << "wa!" << endl;
	#endif
	set<int> st1;
	for(i = 0; i < 6; i++)
		st1.insert(a[i]);
	pair<multiset<int>::iterator, bool> result = st1.insert(88);
	cout << result.second << endl;
	cout << *st1.find(88);
	return 0;
}