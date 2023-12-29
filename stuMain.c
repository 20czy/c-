//ѧ���ɼ�����ϵͳ
//�������ԣ�C����
//�������ߣ�Visual Studio
//����ʱ�䣺2023.12.24
//�����ߣ�������


#include "studentManageSystem.h"

int main() {
	while (1)
	{
		//��ӡ�˵�
		Menu();
		//��ȡһ���ַ� ����,�ַ����ڴ���ӳ��ΪASCII��
		char ch = _getch();//�ӿ���̨��ȡ�����ַ�������ʾ����Ļ�ϣ�����ȡ���ַ�����������

		switch (ch)
		{
		case '1'://1.¼��ѧ����Ϣ
			InputStudent();
			break;
		case '2'://2.��ӡѧ����Ϣ
			PrintStudent();
			break;
		case '3'://3.����ѧ����Ϣ
			SaveStudent();
			break;
		case '4'://4.��ȡѧ����Ϣ
			ReadStudent();
			break;
		case '5'://5.ͳ������ѧ������
			CountStudent();
			break;
		case '6'://6.����ѧ����Ϣ
			FindStudentById();
			break;
		case '7'://7.�޸�ѧ����Ϣ
			ChangeStudentById();
			break;
		case '8'://8.ɾ��ѧ����Ϣ
			DeleteStudent();
			break;
		case '0'://0.�˳�ϵͳ
			return 0;
			break;
		default:
			printf("��������û�иù���\n\n");
			system("pause");  //��ͣ
			system("cls");    //����
			break;
		}
	}

	return 0;
}

void Menu() {
	printf("*************************************************\n");
	printf("*\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳV1.0\t*\n");
	printf("*\t\t��ѡ����\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.¼��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.��ȡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t5.ͳ������ѧ������\t\t*\n");
	printf("*\t\t6.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t7.�޸�ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t8.ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t0.�˳�ϵͳ\t\t\t*\n");
	printf("*************************************************\n");
}

void InputStudent(){

	Node* pNewNode = (Node*)malloc(sizeof(Node));
    pNewNode->next = NULL;

    printf("������ѧ��������\n");
    scanf_s("%s", pNewNode->stu.stuName, sizeof(pNewNode->stu.stuName));

    printf("�������Ա�\n");
    scanf_s("%s", pNewNode->stu.gender, sizeof(pNewNode->stu.gender));

    printf("������ѧ�����䣺\n");
    scanf_s("%d", &pNewNode->stu.age);

    printf("������ѧ�ţ�\n");
    scanf_s("%d", &pNewNode->stu.stuId);

    printf("������ɼ���\n");
    scanf_s("%d", &pNewNode->stu.stuScore);

    if (head == NULL) {
        head = pNewNode; // �������Ϊ�գ���ͷָ��ָ���½ڵ�
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = pNewNode; // ���½ڵ����ӵ������ĩβ
    }

    printf("ѧ����Ϣ¼��ɹ���\n\n");
    system("pause");
    system("cls");
}

void PrintStudent(){
    system("cls");
	//��������
	Node* ptemp = head;
	if (ptemp == NULL) {
		printf("ϵͳ������ѧ����Ϣ����¼���������ӡ�鿴��\n\n");
	}
	else {
		printf("*********************************************************************************\n");
		printf("*\t\t\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳV1.0\t\t\t*\n");
		printf("*********************************************************************************\n");
		printf("*\tѧ��\t*\t����\t*\t�Ա�\t*\t����\t*\t�ɼ�\t*\n");
		printf("*********************************************************************************\n");

		while (ptemp != NULL)
		{
			printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
				ptemp->stu.stuId,
				ptemp->stu.stuName,
				ptemp->stu.gender,
				ptemp->stu.age,
				ptemp->stu.stuScore
			);

			//��һ���ڵ�
			ptemp = ptemp->next;
			printf("*********************************************************************************\n");
		}
	}

	system("pause");
	system("cls");
}

