#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)//�����������4996�Ĵ���
typedef struct phone
{
	char ID[10]; //���
	char name[20]; //����
	char tel[15]; //�绰
	char sex[2];//�Ա� 
	char email[20]; //email���� 
}Ipa;//�����ͨѶ¼���ԵĽṹ��ȡ������

//��ջ���� 
typedef struct List
{
	Ipa data;//������ 
	struct List *next;//ָ���� 

}List;

List *L = NULL;//��ʼ��Ϊ�� 

//1.��ʼ��ͨѶ¼,����ͷ�ڵ�
void InitList()
{
	L = (List *)malloc(sizeof(List));//����ͷ�ڵ㲢�ҷ��䶯̬�ڴ� 
	L->next = NULL;//ͷ�����һ����ʼ��Ϊ�� 
	printf("��ʼ���ɹ�!\n");
}

//2.�������ݣ�����ͨѶ¼��ͷ�巨�����ο����ݽṹ����23ҳ 
void CreateList_Head()
{
	List *node; //����ڵ�
	int count = 0;//��ʼ��Ϊ0�����ڼ�¼�������� 
	int flag = 1;//�����ж��Ƿ����������һ����¼
	while (flag)//Ϊ1��ִ���������  
	{
		count++;
		node= (List *)malloc(sizeof(List));//����ͷ�ڵ� 
		printf("�����%d����¼��\n", count);
		printf("ID��");
		scanf("%s", &(node->data.ID));//������ 
		//�ж�ID�Ƿ��ظ�
		List *p = L->next;
		while (p)
		{
			//strcmpΪ�ȽϺ��� ������ʽΪstrcmp(str1,str2)����str1=str2���򷵻��� 
			if (strcmp(p->data.ID, node->data.ID) == 0)//�Ƚϵ�ǰ����Ƿ������еı�ŶԱ� 
			{
				printf("ID�ظ�������������!\n");
				printf("ID��");//���������� 
				scanf("%s", &(node->data.ID));
			}
			else
				p = p->next;//û�ظ����������һ��λ��ִ�� 

		}
		//���δ��ͻ��ʼ��Ϣ¼�� 
		printf("������");
		scanf("%s", &(node->data.name));
		printf("�Ա�");
		scanf("%s", &(node->data.sex));
		printf("�绰��");
		scanf("%s", &(node->data.tel));
		printf("���䣺");
		scanf("%s", &(node->data.email));
		node->next = L->next;
		L->next = node;
		printf("�Ƿ����¼��(1.���� 0.���¼��)��");
		scanf("%d", &flag);
		if (flag == 0)
			break;
	}
}

//3.�������ݣ�����ͨѶ¼(β�巨)�� 
void CreateList_Tail()
{
	List *node, *tail; //����ڵ��β�ڵ�
	tail = L;
	int count = 0;
	int flag = 1;
	while (flag)
	{
		count++;
		node = (List *)malloc(sizeof(List)); //���ڵ����ռ�
		printf("¼���%d�����ݣ�", count);
		printf("ID��");
		scanf("%s", &(node->data.ID));
		//�ж�ID�Ƿ��ظ�
		List *p = L->next;
		while (p)
		{
			if (strcmp(p->data.ID, node->data.ID) == 0)
			{
				printf("ID�ظ�������������!\n");
				printf("ID��");
				scanf("%s", &(node->data.ID));
			}
			else
				p = p->next;
		}
		printf("������");
		scanf("%s", &(node->data.name));
		printf("�Ա�");
		scanf("%s", &(node->data.sex));
		printf("�绰��");
		scanf("%s", &(node->data.tel));
		printf("���䣺");
		scanf("%s", node->data.email);
		tail->next = node;
		node->next = NULL;
		tail =  node;
		printf("�Ƿ����¼��(1.���� 0������)��");
		scanf("%d", &flag);
		if (flag == 0)
			break;
	}
}

//4.ɾ������(��������ɾ��)����ɾ���ڵ� 
void DelList()
{
	List *p = L->next;//ָ����һ�� 
	List *q = L;
	char ID[10];//��ŷ�Χ���ܳ���ʮλ�� 
	printf("������Ҫɾ����ID��");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)//�Ƚϱ���Ƿ��ͻ 
	{
		p = p->next;
		q = q->next;
	}
	if (p)
	{
		q->next = p->next;
		printf("ɾ���ɹ�!\n");
		printf("��ɾ�����ݵ���ϢΪ��\n");
		printf("ID��%s\n", p->data.ID);
		printf("������%s\n", p->data.name);
		printf("�Ա�%s\n", p->data.sex);
		printf("�绰��%s\n", p->data.tel);
		printf("���䣺%s\n", p->data.email);
		free(p);//�ͷ�ɾ����p 
	}
	else
	{
		printf("ͨѶ¼�в����ڴ�����Ϣ��\n");
	}
}

