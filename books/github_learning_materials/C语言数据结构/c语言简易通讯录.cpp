#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef  struct NODE
{
	int bh;
	char* name;
	char* phone;
	struct NODE* pnext;
}Node;
int GetBh();//��ñ��
char* GetName();//�������
char* GetPhone();//��õ绰
Node* GetNode();//��ýڵ�
char* GetString();//�ֶ������Ϣ
Node* GetNodeIn();//�ֶ���ýڵ�
char GetKey();//��ùؼ���

void AddNode(Node** phead,Node** pend,Node* node);//��ӽڵ�
void InsertNode(Node** phead,Node** pend,Node* node,int bh);//����ڵ�
void DelNode(Node** phead,Node** pend,int bh);//ɾ���ڵ�
void GenerateInfo(Node** phead,Node** pend,int count);//������Ϣ

typedef struct PAGE
{
	int currentPage;
	int ItemPerPage;
	int totalPage;
	int totalItem;
}Page;
Page* GetPage(Node* phead);//ͳ�Ʒ�ҳ��Ϣ
void ShowMenu(Page* page);//��ʾ��ҳ�˵�
void ShowInfo(Node* phead,Page* page);//��ҳ��ʾ��Ϣ
void TurnPage(Node* phead,Page* page);//���·�ҳ

void ShowHomeMenu();//��ʾ���˵�
void LookBook(Node* phead);//�鿴
void FindBook(Node* phead);//��ѯ
void DelBook(Node* phead,Node* pend);//ɾ��
void ChangeBook(Node* phead);//�޸�


int g_key;
int g_menu_type;
int main()
{
	Node* head=NULL;
	Node* end=NULL;

	srand((unsigned int)(time(0)));
	GenerateInfo(&head,&end,60);

	while(1)
	{
		ShowHomeMenu();
		switch(GetKey())
		{
			case '1':
				g_menu_type=1;
				LookBook(head);
				break;
			case '2':
				AddNode(&head,&end,GetNodeIn());
				break;
			case '3':
				g_menu_type=3;
				FindBook(head);
				break;
			case '4':
				g_menu_type=4;
				DelBook(head,end);
				break;
			case '5':
				g_menu_type=5;
				ChangeBook(head);
				break;
			case 'q':
				return 0;
				break;		
		}	
	}
	return 0;
}
int GetBh()//��ñ��
{
	static int i=1;
	return i++;
}
char* GetName()//�������
{
	char*name=(char*)malloc(6);
	int i;
	for(i=0;i<5;i++)
	{
		name[i]=rand()%25+'a';		
	}
	name[5]=0;
	return name;
}
char* GetPhone()//��õ绰
{
	int i;
	char* phone=(char*)malloc(12);
	switch(rand()%4)
	{
	case 0:
		strcpy(phone,"137");
		break;
	case 1:
		strcpy(phone,"139");
		break;
	case 2:
		strcpy(phone,"150");
		break;
	case 3:
		strcpy(phone,"159");
		break;
	}
	for(i=3;i<11;i++)
	{
		phone[i]=rand()%10+'0';
	}
	phone[11]=0;
	return phone;
}
Node* GetNode()//��ýڵ�
{
	Node* node=(Node*)malloc(sizeof(Node));
	node->bh=GetBh();
	node->name=GetName();
	node->phone=GetPhone();
	node->pnext=NULL; 
	return node;
}
char* GetString()//�ֶ������Ϣ
{
	char* str=(char*)malloc(5);
	int size=5;
	char* bj=str;
	char c;
	int count=0;
	char* newstr=NULL;

	while((c=getchar())!='\n')
	{
		*str=c;
		str++;
		count++;
		if(count+1==size)
		{
			size+=5;
			newstr=(char*)malloc(size);
			strcpy(newstr,bj);
			free(bj);
			bj=newstr;
			str=newstr+count;	
		}
	}
	*str=0;
	return bj;
}
Node* GetNodeIn()//�ֶ���ýڵ�
{
	Node* node=(Node*)malloc(sizeof(Node));
	node->bh=GetBh();
	printf("������ѧ��������");
	node->name=GetString();
	printf("������ѧ���绰��");
	node->phone=GetString();
	node->pnext=NULL; 
	return node;
}