void SaveStudent(){
    FILE* pFile;
	// ����fopen��ʽ���ı������֮ǰ������
	pFile = fopen("C:/Users/Administrator/Desktop/codecrafters-docker-c/studentManageSystem/stuinfo.dat", "w");
	
	if (pFile == NULL) {
		printf("���ļ�ʧ�ܡ�\n");
		return;
	}

	//д������
	Node* pt = head;
	while (pt != NULL)
	{
		//fwrite(&p->stu, sizeof(Node), 1, pFile);
		fprintf(pFile,"*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
			pt->stu.stuId,
			pt->stu.stuName,
			pt->stu.gender,
			pt->stu.age,
			pt->stu.stuScore);
		pt = pt->next;
	}
	//�ر��ļ�
	fclose(pFile);

	printf("���ݱ���ɹ���\n");
	system("pause");
	system("cls");
}

/*void ReadStudent(){
    system("cls");

	//���ļ�
	FILE* pFile;
	pFile = fopen("C:/Users/Administrator/Desktop/codecrafters-docker-c/studentManageSystem/stuinfo.dat", "r");

	if (pFile == NULL) {
		printf("���ļ�ʧ�ܡ�\n");
		return;
	}
	
	
	Node* p = NULL;
	Node* temp = NULL;


	//������ʶ����ı�����
	char str[200];
	int i = 0;
	p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
	FreeLinkedList(head);
    head = p;

	// int fscanf(FILE *stream, const char *format, ...);
	while (fscanf(pFile, "%s", str) != EOF) {
		if (strcmp(str, "*") && str != NULL){
			switch (i) {
            case 0:
                p->stu.stuId = atoi(str);
                break;
            case 1:
                strcpy(p->stu.stuName, str);
                break;
            case 2:
                strcpy(p->stu.gender, str);
                break;
            case 3:
                p->stu.age = atoi(str);
                break;
            case 4:
                p->stu.stuScore = atoi(str);
                break;
        }
		i++;

        if (i == 5) {
            temp = (Node*)malloc(sizeof(Node));
            temp->next = NULL;
            p->next = temp;
            p = temp;
            i = 0;
        }
		}
        
        
	}
	//��ӡ��ȡ���
	fclose(pFile);
	PrintStudent();
}*/
void ReadStudent() {
    system("cls");

    FILE* pFile;
    pFile = fopen("C:/Users/Administrator/Desktop/codecrafters-docker-c/studentManageSystem/stuinfo.dat", "r");

    if (pFile == NULL) {
        printf("���ļ�ʧ�ܡ�\n");
        return;
    }

    Node* temp = NULL;
    FreeLinkedList(head);
    head = NULL; 

    while (1) {
		// �ȴ����ڵ��ڷ����ַ
        Node* pNewNode = (Node*)malloc(sizeof(Node));
        pNewNode->next = NULL;

        int result = fscanf(pFile, "*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
                            &pNewNode->stu.stuId,
                            pNewNode->stu.stuName,
                            pNewNode->stu.gender,
                            &pNewNode->stu.age,
                            &pNewNode->stu.stuScore);

        if (result != 5) {
            free(pNewNode);
            break; // ������ݲ���������ѭ��
        }

        if (head == NULL) {
            head = pNewNode; // ��������ǿյĽ�head������½ڵ�
        } else {
            temp->next = pNewNode; // �½ڵ㱻������������
        }
        temp = pNewNode; // tempָ�벻���ܵ�pnewNde��Ӱ�죬��ָ���������̶��ĵ�ַ��
		                 //�˸�ֵ���������ǽ�tempʼ��ָ����������һ���ڵ�
    }

    fclose(pFile);
    PrintStudent(); 
}


void CountStudent(){
    int countStu = 0;

	//��������
	Node* p = head;
	while (p != NULL)
	{
		countStu++;
		p = p->next;
	}
	printf("ѧ����������%d\n\n", countStu);

	system("pause");
	system("cls");
}

