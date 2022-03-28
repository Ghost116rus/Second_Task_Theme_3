#pragma once
#include <iostream>
#include "My_List.h"

enum Options
{
	Init_stack = 1,
	Add_new_element = 2,
	Delete_last_element = 3,
	Show_stack = 4,
	Show_main_menu = 5,
	Write_author = 6,
	Exit = 7,


	O_Or_1 = 15,
	Menu_Commands = 16
};

/* ������� �� ���� ��� �� 2 - ��� ��������, ����� �� ��������� ��������� ���������� ������ �� ���� ��������  */
int getValue(int condition, const char* string);

/*  ����� �������� ����  */
void show_main_menu();

/*  ����� ���������� �� ������  */
void write_author();

/*  �������� ����������� ���������� ����������  */
void menu(MYLIST::my_List& my_List);