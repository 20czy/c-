#pragma once 

#include<stdio.h>
#include<conio.h>		//_getch()
#include<stdlib.h>		//system()
#include<string.h>		//strlen()
#include<stdbool.h>     //bool


typedef struct tagStudent {
	char stuName[20];	//姓名
	char gender[4];		//性别
	int  age;			//年龄
	int  stuId;		    //学号
	int  stuScore;		//成绩
}Student;

typedef struct stuNode {
    Student stu;
    struct stuNode* next;
}Node;

Node* head = NULL;

//菜单
void Menu();
//1.录入学生信息
void InputStudent();
//2.打印学生信息
void PrintStudent();
//3.保存学生信息
void SaveStudent();
//4.读取学生信息
void ReadStudent();
//5.统计所有学生人数
void CountStudent();
//6.查找学生信息
void FindStudent();
//7.修改学生生信息
void ChangeStudent();
//8.删除学生信息
void DeleteStudent();