void AddNode(Node** phead,Node** pend,Node* node)//��ӽڵ�
{
	if(*phead==NULL)
	{
		*phead=node;
		*pend=node;
		return;
	}
	else
	{
		(*pend)->pnext=node;
		*pend=node;
		return;
	}
}
void InsertNode(Node** phead,Node** pend,Node* node,int bh)//����ڵ�
{
	Node* bj=*phead;
	if((*phead)->bh==bh)
	{
		node->pnext=*phead;
		*phead=node;
		return;
	}
	while(bj->pnext!=NULL)
	{
		if(bj->pnext->bh==bh)
		{
			node->pnext=bj->pnext;
			bj->pnext=node;
			return;		
		}
		bj=bj->pnext; 
	}
	(*pend)->pnext=node;
	*pend=node;
	return;
}
void DelNode(Node** phead,Node** pend,int bh)//ɾ���ڵ�
{
	Node* bj=*phead;
	Node* pDel=NULL;
	if((*phead)->bh==bh)
	{
		pDel=*phead;
		*phead=(*phead)->pnext;
		free(pDel);
		pDel=NULL;
		return;
	}
	while(bj->pnext!=NULL)
	{
		if(bj->pnext->bh==bh)
		{
			pDel=bj->pnext;
			bj->pnext=bj->pnext->pnext;   
			free(pDel);
			pDel=NULL;
			return;
		}
		if(bj->pnext->pnext=NULL)
		{
			pDel=bj->pnext;
			*pend=bj;  
			free(pDel);
			pDel=NULL;
			return;
		}
		bj=bj->pnext; 
	}
}
void GenerateInfo(Node** phead,Node** pend,int count)//������Ϣ
{
	int i;
	for(i=0;i<count;i++)
	{
		AddNode(phead,pend,GetNode());
	}
}

Page* GetPage(Node* phead)//ͳ�Ʒ�ҳ��Ϣ
{
	Page* page=(Page*)malloc(sizeof(Page));
	page->currentPage=0;
	page->ItemPerPage=10;
	page->totalItem=0;
	while(phead)
	{
		page->totalItem++; 
		phead=phead->pnext; 
	}
	page->totalPage=(page->totalItem%page->ItemPerPage==0?page->totalItem/page->ItemPerPage:page->totalItem /page->ItemPerPage+1); 
	return page;
}
void ShowMenu(Page* page)//��ʾ��ҳ�˵�
{
	switch(g_menu_type)
	{
	case 1:
		printf("��ǰ��%dҳ  ��%dҳ  ��%d��  w��һҳ  s��һҳ  b���� \n",page->currentPage,page->totalPage,page->totalItem);
		break;
	case 3:
		printf("��ǰ��%dҳ  ��%dҳ  ��%d��  w��һҳ  s��һҳ  c��ѯ  b���� \n",page->currentPage,page->totalPage,page->totalItem);
		break;
	case 4:
		printf("��ǰ��%dҳ  ��%dҳ  ��%d��  w��һҳ  s��һҳ   c��ѯ  dɾ�� b���� \n",page->currentPage,page->totalPage,page->totalItem);
		break;
	case 5:
		printf("��ǰ��%dҳ  ��%dҳ  ��%d��  w��һҳ  s��һҳ   c��ѯ  u�޸�  b���� \n",page->currentPage,page->totalPage,page->totalItem);
		break;	
	}	
}
void ShowInfo(Node* phead,Page* page)//��ҳ��ʾ��Ϣ
{
	int begin=(page->currentPage-1)*page->ItemPerPage+1; 
	int end=(page->currentPage-1)*page->ItemPerPage+page->ItemPerPage; 
	int count=0;
	while(phead)
	{
		count++;
		if(count<=end&&count>=begin)
		{
			printf("%d  %s  %s \n",phead->bh,phead->name,phead->phone);
		}
		phead=phead->pnext; 
	}
}
void TurnPage(Node* phead,Page* page)//���·�ҳ
{
	char key='s';
	while(1)
	{
		switch (key)
		{
		case 'w':
			if(page->currentPage ==1)
			{
				printf("��ǰ�Ѿ��ǵ�һҳ�ˣ�\n");
			}
			else
			{
				page->currentPage--;
				ShowInfo(phead,page);//��ҳ��ʾ��Ϣ
				ShowMenu(page);
			}
			break;
		case 's':
			if(page->currentPage ==page->totalPage )
			{
				printf("��ǰ�Ѿ������һҳ�ˣ�\n");
			}
			else
			{
				page->currentPage++;
				ShowInfo(phead,page);//��ҳ��ʾ��Ϣ
				ShowMenu(page);
			}
			break;
		case 'b':
		case 'c':
		case 'd':
		case 'u':
			return;
			break;
		default:
			printf("������������Ϣ��");
			break;		
		}
		g_key=key=GetKey();
	}
}
char GetKey()
{
	char key;
	char c;
	int a=1;
	while((c=getchar())!='\n'||a==1)
	{
		key=c;
		a=0;
	}
	return key;
}

