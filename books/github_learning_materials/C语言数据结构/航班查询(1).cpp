#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

struct SLNode
{
   char start[10]; //���
   char end [10];//�յ�
   char sche[10];//����
   char time1[6];//���ʱ��
   char time2[6];//����ʱ��
   char model[4];//����
   int price;//Ʊ��
   char keys[6]; //�ؼ��֣�����ţ�
};//�����¼����
//��̬����ڵ�����


typedef struct
{ 
   SLNode *sl;//��̬����
   int listsize;//����
   int length;//��ǰ��
}SLList;//˳�������


//��ʾһ�������¼����
void Display(SLList L,int i)
{
   printf("����� ���վ �յ�վ ������ ���ʱ�� ����ʱ�� ���� Ʊ��\n");
   printf("%6s\t%6s\t%6s\t%6s\t%6s\t%6s\t%4s\t%d\n",L.sl[i].keys,L.sl[i].start,L.sl[i].end,L.sl[i].sche,L.sl[i].time1,L.sl[i].time2,L.sl[i].model,L.sl[i].price);
}


//˳����Һ���
void SeqSearch(SLList L,char key[],int i)
{
    int k,j,m=0;
    for(j=1;j<=L.length;j++)
{
       switch(i)
    {
        case 1:
             k=strcmp(key,L.sl[j].keys);
              break;
           case 2:
                k=strcmp(key,L.sl[j].start);
                break;//���վ
           case 3:
                k=strcmp(key,L.sl[j].end);
                break;//�յ�վ
           case 4:
                k=strcmp(key,L.sl[j].time1);
                break;//���ʱ��
           case 5:
                k=strcmp(key,L.sl[j].time2);
                break;//����ʱ��
    }

      if(k==0)
   {
           m=1;
           Display(L,j);
   }
}
    if(m==0)
{
        printf("�޴˺�����Ϣ���������������\n"); 
}
}



void del(SLList &L,char key[],int i)
{
    int k,j,m=0;
char ch;
    for(j=1;j<=L.length;j++)
{
       switch(i)
    {
        case 1:
             k=strcmp(key,L.sl[j].keys); break;
           case 2:
                k=strcmp(key,L.sl[j].start);break;//���վ
           case 3:
                k=strcmp(key,L.sl[j].end);break;//�յ�վ
           case 4:
                k=strcmp(key,L.sl[j].time1);break;//���ʱ��
           case 5:
                k=strcmp(key,L.sl[j].time2);break;//����ʱ��
    }

      if(k==0)
   {
           m=1;
           Display(L,j);
     printf("�Ƿ�ɾ���˼�¼��Y/N:");    
     scanf("%c",&ch);
     getchar();
     if(ch=='Y'||ch=='y')
     {
      strcpy(L.sl[j].keys,L.sl[L.length].keys);
      strcpy(L.sl[j].end,L.sl[L.length].end);    
               strcpy(L.sl[j].model,L.sl[L.length].model);
      L.sl[j].price=L.sl[L.length].price;
      strcpy(L.sl[j].sche,L.sl[L.length].sche);
      strcpy(L.sl[j].start,L.sl[L.length].start);
      strcpy(L.sl[j].time1,L.sl[L.length].time1);
      strcpy(L.sl[j].time2,L.sl[L.length].time2);
      L.length = L.length-1;;
      printf("ɾ���ɹ�!!\n");
     }
   }
}
    if(m==0)
{
        printf("�޴˺�����Ϣ���������������\n"); 
}
}




//��ѯ�����˵����Ƴ���
void serachcon(SLList L) 
{
   int i=1;
   char key[10],kl[8];
   while(1)
   {
    printf("****************************\n");
       printf("*     ������Ϣ��ѯϵͳ     *\n");
       printf("****************************\n");
       printf("*        1.�� �� ��        *\n");
       printf("*        2.�� �� վ        *\n");
       printf("*        3.�� �� վ        *\n");
       printf("*        4.���ʱ��        *\n");
       printf("*        5.����ʱ��        *\n");
       printf("*        0.��    ��        *\n");
       printf("****************************\n");
       printf("*         ������(0��5):");
       scanf("%d",&i);
    getchar();
   if(i>=0 && i<=5)
   {
          
          switch(i)
    {
             case 1 :
                  printf("������Ҫ��ѯ�ĺ���ţ���ĸҪ��д��:");
             scanf("%s",key); 
             getchar();
              SeqSearch(L,key,i);
             break;
             case 2 :
                  printf("������Ҫ��ѯ�ĺ������ʼվ��:");
             scanf("%s",key);
             getchar(); 
             SeqSearch(L,key,i);
             break;
             case 3 :
                  printf("������Ҫ��ѯ�ĺ�����յ�վ��:");
             scanf("%s",key);
             getchar(); 
             SeqSearch(L,key,i);
             break;
             case 4 :
                  printf("������Ҫ��ѯ�ĺ�������ʱ��:");
             scanf("%s",kl);
             getchar(); 
             SeqSearch(L,kl,i);
             break;
             case 5 :
                  printf("������Ҫ��ѯ�ĺ���ĵ���ʱ��:");
             scanf("%s",kl);
             getchar(); 
             SeqSearch(L,kl,i);
             break;
             case 0 :
                  return ;
    }
   }
else
    printf("���������Ϣ����!\n");

   
}
}



