#include<iostream>
using namespace std;

int main() {
	cout << "WA!" << endl;
	char arr[11] = { '1', '2', '3', '4', '5', '6', '7' , '8' , '9', '\0'};
	char(*parr)[11] = &arr;
	cout << parr << endl;
	printf("%s", parr);

}