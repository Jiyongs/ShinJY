//��������ġ �˰��� - PIPO ť(���Լ���) �˰����� ����
//������ �迭�� ������ �迭�� �̿�

#include<stdio.h>
int main()
{
	int i, j = 0, k, Page_num, Page_array[50], frame[10], Frame_num, avail, P_count = 0;

	printf("\n 1. PAGE ������ �Է� :");
	scanf("%d", &Page_num);
	printf("\n 2. ������ ������ŭ ���� ���ڿ��� �Է� :");
	for (i = 1; i <= Page_num; i++)
		scanf("%d", &Page_array[i]);
	printf("\n 3. FRAME ������ �Է� :");
	scanf("%d", &Frame_num);
	for (i = 0; i < Frame_num; i++)
		frame[i] = -1;

	printf("\n[���� ���ڿ�] \t   [������ ������]\n");

	//������ ������ŭ �ݺ�
	for (i = 1; i <= Page_num; i++)
	{
		printf("     %d\t\t", Page_array[i]);
		avail = 0;
		//������ ������ŭ �ݺ�
		for (k = 0; k < Frame_num; k++) {
			//������ �迭�� ������ �迭�� ���� ������(=���ϴ� ���� ������ �迭�� �ִٸ�) avail=1
			if (frame[k] == Page_array[i])
				avail = 1;
		}

		//avail�� 0�̸�(�����Ӱ� ������ �迭�� ���� �ٸ��ų�, ������ �迭�� ����ٸ�), ������ ��Ʈ �߻�!
		if (avail == 0)
		{
			frame[j] = Page_array[i];
			j = (j + 1) % Frame_num;
			P_count++; //������ ��Ʈ�� �� ����
			for (k = 0; k < Frame_num; k++)
				printf("   %d\t", frame[k]);
		}
		printf("\n");
	}
	//������ ��Ʈ�� ��(P_count ���� ��)�� ���
	printf("\n  => Page Fault�� %d", P_count);
	printf("�� �Ͼ�ϴ�. \n\n");
	return 0;
}