//5.�������ݣ�ǰ�巨��
void InsertList_Pre()
{
	List *p, *q, *r, *node;
	p = L->next;
	q = L;
	char ID[10];
	printf("������Ҫ�����λ��(�����λ�õ�ID)��");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)//�Ƚϱ���Ƿ��ͻ 
	{
		p = p->next;
		q = q->next;
	}
	if (p != NULL)
	{

		//���½ڵ����ռ�
		node = (List*)malloc(sizeof(List));
		//¼���½ڵ�����
		printf("�������½ڵ���Ϣ��\n");
	   judge:	
			printf("ID��");
			scanf("%s", &(node->data.ID));
			//�ж�ID�Ƿ��ظ�
		    r = L->next;
		    while (r && strcmp(r->data.ID, node->data.ID) != 0)
			{
				r = r->next;
		    }
	  if (r != NULL)
	  {
		  printf("ID�ظ������������룡\n");
		  //free(r); ���ﲻ��free(r),����ͷ�r,��ʧȥr����һ���ڵ����Ϣ������ᱻ�ƻ�
		  goto judge;
	  }
	  printf("������");
	  scanf("%s", &(node->data.name));
	   printf("�Ա�");
	  scanf("%s", &(node->data.sex));
	  printf("�绰��");
	  scanf("%s", &(node->data.tel));
	  printf("���䣺");
	  scanf("%s", &(node->data.email));
	}
	else
	{
		//���û�и�ID
		int choice1;
		printf("ͨѶ¼��δ�ҵ���ID,�Ƿ�ʹ��Ĭ�Ϸ�ʽ���½ڵ���뵽���(1.�� 0.��)��");
		scanf("%d", &choice1);
		if (choice1 == 1)
		{
			//���½ڵ����ռ�
			node = (List *)malloc(sizeof(List));
			//���½ڵ���������
			printf("�������½ڵ���Ϣ��\n");
		judge1:
			printf("ID��");
			scanf("%s", &(node->data.ID));
			//�ж�ID�Ƿ��ظ�
			r = L->next;
			while (r && strcmp(r->data.ID, node->data.ID) != 0)
			{
				r = r->next;
			}
			if (r != NULL) //ID�ظ�
			{
				printf("ID�ظ�,����������!\n");
				goto judge1;
			}
			printf("������");
			scanf("%s", &(node->data.name));
			printf("�Ա�");
			scanf("%s", &(node->data.sex));
			printf("�绰��");
			scanf("%s", &(node->data.tel));
			printf("���䣺");
			scanf("%s", &(node->data.email));
		}
		else
			return;
	}
	node->next = q->next;
	q->next = node;
	printf("����ɹ���\n");
}

//6.�������ݣ���巨��
void InsertList_Back()
{
	List *p, *r, *q, *node;
	p = L->next;
	q = L;
	char ID[10];
	printf("������Ҫ�����λ��(�����λ�õ�ID)��");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)
	{
		p = p->next;
		q = q->next;
	}
	if (p != NULL)
	{
		//Ϊ�½ڵ����ռ�
		node = (List*)malloc(sizeof(List));
		//Ϊ�½ڵ���������
		printf("�������½ڵ���Ϣ��\n");
	judge:
		printf("ID��");
		scanf("%s", &(node->data.ID));
		//�ж�ID�Ƿ��ظ�
		r = L->next;
		while (r && strcmp(r->data.ID, node->data.ID) != 0)
		{
			r = r->next;
		}
		if (r != NULL)
		{
			printf("ID�ظ������������룡\n");
			goto judge;
		}
		printf("������");
		scanf("%s", &(node->data.name));
		printf("�Ա�");
		scanf("%s", &(node->data.sex));
		printf("�绰��");
		scanf("%s", &(node->data.tel));
		printf("���䣺");
		scanf("%s", &(node->data.sex));
		node->next = p->next;
		p->next = node;
		printf("����ɹ���\n");
	}
	else
	{
		//ͨѶ¼��δ�ҵ���ID
		int choice2;
		printf("ͨѶ¼��δ�ҵ���ID,�Ƿ�ʹ��Ĭ�Ϸ�ʽ���ýڵ���뵽���(1.�� 0.��)��");
		scanf("%d", &choice2);
		if (choice2 == 1)
		{
			//Ϊ�½ڵ����ռ�
			node = (List *)malloc(sizeof(List));
			//Ϊ�½ڵ�¼����Ϣ
			printf("�������½ڵ���Ϣ��\n");
		judge1:
			printf("ID��");
			scanf("%s", &(node->data.ID));
			//�ж�ID�Ƿ��ظ�
			r = L->next;
			while (r && strcmp(r->data.ID, node->data.ID) != 0)
			{
				r = r->next;
			}
			if (r != NULL) //ID�ظ�
			{
				printf("ID�ظ������������룡\n");
				goto judge1;
			}
			printf("������");
			scanf("%s", &(node->data.name));
			printf("�Ա�");
			scanf("%s", &(node->data.sex));
			printf("�绰��");
			scanf("%s", &(node->data.tel));
			printf("���䣺");
			scanf("%s", &(node->data.email));
			node->next = q->next;
			q->next = node;
		}
		if (choice2 == 0)
			return;
	}
	
}

