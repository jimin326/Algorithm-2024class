#include <stdio.h>
void quickSort(int a[], int begin, int end, int size);

int main(void) {
	int i, list[10] = {66, 51, 11, 98, 55, 1, 70, 35, 79, 41};
	int size = sizeof(list) / sizeof(list[0]);		// list �迭�� ���� ����
	printf("\n ������ ���� : ");
	for (i = 0; i < size; i++) printf("%3d", list[i]);
	printf("\n\n<<<<<<<<<< �� ���� ���� >>>>>>>>>>\n");

	quickSort(list, 0, size - 1, size);

	getchar(); return 0;
}