//���뺽���¼����
void InputData(SLList &L)
{

     int i;
char yn='y';
while(yn=='y'||yn=='Y')
{ 
   if(L.listsize<=L.length)
   {
      SLNode *newbase;
      newbase = (SLNode *)realloc(L.sl,(L.listsize+100)*sizeof(SLNode));
      if(!newbase)
    {
        printf("�洢����ʧ��");
        return;
    } //�洢����ʧ��
      L.sl = newbase;    //�»�ַ
      L.listsize += 100; //���Ӵ洢����
   }
         i=++L.length;
         printf("����� ���վ �յ�վ ������ ���ʱ�� ����ʱ�� ���� Ʊ��\n");
         scanf("%s %s %s %s %s %s %s %d",L.sl[i].keys,L.sl[i].start,L.sl[i].end,L.sl[i].sche,L.sl[i].time1,L.sl[i].time2,L.sl[i].model,&L.sl[i].price);        
         printf("����������?y/n:");
   getchar();
         scanf("%c",&yn);
   getchar();
}
}


void menu()
{ 
    printf("**********************************\n");
       printf("*     ������Ϣ��ѯ�����ϵͳ     *\n");
       printf("**********************************\n");
       printf("*       1.�� �� �� �� �� Ϣ      *\n");
       printf("*       2.ɾ �� �� �� �� Ϣ      *\n");
       printf("*       3.��   ѯ    �� Ϣ      *\n");
       printf("*       4.�� ʾ ȫ �� �� ¼      *\n");
       printf("*       0.��             ��      *\n");
       printf("**********************************\n");
       printf("*         ������(0��4):");    
}



void del_SNode(SLList &L)
{
getchar();
if(L.length>0)
{
       int i;
    char key[10],kl[8];
    while(1)
    {
      printf("*************************************\n");
         printf("*          ������Ϣɾ��ϵͳ         *\n");
         printf("*************************************\n");
         printf("*        1. �� �� �� �� ɾ ��       *\n");
         printf("*        2. �� �� �� վ ɾ ��       *\n");
         printf("*        3. �� �� �� վ ɾ ��       *\n");
         printf("*        4. �� ���ʱ�� ɾ ��       *\n");
         printf("*        5. �� ����ʱ�� ɾ ��       *\n");
         printf("*        0. ��             ��       *\n");
         printf("*************************************\n");
         printf("*         ������(0��5):");
      scanf("%d",&i);
   getchar();
   
      if(i>=0 && i<=5)
   {
          
           switch(i)
     {
             case 1 :
                  printf("������Ҫɾ���ĺ���ţ���ĸҪ��д��:");
             scanf("%s",key); getchar(); del(L,key,i);
             break;
             case 2 :printf("������Ҫɾ���ĺ������ʼվ��:");
             scanf("%s",key); getchar();del(L,key,i);
             break;
             case 3 :printf("������Ҫɾ���ĺ�����յ�վ��:");
             scanf("%s",key); getchar();del(L,key,i);
             break;
             case 4 :printf("������Ҫɾ���ĺ�������ʱ��:");
             scanf("%s",kl); getchar();del(L,kl,i);
             break;
             case 5 :printf("������Ҫɾ���ĺ���ĵ���ʱ��:");
             scanf("%s",kl); getchar();del(L,kl,i);
             break;
             case 0 :return ;
     }
   }
      else
         printf("���������Ϣ����!\n");
    }
}
else printf("û�м�¼!\n");
}



void displayall(SLList L)
{
if(L.length>0)
{
      printf(" ����� ���վ  �յ�վ  ������  ���ʱ��  ����ʱ�� ���� Ʊ��\n");   
         for(int i=1;i<=L.length;i++)
   {
          printf("%6s\t%6s\t%6s %6s  %6s    %6s  %4s  %d\n",L.sl[i].keys,L.sl[i].start,L.sl[i].end,L.sl[i].sche,L.sl[i].time1,L.sl[i].time2,L.sl[i].model,L.sl[i].price);
   }
}
else printf("û�м�¼!\n");
}


int main()
{
int i;
SLList L;
L.sl=(SLNode *)malloc(100*sizeof(SLNode));
L.listsize=100;
L.length=0;
system("color 1f"); 
printf("*��ӭ���뺽����Ϣ��ѯ�����ϵͳ!!!*\n"); 
while(1)
{
   menu();
   scanf("%d",&i);
   if(i <= 4&&i >= 0)
      {
    switch(i)
    {
          case 1: InputData(L);break;
             case 2: del_SNode(L);break;          
          case 3: serachcon(L);break;
          case 4: displayall(L);break;
          case 0: printf("ллʹ�ã��� ��!\n");break;
    }
   }
   else printf("���������Ϣ����!\n");
}
}
