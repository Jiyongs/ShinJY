//페이지대치 알고리즘 - PIPO 큐(선입선출) 알고리즘의 구현
//페이지 배열과 프레임 배열을 이용

#include<stdio.h>
int main()
{
	int i, j = 0, k, Page_num, Page_array[50], frame[10], Frame_num, avail, P_count = 0;

	printf("\n 1. PAGE 개수를 입력 :");
	scanf("%d", &Page_num);
	printf("\n 2. 페이지 개수만큼 참조 문자열을 입력 :");
	for (i = 1; i <= Page_num; i++)
		scanf("%d", &Page_array[i]);
	printf("\n 3. FRAME 개수를 입력 :");
	scanf("%d", &Frame_num);
	for (i = 0; i < Frame_num; i++)
		frame[i] = -1;

	printf("\n[참조 문자열] \t   [페이지 프레임]\n");

	//페이지 개수만큼 반복
	for (i = 1; i <= Page_num; i++)
	{
		printf("     %d\t\t", Page_array[i]);
		avail = 0;
		//프레임 개수만큼 반복
		for (k = 0; k < Frame_num; k++) {
			//프레임 배열과 페이지 배열의 값이 같으면(=원하는 값이 프레임 배열에 있다면) avail=1
			if (frame[k] == Page_array[i])
				avail = 1;
		}

		//avail이 0이면(프레임과 페이지 배열의 값이 다르거나, 페이지 배열이 비었다면), 페이지 폴트 발생!
		if (avail == 0)
		{
			frame[j] = Page_array[i];
			j = (j + 1) % Frame_num;
			P_count++; //페이지 폴트의 수 증가
			for (k = 0; k < Frame_num; k++)
				printf("   %d\t", frame[k]);
		}
		printf("\n");
	}
	//페이지 폴트의 수(P_count 변수 값)를 출력
	printf("\n  => Page Fault는 %d", P_count);
	printf("번 일어납니다. \n\n");
	return 0;
}