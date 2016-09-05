/*
Тестовая задача 3
main.cpp
Яковлев Евгений Сергеевич
02.09.2016 12:15
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BUFFER_SIZE = 32768;	// Размер буфера
const int CYCLIC_SHIFT = 5;	// Размер циклического сдвига
const int arr_size = BUFFER_SIZE/sizeof(unsigned short);	//число элементов массива

void write_array(unsigned short*);
void read_arrays(unsigned short*, unsigned short*);
void shift_arr_r(unsigned short*, int);

int main(int argc, char* argv[]) {
	register int i;
	int temp;
	unsigned short* addr_arr = (unsigned short*) malloc(BUFFER_SIZE);
	if(addr_arr == NULL) return 1;

	for(i = 0; i < arr_size; i++)
		addr_arr[i] = i;

	/* Проверка адресного кода 
	for(i = 0; i < arr_size; i++)
		printf("%d\n", addr_arr[i]);
	*/
	write_array(addr_arr); 

	for(i = 0; i < arr_size; i++)
		addr_arr[i] = arr_size - 1 - i;

	/* Проверка обратного адресного кода 
	for(i = 0; i < arr_size; i++)
		printf("%d\n", addr_arr[i]);
	*/
	write_array(addr_arr);
	free(addr_arr);

	unsigned short* buff_arr1 = (unsigned short*) malloc(BUFFER_SIZE);
	unsigned short* buff_arr2 = (unsigned short*) malloc(BUFFER_SIZE);
	read_arrays(buff_arr1, buff_arr2);

	for(i = 0; i < arr_size; i+=2) {
		temp = buff_arr1[i];
		buff_arr1[i] = buff_arr1[i+1];
		buff_arr1[i+1] = temp;

		temp = buff_arr2[i];
		buff_arr2[i] = buff_arr2[i+1];
		buff_arr2[i+1] = temp;
	}
	/* Проверка перемешанного массива 
	for(i = 0; i < arr_size; i++)
		printf("%d\n", buff_arr1[i]);
	*/

	shift_arr_r(buff_arr1, CYCLIC_SHIFT);
	write_array(buff_arr1);
	shift_arr_r(buff_arr2, CYCLIC_SHIFT);
	write_array(buff_arr2);
	/* Проверка сдвинутого массива 
	for(i = 0; i < arr_size; i++)
		printf("%d\n", buff_arr1[i]);
	*/

	free(buff_arr1);
	free(buff_arr2);
	getchar();
	return 0;
}

/* Запись массива в файл */
void write_array(unsigned short* arr) {
	FILE* file;
	register int i;
	char file_name[43];

	printf("Enter writing file name(max 40 char): ");
	gets(file_name);
	strcat(file_name,".bin");
	if((file = fopen(file_name, "wb")) == NULL) {
		printf("Error file opening.\n");
		return;
	}
	for(i = 0; i < arr_size; i++)
		if(fwrite(&arr[i], sizeof(unsigned short), 1, file) != 1)
			printf("Error file writing.\n");
	
	fclose(file);
}

/* Чтение массивов из файла */
void read_arrays(unsigned short* arr1, unsigned short* arr2) {
	FILE *file1, *file2;
	register int i;
	char file_name[43];

	/* Чтение первого файла */
	printf("Enter reading file name(max 40 char): ");
	gets(file_name);
	strcat(file_name,".bin");
	if((file1 = fopen(file_name, "rb")) == NULL) {
		printf("Error file opening.\n");
		return;
	}
	for(i = 0; i < arr_size; i++)
		if(fread(&arr1[i], sizeof(unsigned short), 1, file1) != 1)
			printf("Error file reading.\n");

	/* Чтение второго файла */
	printf("Enter reading file name(max 40 char): ");
	gets(file_name);
	strcat(file_name,".bin");
	if((file2 = fopen(file_name, "rb")) == NULL) {
		printf("Error file opening.\n");
		return;
	}
	for(i = 0; i < arr_size; i++)
		if(fread(&arr2[i], sizeof(unsigned short), 1, file2) != 1)
			printf("Error file reading.\n");

	fclose(file1);
	fclose(file2);
}

/* Сдвиг массива вправо на N элементов */
void shift_arr_r(unsigned short* arr, int N) {
	register int i, j;
	unsigned short* temp_arr1 = (unsigned short*) malloc((arr_size - N)*sizeof(unsigned short));
	unsigned short* temp_arr2 = (unsigned short*) malloc(N*sizeof(unsigned short));

	for(i = arr_size-N, j = 0; i < arr_size; i++, j++)
		temp_arr2[j] = arr[i];

	for(i = 0; i < arr_size-N; i++)
		temp_arr1[i] = arr[i];

	for(i = 0; i < N; i++)
		arr[i] = temp_arr2[i];
	for(i = N; i < arr_size; i++)
		arr[i] = temp_arr2[i-N];

	free(temp_arr1);
	free(temp_arr2);
}






/* Сдвиг массива вправо на N элементов
void shift_arr_r(unsigned char* arr, int N) {
	register int i, j;
	unsigned short* temp_arr1 = (unsigned short*) malloc((arr_size - N)*sizeof(unsigned char));
	unsigned short* temp_arr2 = (unsigned short*) malloc(N*sizeof(unsigned char));

	for(i = arr_size-N-1, j = 0; i >= 0; i--, j++)
		temp_arr1[j] = arr[i];

	for(i = arr_size, j = 0; i < arr_size-N; i--, j++)
		temp_arr2[j] = arr[i];

	for(i = 0; i < N; i++)



	free(temp_arr1);
	free(temp_arr2);
}
*/