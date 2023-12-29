//学生成绩管理系统
//开发语言：C语言
//开发工具：Visual Studio
//开发时间：2023.12.24
//开发者：陈泽阳


#include "studentManageSystem.h"

int main() {
	while (1)
	{
		//打印菜单
		Menu();
		//读取一个字符 整数,字符在内存中映射为ASCII码
		char ch = _getch();//从控制台读取单个字符，不显示在屏幕上，将读取的字符返还给程序

		switch (ch)
		{
		case '1'://1.录入学生信息
			InputStudent();
			break;
		case '2'://2.打印学生信息
			PrintStudent();
			break;
		case '3'://3.保存学生信息
			SaveStudent();
			break;
		case '4'://4.读取学生信息
			ReadStudent();
			break;
		case '5'://5.统计所有学生人数
			CountStudent();
			break;
		case '6'://6.查找学生信息
			FindStudentById();
			break;
		case '7'://7.修改学生信息
			ChangeStudentById();
			break;
		case '8'://8.删除学生信息
			DeleteStudent();
			break;
		case '0'://0.退出系统
			return 0;
			break;
		default:
			printf("输入有误，没有该功能\n\n");
			system("pause");  //暂停
			system("cls");    //清屏
			break;
		}
	}

	return 0;
}

void Menu() {
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统V1.0\t*\n");
	printf("*\t\t请选择功能\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.保存学生信息\t\t\t*\n");
	printf("*\t\t4.读取学生信息\t\t\t*\n");
	printf("*\t\t5.统计所有学生人数\t\t*\n");
	printf("*\t\t6.查找学生信息\t\t\t*\n");
	printf("*\t\t7.修改学生信息\t\t\t*\n");
	printf("*\t\t8.删除学生信息\t\t\t*\n");
	printf("*\t\t0.退出系统\t\t\t*\n");
	printf("*************************************************\n");
}

void InputStudent(){

	Node* pNewNode = (Node*)malloc(sizeof(Node));
    pNewNode->next = NULL;

    printf("请输入学生姓名：\n");
    scanf_s("%s", pNewNode->stu.stuName, sizeof(pNewNode->stu.stuName));

    printf("请输入性别：\n");
    scanf_s("%s", pNewNode->stu.gender, sizeof(pNewNode->stu.gender));

    printf("请输入学生年龄：\n");
    scanf_s("%d", &pNewNode->stu.age);

    printf("请输入学号：\n");
    scanf_s("%d", &pNewNode->stu.stuId);

    printf("请输入成绩：\n");
    scanf_s("%d", &pNewNode->stu.stuScore);

    if (head == NULL) {
        head = pNewNode; // 如果链表为空，则将头指针指向新节点
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = pNewNode; // 将新节点连接到链表的末尾
    }

    printf("学生信息录入成功。\n\n");
    system("pause");
    system("cls");
}

void PrintStudent(){
    system("cls");
	//遍历链表
	Node* ptemp = head;
	if (ptemp == NULL) {
		printf("系统中暂无学生信息，请录入后再来打印查看。\n\n");
	}
	else {
		printf("*********************************************************************************\n");
		printf("*\t\t\t欢迎使用高校学生成绩管理系统V1.0\t\t\t*\n");
		printf("*********************************************************************************\n");
		printf("*\t学号\t*\t姓名\t*\t性别\t*\t年龄\t*\t成绩\t*\n");
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

			//下一个节点
			ptemp = ptemp->next;
			printf("*********************************************************************************\n");
		}
	}

	system("pause");
	system("cls");
}

void SaveStudent(){
    FILE* pFile;
	// 利用fopen方式打开文本会清空之前的数据
	pFile = fopen("C:/Users/Administrator/Desktop/codecrafters-docker-c/studentManageSystem/stuinfo.dat", "w");
	
	if (pFile == NULL) {
		printf("打开文件失败。\n");
		return;
	}

	//写入数据
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
	//关闭文件
	fclose(pFile);

	printf("数据保存成功。\n");
	system("pause");
	system("cls");
}

