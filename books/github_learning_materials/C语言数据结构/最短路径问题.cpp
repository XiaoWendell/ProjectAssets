#include<stdio.h>
#include<stdlib.h>

#define INF 10000
#define LEN sizeof(struct hua)

char a[100][100];  //��ʾ�Թ����ַ�����
int n, m;          //��ʾ�Թ���С
int sx, sy;        //�������
int gx, gy;        //�յ�����
int wei[100][100];   //������λ�õ���̾��������
int ax, ay;              //ax��ayΪ�Ӷ���ǰ��ȡ���Ķ�Ӧֵ
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
struct hua
{
    int nx;
    int ny;
    struct hua *next;
};

int main()
{
    int bfs(struct hua * head);
    int i;
    int res;
    struct hua * head;
    scanf("%d %d",&n,&m);    //�����Թ���Сn*m
    scanf("%d %d",&sx,&sy);  //�������
    scanf("%d %d",&gx,&gy);  //�����յ�
    for(i=0;i<n;i++)
        scanf("%s",a[i]);
    head = (struct hua *) malloc(LEN);
    head->nx = sx;           //��������긳����һ��������������λ
    head->ny = sy;
    head->next = NULL;
    res = bfs(head);
    if(res == INF)
        printf("�޷�����");
    else
        printf("%d",res);
    return 0;
}

struct hua * push(int x, int y,struct hua * q)   //���ǰ��Ҫβָ��
{
    struct hua * p3;
    p3 = (struct hua *) malloc(LEN);
    p3->nx = x;
    p3->ny = y;
    q->next = p3;
    p3->next = NULL;
    return p3;            //���������βָ��
}

struct hua * pop(struct hua * w)       //ȡ����Ҫͷָ��
{
    struct hua * head;
    ax = w->nx;
    ay = w->ny;
    head = w->next;
    free(w);
    return head;          //���������ͷָ��
}



int bfs(struct hua * head)
{
    int i, j;
    struct hua * c = head, * d = head;         //c��λͷָ�룬d��λβָ��
    for(i=0;i<n;i++)        //�����е�λ�ö���ʼ��ΪINF
        for(j=0;j<m;j++)
            wei[i][j] = INF;
    wei[sx][sy] = 0;         //�������Ѽ������λ�ã����ｫ�����������Ϊ0
    while(c != NULL)   //����ѭ��ֱ��������Ԫ��
    {
        c = pop(c);
        if(ax == gx && ay == gy)
            break;
        for(i=0;i<4;i++)   //�ĸ�����ѭ��
        {
            int ux = ax + dx[i];
            int uy = ay + dy[i];   //�ƶ����λ�ü�ux��uy
            if(0<=ux && ux<n && 0<=uy && uy<m && a[ux][uy] != '#' && wei[ux][uy] == INF)   //�ж��Ƿ�����ƶ��Լ��Ƿ��Ѿ����ʹ�
            {
                if(c == NULL)
                {
                    c = d = (struct hua *) malloc(LEN);
                    c->nx = ux;
                    c->ny = uy;
                    d->next = NULL;
                }
                else
                d = push(ux, uy, d);
                wei[ux][uy] = wei[ax][ay] + 1;
            }
        }
    }
    return wei[gx][gy];
}

