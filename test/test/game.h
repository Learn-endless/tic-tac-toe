#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

#define ROW 3  //棋盘的行
#define COL 3  //棋盘的列

void menu(); //菜单

void test();//游戏测试模块

void init(char arr[ROW][COL], int row, int col); //棋盘初始化

void Displayboard(char arr[ROW][COL], int row, int col); //显示棋盘

void Playmove(char arr[ROW][COL],int row,int col);  //玩家下棋

void Computermove(char arr[ROW][COL],int row,int col); //电脑下棋

char Judge(char arr[ROW][COL], int row, int col); //判断情况- 输 or 赢 or 平局 or 继续

int IsFull(char arr[ROW][COL],int row,int col); //判断是否平局