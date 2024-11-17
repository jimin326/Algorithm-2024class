#include <stdio.h>

int i = 0;			// 퀵 정렬 단계 출력용 변수

// 주어진 부분집합 안에서 피봇의 위치를 확정하여 분할 위치를 정하는 연산
int partition(int a[], int begin, int end, int size) {
	int pivot, L, R, t, temp;
	L = begin + 1;	// 9장 연습문제 21번 풀이용
	R = end;
	pivot = begin;	// 정렬 범위에서 첫번째 원소 begin을 피봇으로 선택
	printf("\n [%d단계 : pivot = %d ] \n", ++i, a[pivot]);
	while (L <= R) {
		while (L <= end && a[L] < a[pivot]) L++;
		while (R >= begin && a[R] > a[pivot]) R--;		//  a[R] >= a[pivot]가 아님
		// while ((a[L] < a[pivot]) && (L < R)) L++;    //  L과 R이 교차되는 경우 배제하는 오류
		// while ((a[R] > a[pivot]) && (L < R)) R--;   //  L과 R이 교차되는 경우 배제하는 오류
		if (L < R) {			// L과 R 원소의 자리 교환
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;
		}	
	}

	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;

	for (t = 0; t < size; t++) printf("%5d", a[t]);	// 현재의 정렬 상태 출력
	printf("\n");
	return R;	// 정렬되어 확정된 피봇의 위치 반환
}

void quickSort(int a[], int begin, int end, int size) {
	int p;
	if (begin < end){
		p = partition(a, begin, end, size);		// 피봇의 위치에 의해 분할 위치 결정
		if (begin < p - 1) quickSort(a, begin, p - 1, size);
		if (p + 1 < end) quickSort(a, p + 1, end, size);
	}
}