#include<iostream>
using namespace std;

struct student
{
	char name[20];
	int score;
};

int main()
{
	student s;
	//FILE* fpIn = fopen("D:\\vs project\\w.txt", "wb");
	//while (cin >> s.name >> s.score)
	//	fwrite(&s, sizeof(s), 1, fpIn);
	//fclose(fpIn);
	FILE* fpOut = fopen("D:\\vs project\\w.txt", "rb");
	while (fread(&s, sizeof(s), 1, fpOut))
		cout << s.name << " " << s.score << endl;
	fclose(fpOut);
	return 0;
}