/*void ReadStudent(){
    system("cls");

	//打开文件
	FILE* pFile;
	pFile = fopen("C:/Users/Administrator/Desktop/codecrafters-docker-c/studentManageSystem/stuinfo.dat", "r");

	if (pFile == NULL) {
		printf("打开文件失败。\n");
		return;
	}
	
	
	Node* p = NULL;
	Node* temp = NULL;


	//逐个单词读入文本内容
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
	//打印读取结果
	fclose(pFile);
	PrintStudent();
}*/
void ReadStudent() {
    system("cls");

    FILE* pFile;
    pFile = fopen("C:/Users/Administrator/Desktop/codecrafters-docker-c/studentManageSystem/stuinfo.dat", "r");

    if (pFile == NULL) {
        printf("打开文件失败。\n");
        return;
    }

    Node* temp = NULL;
    FreeLinkedList(head);
    head = NULL; 

    while (1) {
		// 先创建节点在分配地址
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
            break; // 如果数据不满足跳出循环
        }

        if (head == NULL) {
            head = pNewNode; // 如果链表是空的将head分配给新节点
        } else {
            temp->next = pNewNode; // 新节点被放在链表的最后
        }
        temp = pNewNode; // temp指针不会受到pnewNde的影响，它指向的是这个固定的地址，
		                 //此赋值语句的作用是将temp始终指向链表的最后一个节点
    }

    fclose(pFile);
    PrintStudent(); 
}


void CountStudent(){
    int countStu = 0;

	//遍历链表
	Node* p = head;
	while (p != NULL)
	{
		countStu++;
		p = p->next;
	}
	printf("学生总人数：%d\n\n", countStu);

	system("pause");
	system("cls");
}

void FindStudentById(){
    system("cls");
	int stuId;
	printf("请输入查找学生学号：");
	scanf("%d", &stuId);
	// 遍历链表查找，查找到后进行信息显示
	Node* p = head;
	// 打印一次表头
	bool isShowHead = false;
	// 记录是否有找到该学号的学生信息
	bool isFindStu = false;
	while (p != NULL)
	{
		if (stuId == p->stu.stuId) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\t学号\t*\t姓名\t*\t性别\t*\t年龄\t*\t成绩\t*\n");
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
		printf("学号输入有误，系统中暂无该学生信息。\n\n");
	}

	system("pause");
	system("cls");
}

void ChangeStudentById(){
	int stuNum;
	printf("请输入修改学生的学号：");
	scanf("%d", &stuNum);

	Node* p = head;

	bool isShowHead = false;
	bool isFindStu = false;

	while (p != NULL)
	{
		if (stuNum == p->stu.stuId) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\t学号\t*\t姓名\t*\t性别\t*\t年龄\t*\t成绩\t*\n");
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
			//修改学生信息
			printf("请输入学生姓名：\n");
			scanf_s("%s", p->stu.stuName, sizeof(p->stu.stuName));
			printf("请输入性别：\n");
			scanf_s("%s", p->stu.gender, sizeof(p->stu.gender));
			printf("请输入学生年龄：\n");
			scanf_s("%d", &p->stu.age);
			printf("请输入学号：\n");
			scanf_s("%d", &p->stu.stuId);
			printf("请输入成绩：\n");
			scanf_s("%d", &p->stu.stuScore);
			isFindStu = true;
			printf("*********************************************************************************\n");
			printf("学生信息修改成功，请注意及时保存。\n\n");
		}
		p = p->next;
	}

	if (!isFindStu) {
		printf("学号输入有误，系统中暂无该学生信息，无法进行修改。\n\n");
	}

	system("pause");
	system("cls");
}

void DeleteStudent(){
    system("cls");

	int stuNum;
	printf("请输入删除学生的学号：");
	scanf("%d", &stuNum);

	Node* p = head;
	//记录前一个节点
	Node* preNode = head;

	bool isShowHead = false;
	bool isFindStu = false;
	while (p != NULL)
	{
		if (stuNum == p->stu.stuId) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\t学号\t*\t姓名\t*\t性别\t*\t年龄\t*\t成绩\t*\n");
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

			//删除节点为头节点
			if (p == head) {
				head = NULL;
			}
			//删除节点为尾节点
			else if (p->next == NULL) {
				p = preNode;
				p->next = NULL;
			}
			//删除节点为中间节点
			else {
				preNode->next = p->next;
			}
			printf("删除成功，请记得保存。\n\n");
		}
		preNode = p;
		p = p->next;
	}

	if (!isFindStu) {
		printf("学号输入有误，系统中暂无该学生信息，无法进行删除操作。\n\n");
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