//7.�޸�ͨѶ¼����
void UpdateList()
{
	List *p;//����ָ�� 
	p = L->next;
	char ID[10];
	printf("������Ҫ�޸ĵ�ID:");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)//���p���ұ�Ų���ͻ 
	{
		p = p->next;//ָ����һ�� 
	}
	if (p != NULL)//pΪ�������� 
	{
		int choice;
		printf("��������Ҫ�޸ĵ�����(1.���� 2.�Ա� 3.�绰 4.����)��");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("�������µ�������");
			scanf("%s", &(p->data.name));
		}
		if (choice == 2)
		{
			printf("�������µ���ϵ���Ա�");
			scanf("%s", &(p->data.sex));
		}
		if (choice == 3)
		{
			printf("�������µĵ绰��");
			scanf("%s", &(p->data.tel));
		}
		if (choice == 4)
		{
			printf("�������µ����䣺");
			scanf("%s", &(p->data.email));
		}
		printf("���³ɹ���\n");
	}
	else
	{
		printf("ͨѶ¼�в����ڸ�ID!\n");
		return;
	}
}

//8.����ͨѶ¼�е����ݣ�ͨ��ID���ң�
void SearchList()
{
	List *p;
	char ID[10];
	p = L->next;
	printf("������Ҫ���ҵ�ID��");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("ͨѶ¼�в����ڴ��ˣ�\n");
		return;
	}
	else
	{
		printf("ID��%s\t", p->data.ID);
		printf("������%s\t", p->data.name);
		printf("�Ա�%s\t", p->data.sex);
		printf("�绰��%s\t", p->data.tel);
		printf("���䣺%s\n", p->data.email);
	}
	
}

//9.����ͨѶ¼
void TraverseList()
{
	List *p;
	if (L == NULL)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	else
	{
		p = L->next;
		printf("ͨѶ¼��ȫ����Ϣ���£�\n");
		while (p)//ѭ������ 
		{
			printf("ID��%s\t", p->data.ID);
			printf("������%s\t", p->data.name);
			printf("�Ա�%s\t", p->data.sex);
			printf("�绰��%s\t", p->data.tel);
			printf("���䣺%s\n", p->data.email);
			p = p->next;
		}
	}
}

//10.�ͷ�����
void DestroyList()
{
	List *p, *q;
	p = L->next;
	while (p)
	{
		q = p;//��q��ʱ��Ÿýڵ�
		p = p->next; //pָ����һ���ڵ�
		free(q);// �ͷŵ�ǰ�ڵ�
		q = NULL;
	}
	free(p);
	free(L);
	L = NULL;
	printf("�ͷųɹ���\n");
}

void Menu()
{
	printf("\t\t\t****************************************************\n");
	printf("\t\t\t1.��ʼ��ͨѶ¼                          2.����ͨѶ¼\n");
	printf("\t\t\t3.ɾ����ϵ��                            4.�޸���ϵ��\n");
	printf("\t\t\t5.������ϵ��                            6.������ϵ��\n");
	printf("\t\t\t7.����ͨѶ¼                            8.�ͷ�ͨѶ¼\n");
	printf("\t\t\t****************************************************\n");
}
int main()
{
	int choice;
	while (1)
	{
		Menu();
		printf("��ѡ��˵���");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			//��ʼ��ͨѶ¼
			InitList();
			break;
		}
		case 2:
		{
			//����ͨѶ¼
			int num;
			printf("��ѡ������ʽ(1.ͷ�巨 2.β�巨):");
			scanf("%d", &num);
			if (num == 1)
			{
				//ͷ�巨
				CreateList_Head();
				break;
			}
			if (num == 2)
			{
				//β�巨
				CreateList_Tail();
				break;
			}
		}
		case 3:
		{
			//ɾ����Ϣ
			DelList();
			break;
		}
		case 4:
		{
			//�޸���Ϣ
			UpdateList();
			break;
		}
		case 5:
		{
			//������Ϣ
			SearchList();
			break;
		}
		case 6:
		{
			//������Ϣ
			int num;
			printf("��ѡ����뷽ʽ(1.ǰ�巨 2.β�巨 3.��巨)��");
			scanf("%d", &num);
			if (num == 1)
			{
				//ǰ�巨
				InsertList_Pre();
				break;
			}
			if (num == 2)
			{
				//��巨
				InsertList_Back();
				break;
			}
		}
		case 7:
		{
			//����ͨѶ¼
			TraverseList();
			break;
		}
		case 8:
		{
			//�ͷ�ͨѶ¼
			DestroyList();
			break;
		}
		default:
			break;
		}
	}
}

