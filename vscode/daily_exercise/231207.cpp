#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {
  int i, j, arr[5][5] = {{12,35,3,9,0},{2,35,9,12,1},{35,12,0,1,9},{4,90,35,9,12},{11,9,0,12,35}};
  vector<int> v;
  unordered_map<int, int> mp;
  for(i = 0; i < 5; i++) {
    for(j = 0; j < 5; j++)
      mp[arr[i][j]]++;
  }
  for(auto it = mp.begin(); it != mp.end(); it++) 
    if(it->second == 5) v.push_back(it->first);
  vector<int>::reverse_iterator it;
  for(it = v.rbegin(); it != v.rend(); it++) 
    cout << *it << " "; 
  return 0;
}