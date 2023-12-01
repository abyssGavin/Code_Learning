#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

char ch[2] = { 'L', 'O' };
unordered_map<string, int> mp;

int fun(string str) {
	if (mp.find(str) != mp.end()) return mp[str];
	if (str.size() < 3) {
		mp[str] = 0;
		return 0;
	}
	if (str.find("LO*") != string::npos || str.find("L*L") != string::npos || str.find("*OL") != string::npos) {
		mp[str] = 1;
		return 1;
	}
	if (str.find('*') == string::npos && str.find("LOL") == string::npos) {
		mp[str] = 0;
		return 0;
	}
	bool jud = false;
	int tmp;
	for (auto& it : str) {
		if (it == '*') {
			for (int i = 0; i < 2; i++) {
				it = ch[i];
				if (str.find("LO*") != string::npos || str.find("L*L") != string::npos || str.find("*OL") != string::npos) {
					it = '*';
					continue;
				}
				tmp = fun(str);
				it = '*';
				if (tmp == -1) {
					mp[str] = 1;
					return 1;
				}
				if (tmp == 0) jud = true;
			}
		}
	}
	if (jud) {
		mp[str] = 0;
		return 0;
	}
	mp[str] = -1;
	return -1;
}

int main() {
	int n, i;
	string str;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> str;
		cout << fun(str) << endl;
	}
}