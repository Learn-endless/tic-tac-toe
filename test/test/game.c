#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//�˵�ģ��
void menu()
{
	printf("***************************\n");
	printf("****  1.play   0.exit  ****\n");
	printf("***************************\n");
}


//��ʼ������
void init(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}



//��ʾ����
void Displayboard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j<col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}


//�������
void Playmove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߡ�\n");
	while (1)
	{
		printf("������Ҫ�ߵ����꣺");
		scanf("%d%d", &x, &y);
		//�ж�x��y�����Ƿ�Ϸ�
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�������ѱ�ռ�ã�\n");
		}
		else
			printf("����Ƿ���\n");
	}
}



//��������
void Computermove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�������꡷\n");
	while (1)
	{
		x = rand() % row;  //�����ߵ������
		y = rand() % col;  //�����ߵ������
		if (arr[x][y] == ' ') //�жϸ������Ƿ�Ϊ�հ�
		{
			arr[x][y] = '#';
			break;
		}
	}
}


//�ж�ƽ��
int IsFull(char arr[ROW][COL],int row,int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}


//�ж�ģ��--�� or Ӯ or ƽ�� or ����
char Judge(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	//������
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];

	}
	//������
	for (i = 0; i < col; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];

	}
	//�Խ���(�ϵ���)
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0]!= ' ')
		return arr[0][0];
	//�Խ��ߣ��µ��ϣ�
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0]!= ' ')
		return arr[2][0];
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(arr,ROW,COL))
		return 'Q';
	//����
	return 'C';
}



//��Ϸʵ��ģ��
void game()
{
	// '*'-���Ӯ  '#'-����Ӯ  'Q'-ƽ��  'C'-����
	char ret = 0;
	//�������������������
	char arr[ROW][COL] = { 0 };
	//���̳�ʼ��
	init(arr, ROW, COL);
	//��ʾ����
	Displayboard(arr, ROW, COL);
	while (1)
	{
		//�������
		Playmove(arr, ROW, COL);
		//��ʾ����
		//Displayboard(arr, ROW, COL);
		//�ж����
		ret = Judge(arr, ROW, COL);
		if (ret != 'C')
			break;
		system("CLS");
		//��������
		Computermove(arr, ROW, COL);
		//��ʾ����
		Displayboard(arr, ROW, COL);
		//�ж����
		ret = Judge(arr, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		system("CLS");
		Displayboard(arr, ROW, COL);
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		system("CLS");
		Displayboard(arr, ROW, COL);
		printf("����Ӯ��\n");
	}
	else
	{
		system("CLS");
		Displayboard(arr, ROW, COL);
		printf("ƽ�֣�\n");
	}
}



//��Ϸ����ģ��
void test()
{
	int input = 0;
	system("mode con cols=27 lines=25");
	system("title **** �� �� ****");
	srand((unsigned int)time(NULL)); //�����������ȷ����
	do
	{
		menu(); //�˵�
		printf("��ѡ��>:");
		scanf("%d", &input);
		system("CLS");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			Sleep(1500);
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
}



