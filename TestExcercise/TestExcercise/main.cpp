/*
Test Task 1
main.cpp
������� ������� ���������
01.09.2016 20:03
*/

#include "functions.h"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	struct students students_list[MAX];
	struct students students_list2[MAX];

	printf("***������ 1-7***\n");
	init_list(&students_list[0]);
	print_list(&students_list[0]);

	printf("\n***������ 7-10***\n");
	sort_list(&students_list[0]);
	print_list(&students_list[0]);
	write_list(&students_list[0]);

	printf("\n***������(����� 2) 1-2***\n");
	read_list(&students_list2[0]);
	print_list(&students_list2[0]);

	printf("\n***������(����� 2) 3-7***\n");
	add_student(&students_list2[0]);
	sort_list(&students_list2[0]);
	print_list(&students_list2[0]);
	write_list(&students_list2[0]);

	getchar();
	return 0;
}