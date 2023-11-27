#include<iostream>
using namespace std;

bool noprime[100000];
int count;

void isprime(int i,int j)
{
  if(i > j) return;
  if(i < 2 || noprime[i]) 
    {
        isprime(i + 1, j);
        return;
    }
  int index, jud = 0;
  for(index = 2; index * index <= i; index++)
    if(i % index == 0)
      {
        jud = 1;
        break;
      }
  if(jud)
  {
    noprime[i] = true;
    for(index = i; index <= j; index += i)
      noprime[index] = true;
  }
  else count++;

  isprime(i + 1, j);
}

int main()
{
  int i, j, k = 1, sum = 0;
  cin >> i >> j;
  isprime(i, j);
  cout << count << " ";
  for(; i <= j; j--)
    if(!noprime[j])
      {
        sum += j * k;
        k = -k;
      }
      cout << sum;
      return 0;
}