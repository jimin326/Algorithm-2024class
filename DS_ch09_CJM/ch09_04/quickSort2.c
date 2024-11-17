#include <stdio.h>

int i = 0;			// �� ���� �ܰ� ��¿� ����

// �־��� �κ����� �ȿ��� �Ǻ��� ��ġ�� Ȯ���Ͽ� ���� ��ġ�� ���ϴ� ����
int partition(int a[], int begin, int end, int size) {
	int pivot, L, R, t, temp;
	L = begin + 1;	// 9�� �������� 21�� Ǯ�̿�
	R = end;
	pivot = begin;	// ���� �������� ù��° ���� begin�� �Ǻ����� ����
	printf("\n [%d�ܰ� : pivot = %d ] \n", ++i, a[pivot]);
	while (L <= R) {
		while (L <= end && a[L] < a[pivot]) L++;
		while (R >= begin && a[R] > a[pivot]) R--;		//  a[R] >= a[pivot]�� �ƴ�
		// while ((a[L] < a[pivot]) && (L < R)) L++;    //  L�� R�� �����Ǵ� ��� �����ϴ� ����
		// while ((a[R] > a[pivot]) && (L < R)) R--;   //  L�� R�� �����Ǵ� ��� �����ϴ� ����
		if (L < R) {			// L�� R ������ �ڸ� ��ȯ
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;
		}	
	}

	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;

	for (t = 0; t < size; t++) printf("%5d", a[t]);	// ������ ���� ���� ���
	printf("\n");
	return R;	// ���ĵǾ� Ȯ���� �Ǻ��� ��ġ ��ȯ
}

void quickSort(int a[], int begin, int end, int size) {
	int p;
	if (begin < end){
		p = partition(a, begin, end, size);		// �Ǻ��� ��ġ�� ���� ���� ��ġ ����
		if (begin < p - 1) quickSort(a, begin, p - 1, size);
		if (p + 1 < end) quickSort(a, p + 1, end, size);
	}
}