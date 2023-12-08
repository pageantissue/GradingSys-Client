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

#define SERVER_PORT 6591 //服务端口
#define BUF_SIZE 1024
using namespace std;

void help() {
	cout.setf(ios::left); //设置对齐方式为left 
	cout.width(30); //设置宽度，不足用空格填充 
	//cout << setiosflags(ios::left);
	cout << "ls" << "Display the current directory listing" << endl;	//列出当前目录清单
	cout.width(30);
	cout << "cd" << "Enter the specific directory " << endl;		//前往指定目录
	cout.width(30);
	cout << "mkdir" << "Create directory" << endl;					//创建目录
	cout.width(30);
	cout << "rm" << "Delete the file or directory" << endl;			//删除文件和目录 
	cout.width(30);
	cout << "touch" << "Create new file" << endl;				//创建新文件
	cout.width(30);
	cout << "read" << "Read the content of file" << endl;		//读文件
	cout.width(30);
	cout << "write" << "Write the file" << endl;			//写文件
	cout.width(30);
	cout << "chmod" << "Modify the access right" << endl;		//修改文件权限
	cout.width(30);
	cout << "adduser" << "Add user" << endl;		//新增用户
	cout.width(30);
	cout << "deluser" << "Delete user" << endl;		//删除用户
	cout.width(30);
	cout << "addusergrp" << "Add user group" << endl;		//新增用户组
	cout.width(30);
	cout << "delusergrp" << "Delete user group" << endl;		//删除用户组
	cout.width(30);
	cout << "snapshot" << "Back up the system" << endl;			//备份系统
	cout.width(30);
	cout << "format" << "Recover the system" << endl;
	cout.width(30);
	cout << "exit" << "Exit the system" << endl;
}