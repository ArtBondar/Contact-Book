#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define ambiguous
#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include <stdarg.h>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
using namespace std;
struct date {
	int day;
	int month;
	int year;
};
struct contact {
	char *name;
	date bd;
	char **tel;
	int telcount;
};
/////// �������� ��������
int cin_int();
void sort(contact **&book, int &size);
void rename(contact **book, int size, int Ncont);
void cindate(contact **book, int size, int Ncont);
void createcontact(contact **&book, int &size);
void addtel(contact **book, int size, int Ncont);
/////// ����� �� �����
void coutcont(contact **book, int size);
/////// ��������
void delALL(contact **&book, int &size);
void delcontact(contact **&book, int &size);
////// �����
void findName(contact **&book, int &size);
void findNumber(contact **&book, int &size);
////// ����
void write_file(contact **&book, int &size);
void read_file(contact **&book, int &size);