/*
Test Task 1
������� ��� �������� ������ 1
������� ������� ���������
01.09.2016 20:03
*/
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "functions.h"

int num = 0;	//���-�� ��������� � ���������

/* ������������� ��������� */
void init_list(struct students* list) {
	setlocale(LC_ALL, "Russian");
	register int i = 0;
	char buff[MAX_LNAME_LENGTH];

	while(i < MAX) {
		printf("������� ������� %d �������a:\n", i+1);
		gets(buff);
		OemToCharBuff(buff, list[i].fio, MAX_LNAME_LENGTH);
		if(list[i].fio[0] == 0) break;
		printf("������� ��� ���������:\n");
		gets(buff);
		list[i].stipa = atoi(buff);
		printf("\n");
		i++;
	}
}

/* ����� ��������� ��������� */
void print_list(struct students* list) {
	setlocale(LC_ALL, "Russian");
	num = 0;

	printf("������� �������� - ���������:\n");
	printf("-----------------------------\n");
	while(list[num].fio[0] != 0) {
		printf("%s - %d\n", list[num].fio, list[num].stipa);
		num++;
	}
	printf("\n");
}

/* ���������� ��������� �� �(A) �� �(Z) */
void sort_list(struct students* list) {
	struct students buff;
	register int i, j;

	for(i = 0; i < num - 1; i++)
		for(j = i + 1; j < num; j++)
			if(strcmp(list[i].fio, list[j].fio) > 0) {
				buff = list[i];
				list[i] = list[j];
				list[j] = buff;
			}
}

/*������ ��������� � ���� */
void write_list(struct students* list) {
	setlocale(LC_ALL, "Russian");
	FILE* file;
	register int i;
	
	if((file = fopen("students_list", "wb")) == NULL) {
		printf("������ ��� �������� �����.\n");
		return;
	}
	
	for(i = 0; i < num; i++)
		if(list[i].fio)
			if(fwrite(&list[i], sizeof(struct students), 1, file) != 1)
				printf("������ ��� ������ �����.\n");
	
	fclose(file);
}

/* ������ ��������� �� ����� */
void read_list(struct students* list) {
	setlocale(LC_ALL, "Russian");
	FILE* file;
	register int i = 0;
	
	for(i = 0; i < MAX; i++) list[i].fio[0] = 0;	//������������� ���������

	if((file = fopen("students_list", "rb")) == NULL) {
		printf("������ ��� �������� �����.\n");
		return;
	}
	
	i = 0;
	while(fread(&list[i], sizeof(struct students), 1, file) && list[i].fio[0] != 0) {
		i++;
	}

	fclose(file);
}

/* ���������� �������� � ��������� */
void add_student(struct students* list) {
	setlocale(LC_ALL, "Russian");
	char buff[MAX_LNAME_LENGTH];

	while(num < MAX) {
		printf("������� ������� %d �������a:\n", num+1);
		gets(buff);
		OemToCharBuff(buff, list[num].fio, MAX_LNAME_LENGTH);
		if(list[num].fio[0] == 0) break;
		printf("������� ��� ���������:\n");
		gets(buff);
		list[num].stipa = atoi(buff);
		printf("\n");
		num++;
	}
}