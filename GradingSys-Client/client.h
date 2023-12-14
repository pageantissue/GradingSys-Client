#pragma once
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cerrno>

#define SERVER_PORT 6591
#define BUF_SIZE 1024
using namespace std;

void help1() { //学生的命令提示
	cout.setf(ios::left); //设置对齐方式为left 
	cout.width(30); //设置宽度，不足用空格填充 
	cout << "checkHw [courseName] [taskName]" << "View the content of the corresponding assignment " << endl;  //查看作业内容
	cout.width(30);
	cout << "submit [courseName] [taskName]" << "Submit an assignment" << endl;  //提交作业
	cout.width(30);
	cout << "checkScore [courseName] [taskName]" << "View the score of the corresponding assignment " << endl;  //查看作业分数
}

void help2() { //教师的命令提示
	cout.setf(ios::left); //设置对齐方式为left 
	cout.width(30); //设置宽度，不足用空格填充 
	cout << "publish [courseName] [taskName]" << "Publish a task" << endl;  //布置作业
	cout.width(30);
	cout << "judge [courseName] [taskName]" << "Judging homework" << endl;  //给作业打分
}

void help() { // root的命令提示
	cout.setf(ios::left);
	cout.width(30);
	cout << "ls [-l]" << "Display the current directory listing" << endl;
	cout.width(30);
	cout << "cd [path]" << "Enter the specific directory " << endl;
	cout.width(30);
	cout << "gotoRoot " << "Return to the root directory " << endl;
	cout.width(30);
	cout << "mkdir [path]" << "Create directory" << endl;
	cout.width(30);
	cout << "rm [-rf dir_path] | [-f file_path]" << "Delete directory or file" << endl;
	cout.width(30);
	cout << "touch" << "Create a blank file" << endl;
	cout.width(30);
	cout << "echo \"content\" > [path] | \"content\" >> [path]" << "Write or add a file" << endl;
	cout.width(30);
	cout << "cat [file_path]" << "View the file content" << endl;
	cout.width(30);
	cout << "chmod [ugoa]*[-+=]*[rwx] | [0-7]+" << "Modify the access right" << endl;
	cout.width(30);
	cout << "chown [user:group] [path]" << "Modify user and group in file" << endl;
	cout.width(30);

	cout << "useradd [-g group] [-m] [user]" << "Add user" << endl;
	cout.width(30);
	cout << "userdel [user]" << "Delete user" << endl;
	cout.width(30);
	cout << "groupadd [group]" << "Add group" << endl;
	cout.width(30);
	cout << "groupdel [group]" << "Delete group" << endl;
	cout.width(30);
	cout << "passwd [user]" << "Modify the password" << endl;
	help1(); help2();
	cout.width(30);
	cout << "logout" << "Logout the account" << endl;
	cout.width(30);
	cout << "exit" << "Exit the system" << endl;
	cout.width(30);
}