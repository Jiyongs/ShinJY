//��������ġ �˰��� - LRU(Least Recently Used) �˰����� ����
//������ ��ġ ��, �������� ������� ���� �������� ����
//������ �迭�� ������ ť�� �̿�
//Count(�����) �̿��Ͽ�, �� �������� ������ ���� Ƚ���� ����(���α׷����� ����� ����� ����: Unused_Count)

#include<stdio.h>
int main()
{
	int i, j, F_idx = 0, Page_num, Page_array[50], Frame_Queue[20], Frame_num, Pault_count = 0;
	int d, r, temp, Frame_pointer, Unused_count_BignumSort[20], Unused_count[20];

	printf("\n 1. PAGE ������ �Է� : ");
	scanf("%d", &Page_num);
	printf("\n 2. ������ ������ŭ ���� ���ڿ��� �Է� : ");
	for (i = 0; i< Page_num; i++)
		scanf("%d", &Page_array[i]);
	printf("\n 3. FRAME ������ �Է� :");
	scanf("%d", &Frame_num);
	Frame_Queue[F_idx] = Page_array[F_idx];


	printf("\n  [���� ���ڿ�] \t[������ ������]\n");
	printf("	%d\t", Page_array[0]);
	printf("\t%d\n", Frame_Queue[F_idx]);
	//ù��° ���� ���ڿ��� �����ӿ� ä�� ��, ������ ��Ʈ(Pault_count)�� ������ �ε���(F_idx) 1 ����
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
		//���� ��� �����ӿ� ã�� ���ڿ��� ���ٸ�, ������ ��Ʈ 1 ����
		if (Frame_pointer == Frame_num)
		{
			Pault_count++;
			//�����ӿ� ���� ���ڿ��� �߰��س���
			//������ �ε����� ������ �������� ���� ���� �߰�
			if (F_idx<Frame_num)
			{
				Frame_Queue[F_idx] = Page_array[i];
				F_idx++;
				for (j = 0; j<F_idx; j++)
					printf("\t%d", Frame_Queue[j]);
			}
			//�������� �� ������ ��, ���� ���ڿ��� �������� ������ �ٸ��� �� �������� Unused_count�� ����
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
				//Unused_count_BignumSort[]�� Unused_count[]�� ���� ������
				for (r = 0; r < Frame_num; r++) {
					Unused_count_BignumSort[r] = Unused_count[r];
				}
				for (r = 0; r<Frame_num; r++)
				{
					for (j = r; j<Frame_num; j++)
					{
						//Unused_count_BignumSort[]�� Unused_count Ƚ���� ���� ������ ����(index 0���� �������� ����)
						//=> �ᱹ, Unused_count_BignumSort[0]�� ���� ���� Ƚ���� Unused_count�� ���Ե�
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
					/*��� ������ ��, ���� ū Unused_count�� ���� ������(������ ���� Ƚ���� ���� ū ������) ť��
					���� �����Ϸ��� ���ڿ� ���� ����*/
					if (Unused_count[r] == Unused_count_BignumSort[0])
						Frame_Queue[r] = Page_array[i];
				}
				for (j = 0; j<F_idx; j++)
					printf("\t%d", Frame_Queue[j]);
			}
		}
		printf("\n");
	}

	//������ ��Ʈ�� ��(Pault_count ���� ��)�� ���
	printf("\n\n  => Page Fault�� %d", Pault_count);
	printf("�� �Ͼ�ϴ�. \n\n");

	return 0;
}
