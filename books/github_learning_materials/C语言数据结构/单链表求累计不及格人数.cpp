#include<iostream>
#include<malloc.h>
#include <iomanip>
using namespace std;
typedef int ElemType;
#define M 20
typedef struct LNode
{
	ElemType data;	//����������
	struct LNode* next;	//ָ����
}LNode, * LinkList;
void CreateLink(LinkList& h, ElemType a[], int n)
{
	LinkList s, tc; int i;
	h = (LinkList)malloc(sizeof(LinkList));
	tc = h;
	for (i = 0; i < n; i++)
	{
		s = (LinkList)malloc(sizeof(LinkList));	//ͷ�ڵ㴴��
		s->data = a[i];
		tc->next = s;
		tc = s;
	}
	tc->next = NULL;
}
int Count(LinkList sl)
{
	int k = 0;
	LNode* p;
	if (sl->next == NULL)return 0;
	p = sl->next;

	//�������ж�
	while (p != NULL)
	{
		if (p->data < 60) { k++; }
		p = p->next;
	}
	return k;
}
//void main()
//{
//	int N;
//	//cout << "������ѧ��������" << endl;
//	cout << "ѧ������Ϊ��";
//	cin >> N;
//	LinkList head;
//	ElemType a[M];
//	int i, k;
//	cout << "��������������ѧ���ĳɼ���" << endl;
//	for (i = 0; i < N; i++)
//		scanf_s("%d", &a[i]);
//	cout << "����ѧ���ĳɼ�����Ϊ��" << endl;
//	for (i = 0; i < N; i++)
//	{
//		cout << a[i] << setw(6);
//	}
//	cout << endl;
//	CreateLink(head, a, N);//����������
//	k = Count(head);//���������ֵ�ĺ���
//	cout << "����ѧ���ĳɼ��в����������Ϊ��" << k << "��";
//	cout << endl;
//}