void FindStudentById(){
    system("cls");
	int stuId;
	printf("���������ѧ��ѧ�ţ�");
	scanf("%d", &stuId);
	// ����������ң����ҵ��������Ϣ��ʾ
	Node* p = head;
	// ��ӡһ�α�ͷ
	bool isShowHead = false;
	// ��¼�Ƿ����ҵ���ѧ�ŵ�ѧ����Ϣ
	bool isFindStu = false;
	while (p != NULL)
	{
		if (stuId == p->stu.stuId) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\tѧ��\t*\t����\t*\t�Ա�\t*\t����\t*\t�ɼ�\t*\n");
				printf("*********************************************************************************\n");
				isShowHead = true;
			}
			printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
				p->stu.stuId,
				p->stu.stuName,
				p->stu.gender,
				p->stu.age,
				p->stu.stuScore
			);
			isFindStu = true;
			printf("*********************************************************************************\n");
		}
		p = p->next;
	}

	if (!isFindStu) {
		printf("ѧ����������ϵͳ�����޸�ѧ����Ϣ��\n\n");
	}

	system("pause");
	system("cls");
}

void ChangeStudentById(){
	int stuNum;
	printf("�������޸�ѧ����ѧ�ţ�");
	scanf("%d", &stuNum);

	Node* p = head;

	bool isShowHead = false;
	bool isFindStu = false;

	while (p != NULL)
	{
		if (stuNum == p->stu.stuId) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\tѧ��\t*\t����\t*\t�Ա�\t*\t����\t*\t�ɼ�\t*\n");
				printf("*********************************************************************************\n");
				isShowHead = true;
			}
			printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
				p->stu.stuId,
				p->stu.stuName,
				p->stu.gender,
				p->stu.age,
				p->stu.stuScore
			);
			//�޸�ѧ����Ϣ
			printf("������ѧ��������\n");
			scanf_s("%s", p->stu.stuName, sizeof(p->stu.stuName));
			printf("�������Ա�\n");
			scanf_s("%s", p->stu.gender, sizeof(p->stu.gender));
			printf("������ѧ�����䣺\n");
			scanf_s("%d", &p->stu.age);
			printf("������ѧ�ţ�\n");
			scanf_s("%d", &p->stu.stuId);
			printf("������ɼ���\n");
			scanf_s("%d", &p->stu.stuScore);
			isFindStu = true;
			printf("*********************************************************************************\n");
			printf("ѧ����Ϣ�޸ĳɹ�����ע�⼰ʱ���档\n\n");
		}
		p = p->next;
	}

	if (!isFindStu) {
		printf("ѧ����������ϵͳ�����޸�ѧ����Ϣ���޷������޸ġ�\n\n");
	}

	system("pause");
	system("cls");
}

void DeleteStudent(){
    system("cls");

	int stuNum;
	printf("������ɾ��ѧ����ѧ�ţ�");
	scanf("%d", &stuNum);

	Node* p = head;
	//��¼ǰһ���ڵ�
	Node* preNode = head;

	bool isShowHead = false;
	bool isFindStu = false;
	while (p != NULL)
	{
		if (stuNum == p->stu.stuId) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\tѧ��\t*\t����\t*\t�Ա�\t*\t����\t*\t�ɼ�\t*\n");
				printf("*********************************************************************************\n");
				isShowHead = true;
			}
			printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
				p->stu.stuId,
				p->stu.stuName,
				p->stu.gender,
				p->stu.age,
				p->stu.stuScore
			);
			isFindStu = true;
			printf("*********************************************************************************\n");

			//ɾ���ڵ�Ϊͷ�ڵ�
			if (p == head) {
				head = NULL;
			}
			//ɾ���ڵ�Ϊβ�ڵ�
			else if (p->next == NULL) {
				p = preNode;
				p->next = NULL;
			}
			//ɾ���ڵ�Ϊ�м�ڵ�
			else {
				preNode->next = p->next;
			}
			printf("ɾ���ɹ�����ǵñ��档\n\n");
		}
		preNode = p;
		p = p->next;
	}

	if (!isFindStu) {
		printf("ѧ����������ϵͳ�����޸�ѧ����Ϣ���޷�����ɾ��������\n\n");
	}

	system("pause");
	system("cls");
}


// helper method
void FreeLinkedList(Node* head) {
    Node* current = head;
    Node* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

