
#include"fun.h"
using namespace std;

void test1() {
	cout << "WA!" << endl;
	char arr[11] = { '1', '2', '3', '4', '5', '6', '7' , '8' , '9', '\0' };
	char(*parr)[11] = &arr;
	cout << parr << endl;
	printf("%s\n", parr);

}

void test3(int r, int c, int(*p)[5]) {
	cout << "TWO" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << p[i][j];
		}
		cout << endl;
	}
	cout << "THREE" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << *((*(p + i)) + j); //��΢���һ�£�����ͦ�򵥵ģ�������p��ָ���ָ��p[i]��ָ�������ָ������
		}
		cout << endl;
	}
}

void test2() {
	int r = 3, c = 5;
	int arr[3][5];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = i + j;
		}
	}
	cout << "ONE" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << *((*(arr + i)) + j); //��΢���һ�£�����ͦ�򵥵ģ�������p��ָ���ָ��p[i]��ָ�������ָ������
		}
		cout << endl;
	}
	test3(r, c, arr);
}

