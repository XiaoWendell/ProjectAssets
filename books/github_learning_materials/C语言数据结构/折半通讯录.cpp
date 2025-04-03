#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;

/*  person��
	�����˵����������У��绰
*/
class Person 
{
private:	
	string name;
	string city;
	string phone;
public: 
	Person(){}
	Person(string name, string city, string phone) 
	{
		this->name = name;
		this->city = city;
		this->phone = phone;
	}
	string getCity() 
	{
		return this->city;
	}
	void setCity(string city) 
	{
		this->city = city;
	}
	string getPhone() 
	{
		return this->phone;
	}
	void setPhone(string phone)
	{
		this->phone = phone;
	}
	string getName() 
	{
		return this->name;
	}
	void setName(string name) 
	{
		this->name = name;
	}	
	void update(string name, string city, string phone)
	{
		this->name = name;
		this->city = city;
		this->phone = phone;
	}
};


typedef Person ElemType;
typedef int Status;
const int SUCCESS = 1;
const int ERROR = -2;

//����ڵ�����
typedef struct DulNode
{
	ElemType data[100];
	int length;
}DulNode;

//����
void nodeSort(DulNode &list,int local,string oldName,string newName)
{	
	int low = 0;
	int high = 0;
	int mid = 0;
	int temp = 0;
	if(newName.compare(oldName) <= 0)
	{
		low = 0;
		high = local - 1;
		temp = 1;	//�������
	}else
	{
		low = local + 1;
		high = list.length-1;
		temp = 0;	//���Ҳ���
	}		
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(newName.compare(list.data[mid].getName()) < 0)
		{
			high = mid - 1;
		}else
		{
			low = mid + 1;
		}
	}
	Person tempPerson = list.data[local];
	if(temp == 1)	//�����ƶ�
	{
		for(int j = local - 1 ;j >= high + 1;--j)
		{
			list.data[j + 1] = list.data[j];
		}
		list.data[(high + 1)] = tempPerson;	
	}else			
	{
		for(int j = local + 1 ;j <= high; j++)
		{
			list.data[j - 1] = list.data[j];
		}
		list.data[(high)] = tempPerson;	
	}
}

//����ڵ�,�۰����
Status nodeInsert(DulNode &list, Person person) 
{		
	int len = list.length-1;
	if(len >= 0)
	{
		int low = 0; int high = len;
		int mid = 0;
		while(low <= high)
		{
			mid = (low + high) / 2;				
			if(person.getName().compare(list.data[mid].getName()) < 0)
			{
				high = mid - 1;
			}else
			{
				low = mid + 1;
			}
		}
		for(int j = len;j >= high + 1;--j)
		{
			list.data[j + 1] = list.data[j];
		}
		list.data[(high + 1)] = person;		
	}
	else
	{		
		list.data[0] = person;		
	}
	list.length++;
	return SUCCESS;
}

//ɾ���ڵ� 
Status nodeDelete(DulNode &list, string name) 
{
	if(list.length > 0)
	{
		int low = 0;
		int high = list.length-1;
		int mid = (low + high) / 2;		
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(name.compare(list.data[mid].getName()) < 0)
			{
				high = mid - 1;
			}else if(name.compare(list.data[mid].getName()) > 0)
			{
				low = mid + 1;
			}		
			else
			{
				for(int i = mid + 1;i <= list.length - 1;i ++)
				{
					list.data[i - 1] = list.data[i];
				}
				list.length --;
				return SUCCESS;
			}
		}
		return ERROR;
	}
	return ERROR;
}

//�ж��û��Ƿ���ڲ���ȡ�ýڵ������(�޸�)
Status isNode(DulNode &list, string name, Person** person)
 {
	if(list.length > 0)
	{
		int low = 0;
		int high = list.length-1;
		int mid = (low + high) / 2;
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(name.compare(list.data[mid].getName()) < 0)
			{
				high = mid - 1;
			}else 
			{
				low = mid + 1;
			}		
		}	
		if(name.compare(list.data[high].getName()) == 0)
		{
			*person = &(list.data[high]);		
			return high;
		}
	}
	return ERROR;	
}

//���������ж��û��Ƿ���ڲ���ȡ�ýڵ�����ݣ������û��� 
Status selectNode(DulNode &list, string name, Person** person) 
{
	if(list.length > 0)
	{
		int low = 0;
		int high = list.length-1;
		int mid = (low + high) / 2;		
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(name.compare(list.data[mid].getName()) < 0)
			{
				high = mid - 1;
			}else if(name.compare(list.data[mid].getName()) > 0)
			{
				low = mid + 1;
			}else
			{
				*person = &(list.data[mid]);		
				return SUCCESS;
			}
		}			
	}
	return ERROR;	
}

