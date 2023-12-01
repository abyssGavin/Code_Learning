#include<iostream>
#include<cstring>
using namespace std;

char orilight[3], result[3];

void read(int i, int j)
{
    orilight[i] |= 1 << j;
}

void flip(int i, int j)
{
    result[i] ^= 1 << j;
}

int main()
{
    int i, j, num, count;
    char ch;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            cin >> num;
            if (num) read(i, j);
        }
    for (num = 0; num < 9; num++)
    {
        count = 0;
        ch = num;
        memcpy(result, orilight, sizeof(result));
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (!(ch >> j & 1))
                {
                    count++;
                    flip(i, j);
                    if (j > 0) flip(i, j - 1);
                    if (j < 2) flip(i, j + 1);
                    if (i < 2) flip(i + 1, j);
                }
            }
            ch = result[i];
        }
        if (result[2] == 7)
        {
            cout << count;
            break;
        }
    }
    system("pause");
    return 0;
}