#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define INF 0x3f3f3f3f;
#define n 10
using namespace std;
const int max_v=50;
int path[max_v][max_v];
 
typedef struct
{
    char name[20];
    char code[20];
    char intro[100];
}DataType;
 
typedef struct
{
    int num;
    DataType data;
}View;
 
typedef struct
{
    View view[max_v];
    int pl[max_v][max_v];
    int vexnum,arcnum;
}AMGraph;
 
void DisplayTu(){
    printf("***------------------ѧУƽ��ͼ--------------------***\n\n");
    printf("***                       ʵѵ¥(2)              ***\n");
    printf("***   ʪ�ع�԰(10)--------|   |---------������(3)  ***\n");
    printf("***        |                ͼ���(1)      |       ***\n");
    printf("***        ����(9)        |            |       ***\n");
    printf("***         |             ��ѧ¥(5)      |       ***\n");
    printf("***         |                 |            |       ***\n");
    printf("***   ����(8)                 |            |       ***\n");
    printf("***     |                     |            |       ***\n");
    printf("***     |                     ---------�һ���(4)   ***\n");
    printf("***     ---��ͨ��¥(7)---�԰(6)-------------|       ***\n\n");
    printf("***------------------------------------------------***\n\n");
    system("pause");
    system("cls");
}
 
