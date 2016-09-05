/*
Тестовая задача 2
main.cpp
unsigned short - 2 байта
Яковлев Евгений Сергеевич
02.09.2016 09:03
*/
#include <stdio.h>
#include <stdlib.h>

const int BUFFER_SIZE = 32768;	// Размер буфера
const unsigned short STRIPED_WORD = 0xAAAA;	// Короткое слово с полосатым кодом 1010101010101010

void write_array(unsigned short*);
void dec_to_bin(unsigned short);

int main(int argc, char* argv[]) {
	register int i;
	int arr_size = BUFFER_SIZE/sizeof(unsigned short);	// Размер требуемого массива
	unsigned short* striped_arr = (unsigned short*) malloc(BUFFER_SIZE);
	if (striped_arr == NULL) return 1;

	for(i = 0; i < arr_size; i++)
		striped_arr[i] = STRIPED_WORD;
	
	for(i = 0; i < arr_size; i++)
		dec_to_bin(striped_arr[i]);

	write_array(striped_arr);

	free(striped_arr);
	getchar();
	return 0;
}

/* Запись в файл*/
void write_array(unsigned short* arr) {
	FILE* file;
	register int i;
	
	if((file = fopen("striped_file.bin", "wb")) == NULL) {
		printf("Error file opening.\n");
		return;
	}
	
	for(i = 0; i < BUFFER_SIZE/sizeof(unsigned short); i++)
		if(fwrite(&arr[i], sizeof(unsigned short), 1, file) != 1)
				printf("Error file writing.\n");
	
	fclose(file);
}

/* Перевод из десятичной в двоичную систему счисления.
Для проверки нашего полосатого кода ;)*/
void dec_to_bin(unsigned short num) {
	register int i;
	
	for(i = BUFFER_SIZE; i > 0; i = i/2)
		if(num & i) printf("1");
		else printf("0");
}