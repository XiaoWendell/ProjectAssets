#include <stdio.h> 
#include <string.h>
int main() {
    int n, cnt = 0;
    char a[100], b[100];//������������ 
    double temp, sum = 0.0;
    
	scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);  //sscanf(); ��һ���ַ�������ȡ�������ݣ��������һ�����ַ������ո��Ʊ����س����ָ�������ַ��� 
        sprintf(b, "%.2lf",temp);//sscanf�����ַ��� sprintf������ת��Ϊ�ַ��� 
		printf(b, "%.2lf",temp);
        int flag = 0;
        for(int j = 0; j < strlen(a); j++) {
            if(a[j] != b[j]) flag = 1;
        }
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if(cnt == 1) {
        printf("The average of 1 number is %.2lf", sum);
    } else if(cnt > 1) {
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
    } else {
        printf("The average of 0 numbers is Undefined");
    }
    return 0;
}