void init(AMGraph &AM){
    int i=1;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"1");
    strcpy(AM.view[i].data.name,"ͼ���");
    strcpy(AM.view[i].data.intro,"ͼ��ݹ�ӭ�Ŷ��������������ѧУ�ı�־�Խ���.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"2");
    strcpy(AM.view[i].data.name,"ʵѵ¥");
    strcpy(AM.view[i].data.intro,"λ��ͼ���ǰ,�������Ź���,ʹ������ׯ��.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"3");
    strcpy(AM.view[i].data.name,"������");
    strcpy(AM.view[i].data.intro,"����Ľ������Ϊ�й������˱�����ɫ��.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"4");
    strcpy(AM.view[i].data.name,"�һ���");
    strcpy(AM.view[i].data.intro,"ǧ������,֯�ͻ����ƽ�,������������µ��⾳,����Ѱζ.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"5");
    strcpy(AM.view[i].data.name,"��ѧ¥");
    strcpy(AM.view[i].data.intro,"��ͬѧ���Ͽ�ѧϰ�ĵط�.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"6");
    strcpy(AM.view[i].data.name,"�԰");
    strcpy(AM.view[i].data.intro,"ӵ��һ��Сɽ��,���ڶ����.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"7");
    strcpy(AM.view[i].data.name,"��ͨ��¥");
    strcpy(AM.view[i].data.intro,"�ǵ��ӵ�������ѧԺ��ѧ������ʵ��ĵط����Լ���ʦ�İ칫��.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"8");
    strcpy(AM.view[i].data.name,"����");
    strcpy(AM.view[i].data.intro,"��ͼ���ǰ�����´���,�Ա���������������������кܶ����.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"9");
    strcpy(AM.view[i].data.name,"����");
    strcpy(AM.view[i].data.intro,"��ͬѧ��˯����Ϣ�ĵط�.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"10");
    strcpy(AM.view[i].data.name,"ʪ�ع�԰");
    strcpy(AM.view[i].data.intro,"�к�ˮ�ͺܶ���ľ,��������,�羰����.");
    for(int j=1;j<=i;j++)
        for(int k=1;k<=i;k++){
            if(k==j)
                AM.pl[j][k]=0;
            else
                AM.pl[j][k]=INF;
            path[j][k]=k;
        }
    AM.pl[1][2]=AM.pl[2][1]=50;
    AM.pl[1][3]=AM.pl[3][1]=300;
    AM.pl[2][3]=AM.pl[3][2]=200;
    AM.pl[2][10]=AM.pl[10][2]=460;
    AM.pl[1][5]=AM.pl[5][1]=200;
    AM.pl[1][10]=AM.pl[10][1]=400;
    AM.pl[3][5]=AM.pl[5][3]=800;
    AM.pl[3][4]=AM.pl[4][3]=900;
    AM.pl[4][5]=AM.pl[5][4]=400;
    AM.pl[5][10]=AM.pl[10][5]=500;
    AM.pl[5][9]=AM.pl[9][5]=400;
    AM.pl[5][6]=AM.pl[6][5]=700;
    AM.pl[8][10]=AM.pl[10][8]=150;
    AM.pl[8][9]=AM.pl[9][8]=100;
    AM.pl[6][8]=AM.pl[8][6]=260;
    AM.pl[6][7]=AM.pl[7][6]=50;
    AM.pl[6][4]=AM.pl[4][6]=1000;
    AM.pl[7][8]=AM.pl[8][7]=200;
    AM.pl[9][10]=AM.pl[10][9]=50;
}
 
void Display(AMGraph AM){
    printf("������ȫ������Ĵ��źͱ��:\n\n");
    printf("����\t\t����\n");
    for(int i=1;i<=n;i++)
        printf("%s\t\t%d\n",AM.view[i].data.code,AM.view[i].num);
    printf("\n");
}
 
void Edit(AMGraph &AM){
    printf("��ӭ�༭������Ϣ��\n");
    Display(AM);
    printf("������Ҫ�༭�ľ���Ĵ���:\n");
    char q[20];
    cin>>q;
    for(int i=1;i<=n;i++){
        if(strcmp(AM.view[i].data.code,q)==0){
            printf("�������µľ�����Ϣ��\n");
            printf("[��ʾ:���� ���š����ơ�����˳������!]\n\n");
            cin>>AM.view[i].data.code;
            cin>>AM.view[i].data.name;
            cin>>AM.view[i].data.intro;
            printf("�޸ĳɹ���\n\n");
        }
    }
    system("pause");
    system("cls");
}
 
void Query(AMGraph AM){
    printf("��ӭ��ѯ������Ϣ��\n");
    Display(AM);
    printf("������Ҫ��ѯ�ľ���Ĵ��ţ�\n\n");
    char q[20];
    cin>>q;
    for(int i=1;i<=n;i++){
        if(strcmp(AM.view[i].data.code,q)==0){
            printf("�þ���ľ�����Ϣ����:\n");
            printf("����:%s\n",AM.view[i].data.name);
            printf("���:%s\n\n",AM.view[i].data.intro);
        }
    }
    system("pause");
    system("cls");
}
 
void ShortestPath(AMGraph AM){
    printf("��ӭ��ѯ����·����\n");
    Display(AM);
    printf("������Ҫ��ѯ��������ı��:\n");
    int a,b;
    scanf("%d%d",&a,&b);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(AM.pl[i][k]+AM.pl[j][k]<AM.pl[i][j]){
                    AM.pl[i][j]=AM.pl[i][k]+AM.pl[j][k];
                    path[i][j]=path[i][k];
                }
            }
    int sum=0,t;
    printf("����ѯ�ľ��� %s �� %s ֮������·��Ϊ:\n",AM.view[a].data.name,AM.view[b].data.name);
    while(a!=b){
        printf("%s->",AM.view[a].data.name);
        t=a;
        a=path[a][b];
        sum+=AM.pl[t][a];
    }
    printf("%s\n\n",AM.view[b].data.name);
    printf("������֮���·������Ϊ:%dm\n\n",sum);
    system("pause");
    system("cls");
}
 
void Menu(){
    printf("--------У԰������ѯ--------\n\n");
        printf("       1.����ƽ��ͼչʾ.\n");
        printf("       2.������Ϣ�޸�.\n");
        printf("       3.������Ϣ��ѯ.\n");
        printf("       4.����·����ѯ.\n");
        printf("       5.�˳�.\n\n");
        printf("------------------------------\n\n");
}
 
int main()
{
    AMGraph AM;
    init(AM);
    while(1){
        Menu();
        printf("��ѡ����:\n\n");
        int a;
        scanf("%d",&a);
        if(a==5){
            printf("---------------------\n");
            printf("ллʹ�ã���;��죡\n");
            printf("---------------------\n");
            break;
        }
        else if(a!=1&&a!=2&&a!=3&&a!=4){
            printf("��������ѡ�񲻷���Ҫ�����������룡\n");
            continue;
        }
        switch(a){
            case 1:DisplayTu();break;
            case 2:Edit(AM);break;
            case 3:Query(AM);break;
            case 4:ShortestPath(AM);break;
        }
    }
    return 0;
}
 
 
 
