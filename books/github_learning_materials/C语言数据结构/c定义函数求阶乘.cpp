/*��׳����⡣
����һ��������n�����n��*/

#include <stdio.h>                      //����Ԥ��������

int fun(int n);                   //��������

int main(int argc, char const *argv[])  //������
{
    int n; 
	printf("Input n:");                         //��������
    scanf("%d", &n);                    //����һ������
    printf("%d!=%d\n",n, fun(n));       //���ú�������׳�

    return 0;
}

int fun(int n)                    //�������n���ĺ���
{
    int fact = 1;

    for (int i = 1; i <= n; ++i) //����1��n 
    {
        fact = fact*i;
    }

    return fact;
}
