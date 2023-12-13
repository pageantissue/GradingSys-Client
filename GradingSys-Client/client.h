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

void help() {
	cout.setf(ios::left);
	cout.width(30);
	//cout << setiosflags(ios::left);
	cout << "ls" << "Display the current directory listing" << endl;	//�г���ǰĿ¼�嵥
	cout.width(30);
	cout << "cd" << "Enter the specific directory " << endl;		//ǰ��ָ��Ŀ¼
	cout.width(30);
	cout << "mkdir" << "Create directory" << endl;					//����Ŀ¼
	cout.width(30);
	cout << "rm" << "Delete the file or directory" << endl;			//ɾ���ļ���Ŀ¼ 
	cout.width(30);
	cout << "touch" << "Create new file" << endl;				//�������ļ�
	cout.width(30);
	cout << "read" << "Read the content of file" << endl;		//���ļ�
	cout.width(30);
	cout << "write" << "Write the file" << endl;			//д�ļ�
	cout.width(30);
	cout << "chmod" << "Modify the access right" << endl;		//�޸��ļ�Ȩ��
	cout.width(30);
	cout << "adduser" << "Add user" << endl;		//�����û�
	cout.width(30);
	cout << "deluser" << "Delete user" << endl;		//ɾ���û�
	cout.width(30);
	cout << "addusergrp" << "Add user group" << endl;		//�����û���
	cout.width(30);
	cout << "delusergrp" << "Delete user group" << endl;		//ɾ���û���
	cout.width(30);
	cout << "snapshot" << "Back up the system" << endl;			//����ϵͳ
	cout.width(30);
	cout << "format" << "Recover the system" << endl;
	cout.width(30);
	cout << "exit" << "Exit the system" << endl;
}