void ShowHomeMenu()//��ʾ���˵�
{
	printf("1.�鿴\n");
	printf("2.���\n");
	printf("3.��ѯ\n");
	printf("4.ɾ��\n");
	printf("5.�޸�\n");
	printf("q.�˳�\n");
}
void LookBook(Node* phead)//�鿴
{
	TurnPage(phead,GetPage(phead));
}
void FindBook(Node* phead)//��ѯ
{
	char* keyword=NULL;
	char key;

	Node* bj=phead;

	Node* newnode=NULL;
	Node* newhead=NULL;
	Node* newend=NULL;
	Node* newbj=NULL;

	while(1)
	{
		//1.�����ѯ��Ϣ����aȷ��
		while(1)
		{
			printf("������Ҫ��ѯ�ùؼ��֣�");
			keyword=GetString();

			printf("��aȷ�ϣ�");
			key=GetKey();
			if(key!='a')
			{
				printf("����������Ҫ��ѯ�Ĺؼ��֣�");
				continue; 
			}
			else
			{
				printf("Ҫ��ѯ�ùؼ����ǣ�");
				break;
			}					
		}
		//2.���鵽����Ϣ�γ��µ�����
		phead=bj;
		while(phead)
		{
			if(strncmp(keyword,phead->name,strlen(keyword))==0||strncmp(keyword,phead->phone,strlen(keyword))==0)
			{
				newnode=(Node*)malloc(sizeof(Node));
				newnode->bh=phead->bh;
				newnode->name=phead->name;
				newnode->phone=phead->phone;
				newnode->pnext=NULL;

				AddNode(&newhead,&newend,newnode);
			}
			phead=phead->pnext; 
		}
		//3.�жϣ���1������������û�ҵ���2�������ҵ��ˣ��鿴һ�£����ͷſռ䣬���²�ѯ
		if(newhead==NULL)
		{
			printf("û�ҵ���Ӧ��Ϣ��");
		}
		else
		{
			LookBook(newhead);

			while(newhead!=NULL)
			{
				newbj=newhead;
				newhead=newhead->pnext; 
				free(newbj);
				newbj=NULL;
			}

			if(g_key=='b'||g_key=='d'||g_key=='u')
			{
				return;
			}
		}
	}
}
void DelBook(Node* phead,Node* pend)//ɾ��
{
	int bh;
	FindBook(phead);

	if(g_key=='b')
	{
		return;
	}
	printf("������Ҫɾ��ѧ���ı�ţ�");
	bh=atoi(GetString());
	DelNode(&phead,&pend,bh);
}
void ChangeBook(Node* phead)//�޸�
{
	int bh;
	FindBook(phead);

	if(g_key=='b')
	{
		return;
	}
	printf("������Ҫ�޸�ѧ���ı�ţ�");
	bh=atoi(GetString());

	while(phead)
	{
		if(phead->bh==bh)
		{
			printf("������ѧ�����֣�");
			phead->name=GetString();
			printf("������ѧ���绰��");
			phead->phone=GetString(); 
		}
		phead=phead->pnext; 
	}
}
