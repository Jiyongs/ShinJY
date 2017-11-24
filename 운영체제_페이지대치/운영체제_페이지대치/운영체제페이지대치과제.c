//페이지대치 알고리즘 - LRU(Least Recently Used) 알고리즘의 구현
//페이지 대치 시, 오랫동안 사용하지 않은 페이지를 선택
//페이지 배열과 프레임 큐를 이용
//Count(계수기) 이용하여, 각 프레임의 사용되지 않은 횟수를 저장(프로그램에서 사용한 계수기 변수: Unused_Count)

#include<stdio.h>
int main()
{
	int i, j, F_idx = 0, Page_num, Page_array[50], Frame_Queue[20], Frame_num, Pault_count = 0;
	int d, r, temp, Frame_pointer, Unused_count_BignumSort[20], Unused_count[20];

	printf("\n 1. PAGE 개수를 입력 : ");
	scanf("%d", &Page_num);
	printf("\n 2. 페이지 개수만큼 참조 문자열을 입력 : ");
	for (i = 0; i< Page_num; i++)
		scanf("%d", &Page_array[i]);
	printf("\n 3. FRAME 개수를 입력 :");
	scanf("%d", &Frame_num);
	Frame_Queue[F_idx] = Page_array[F_idx];


	printf("\n  [참조 문자열] \t[페이지 프레임]\n");
	printf("	%d\t", Page_array[0]);
	printf("\t%d\n", Frame_Queue[F_idx]);
	//첫번째 참조 문자열을 프레임에 채울 때, 페이지 폴트(Pault_count)와 프레임 인덱스(F_idx) 1 증가
	Pault_count++;
	F_idx++;

	for (i = 1; i<Page_num; i++)
	{
		printf("	%d\t", Page_array[i]);
		Frame_pointer = 0;
		for (j = 0; j<Frame_num; j++)
		{
			if (Page_array[i] != Frame_Queue[j])
				Frame_pointer++;
		}
		//만약 모든 프레임에 찾는 문자열이 없다면, 페이지 폴트 1 증가
		if (Frame_pointer == Frame_num)
		{
			Pault_count++;
			//프레임에 참조 문자열을 추가해나감
			//프레임 인덱스가 프레임 개수보다 적을 때만 추가
			if (F_idx<Frame_num)
			{
				Frame_Queue[F_idx] = Page_array[i];
				F_idx++;
				for (j = 0; j<F_idx; j++)
					printf("\t%d", Frame_Queue[j]);
			}
			//프레임이 꽉 차있을 때, 참조 문자열과 프레임의 내용이 다르면 그 프레임의 Unused_count를 증가
			else
			{
				for (r = 0; r<Frame_num; r++)
				{
					Unused_count[r] = 0;
					for (j = i - 1; j<Page_num; j--)
					{
						if (Frame_Queue[r] != Page_array[j])
							Unused_count[r]++;
						else
							break;
					}
				}
				//Unused_count_BignumSort[]에 Unused_count[]의 값을 복사함
				for (r = 0; r < Frame_num; r++) {
					Unused_count_BignumSort[r] = Unused_count[r];
				}
				for (r = 0; r<Frame_num; r++)
				{
					for (j = r; j<Frame_num; j++)
					{
						//Unused_count_BignumSort[]에 Unused_count 횟수가 많은 순으로 정렬(index 0부터 오름차순 정렬)
						//=> 결국, Unused_count_BignumSort[0]에 제일 많은 횟수의 Unused_count가 들어가게됨
						if (Unused_count_BignumSort[r]<Unused_count_BignumSort[j])
						{
							temp = Unused_count_BignumSort[r];
							Unused_count_BignumSort[r] = Unused_count_BignumSort[j];
							Unused_count_BignumSort[j] = temp;
						}
					}
				}
				for (r = 0; r<Frame_num; r++)
				{
					/*모든 프레임 중, 가장 큰 Unused_count를 가진 프레임(사용되지 않은 횟수가 제일 큰 프레임) 큐에
					현재 참조하려는 문자열 값을 넣음*/
					if (Unused_count[r] == Unused_count_BignumSort[0])
						Frame_Queue[r] = Page_array[i];
				}
				for (j = 0; j<F_idx; j++)
					printf("\t%d", Frame_Queue[j]);
			}
		}
		printf("\n");
	}

	//페이지 폴트의 수(Pault_count 변수 값)를 출력
	printf("\n\n  => Page Fault는 %d", Pault_count);
	printf("번 일어납니다. \n\n");

	return 0;
}