//���˵� 
void showMenu()
{
	printf("\n");
	printf("********************** ��ӭʹ��ͨѶ¼����ϵͳ ********************\n");
	printf("*                                                                *\n");
	printf("* ��            ��1�����ͨѶ¼��");
	printf(" �� ��   2����ѯ����          ��*\n");
	printf("* ����������������3���޸�        ");
	printf(" ������  4��ɾ����¼��������    *\n");
	printf("* ����������������5����ʾȫ��    "); 
	printf(" ������  6���˳����� ��         *\n");
	printf("*                                                                *\n");
	printf("******************************************************************\n");
}
//����³�Ա 
int addPerson(DulNode &list) 
{
	char name[20];
	char city[20];
	char phone[20];
	printf("������������������q�ص���ʼ�����������");
	scanf("%s", name);
	fflush(stdin);
	string sName = (string)name;
	if(sName == "q")
	{
		printf("\n");
		return 0;
	}	
	printf("\n��������У�");
	scanf("%s", city);
	printf("\n������绰��");
	scanf("%s", phone);
	Person *person = new Person(sName, city, phone);	
	nodeInsert(list, *person);
	printf("\n��ӳɹ���\n\n");	
	return 1;
}
//��ʾ���г�Ա 
void showAllPerson(DulNode &list)
 {	
	printf("\n=========================== ͨѶ¼�б� ===========================\n\n");
	int len = list.length;
	for(int j = 0;j <= list.length - 1; j ++)
	{
		string name = list.data[j].getName();
		string city = list.data[j].getCity();
		string phone = list.data[j].getPhone();			
		printf("*   ��ţ�%d    ������%s     ���У�%s     �绰��%s\n\n",j + 1, name.c_str(), city.c_str(),phone.c_str());		
	}	
	if(len == 0)
	{
		printf("                     ����Ϊ�գ����������\n\n");
	}
	printf("==================================================================\n\n");
}
//�޸��û���Ϣ
void updatePerson(DulNode &list) 
{	
	char inName[20];
	printf("��������Ҫ�޸��û������� ��������q�ص���ʼ�����������");
	scanf("%s", &inName);
	fflush(stdin);
	string sName = (string)inName; 
	if(sName == "q")
	{
		printf("\n");
		return;
	} 
	Person* person = new Person();
	int high = isNode(list, sName, &person);
	while(high == -2) 
	{
		printf("�û��������ڣ� \n\n");
		printf("��������Ҫ�޸��û������� ��������q�ص���ʼ�����������");		
		char temp[20];    //��ʱ���� 
		scanf("%s", &temp);
		fflush(stdin);
		sName = (string)temp; 
		if(sName == "q")
		{
			printf("\n");
			return;
		} 
		high = isNode(list, sName, &person);
	}	
	string oldName = list.data[high].getName();
	char name[20];
	char city[20];
	char phone[20];
	printf("�������µ��û���Ϣ\n\n");
	printf("������������");
	scanf("%s", &name);
	printf("\n��������У�");
	scanf("%s", &city);
	printf("\n������绰��");
	scanf("%s", &phone);
	person->update(name, city, phone);
	printf("\n�޸ĳɹ�\n\n");
	string newName = (string)name;
	nodeSort(list,high,oldName,newName);
 	showAllPerson(list); 
}
//��ѯ��Ա��Ϣ 
void selectPerson(DulNode &list)
 {	
	char inName[20];
	printf("��������Ҫ��ѯ�û������� ��������q�ص���ʼ�����������");
	scanf("%s", &inName);
    fflush(stdin);
	string sName = (string)inName; 
	if(sName == "q")
	{
		printf("\n");
		return;
	} 
	Person *person = new Person();
	while(selectNode(list, sName, &person) == -2)
	{
		printf("�û��������ڣ�\n\n");
		printf("���ٴ�����Ҫ��ѯ�û���������������q�ص���ʼ���桿��");
		char temp[20];    //��ʱ���� 
		scanf("%s", &temp);
		fflush(stdin);
		sName = (string)temp;
		if(sName == "q")
		{
			printf("\n");
			return;
		} 
	}
	string name = person->getName();
	string city = person->getCity();
	string phone = person->getPhone();
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("*                                                                *\n");
	printf("* ��            ��������%s����          ��\n\n",name.c_str());
	printf("* ��            �����У�%s   ",city.c_str());
	printf("    �绰��%s����          ��\n",phone.c_str());
	printf("*                                                                *\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
} 
//ɾ����Ա��Ϣ 
void deletePerson(DulNode &list) 
{
	char inName[20];
	printf("��������Ҫɾ���û���������������q����ɾ����������");
	scanf("%s", &inName);
	fflush(stdin);
	string sName = (string)inName; 
	if(sName == "q") 
	{
		printf("\n");
		return;
	} 	
	while(nodeDelete(list, sName) == -2)
	{
		printf("�û���������ȷ\n\n");
		printf("���ٴ�������Ҫɾ���û���������������q����ɾ����������");
		char temp[20];    //��ʱ���� 
		scanf("%s", &temp);
		fflush(stdin);
		sName = (string)temp;
		if(sName == "q")
		{
			printf("\n");
			return;
		} 
	}
	printf("ɾ���ɹ���\n\n");
}
//������ 
int main()
 {
	DulNode L;
	L.length = 0;
	int mainChance;
	showMenu();
	printf("������:");
 	scanf("%d", &mainChance);
	fflush(stdin);
	int temp = 0;
	while(mainChance!=6) 
	{
		switch(mainChance) 
		{ 
			case 1:
				temp = addPerson(L);
				if(temp == 1)
				{
					showAllPerson(L); 
				}				
				break;
			case 2:
				selectPerson(L);
				break;
			case 3:
				updatePerson(L);				
				break;
			case 4:
				deletePerson(L);
				break;
			case 5:
				showAllPerson(L);
				break;
			default:
				printf("\n������ 1 ~ 6 ֮������� \n\n");
				break;
		}
		mainChance = 0;
		showMenu();
		printf("������:");
		scanf("%d", &mainChance);
		fflush(stdin);
	}
	return 0;
}


