#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <locale.h>

const int MAX = 25;	// Количество студентов
const int MAX_LNAME_LENGTH = 20;	// Максимальная длина фамилии студента

struct students {
	char fio[20];
	int stipa;
};

void init_list(struct students*);
void print_list(struct students*);
void sort_list(struct students*);
void write_list(struct students*);
void read_list(struct students*);
void add_student(struct students*);

#endif	// FUNCTIONS_H