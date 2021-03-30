#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//菜单模块
void menu()
{
	printf("***************************\n");
	printf("****  1.play   0.exit  ****\n");
	printf("***************************\n");
}


//初始化棋盘
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



//显示棋盘
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


//玩家下棋
void Playmove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走》\n");
	while (1)
	{
		printf("请输入要走的坐标：");
		scanf("%d%d", &x, &y);
		//判断x，y坐标是否合法
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("改坐标已被占用！\n");
		}
		else
			printf("坐标非法！\n");
	}
}



//电脑下棋
void Computermove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下完》\n");
	while (1)
	{
		x = rand() % row;  //电脑走的随机数
		y = rand() % col;  //电脑走的随机数
		if (arr[x][y] == ' ') //判断该坐标是否为空白
		{
			arr[x][y] = '#';
			break;
		}
	}
}


//判断平局
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


//判断模块--输 or 赢 or 平局 or 继续
char Judge(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];

	}
	//竖三列
	for (i = 0; i < col; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];

	}
	//对角线(上到下)
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0]!= ' ')
		return arr[0][0];
	//对角线（下到上）
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0]!= ' ')
		return arr[2][0];
	//判断是否平局
	if (1 == IsFull(arr,ROW,COL))
		return 'Q';
	//继续
	return 'C';
}



//游戏实现模块
void game()
{
	// '*'-玩家赢  '#'-电脑赢  'Q'-平局  'C'-继续
	char ret = 0;
	//创建数组存放下棋的内容
	char arr[ROW][COL] = { 0 };
	//棋盘初始化
	init(arr, ROW, COL);
	//显示棋盘
	Displayboard(arr, ROW, COL);
	while (1)
	{
		//玩家下棋
		Playmove(arr, ROW, COL);
		//显示棋盘
		//Displayboard(arr, ROW, COL);
		//判断情况
		ret = Judge(arr, ROW, COL);
		if (ret != 'C')
			break;
		system("CLS");
		//电脑下棋
		Computermove(arr, ROW, COL);
		//显示棋盘
		Displayboard(arr, ROW, COL);
		//判断情况
		ret = Judge(arr, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		system("CLS");
		Displayboard(arr, ROW, COL);
		printf("玩家赢！\n");
	}
	else if (ret == '#')
	{
		system("CLS");
		Displayboard(arr, ROW, COL);
		printf("电脑赢！\n");
	}
	else
	{
		system("CLS");
		Displayboard(arr, ROW, COL);
		printf("平局！\n");
	}
}



//游戏测试模块
void test()
{
	int input = 0;
	system("mode con cols=27 lines=25");
	system("title **** 棋 盘 ****");
	srand((unsigned int)time(NULL)); //设置随机数的确定点
	do
	{
		menu(); //菜单
		printf("请选择>:");
		scanf("%d", &input);
		system("CLS");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			Sleep(1500);
			break;
		default:
			printf("输入错误，请重新选择！\n");
			break;
		}
	} while (input);
}



