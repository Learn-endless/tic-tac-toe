#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

#define ROW 3  //���̵���
#define COL 3  //���̵���

void menu(); //�˵�

void test();//��Ϸ����ģ��

void init(char arr[ROW][COL], int row, int col); //���̳�ʼ��

void Displayboard(char arr[ROW][COL], int row, int col); //��ʾ����

void Playmove(char arr[ROW][COL],int row,int col);  //�������

void Computermove(char arr[ROW][COL],int row,int col); //��������

char Judge(char arr[ROW][COL], int row, int col); //�ж����- �� or Ӯ or ƽ�� or ����

int IsFull(char arr[ROW][COL],int row,int col); //�ж��Ƿ�ƽ��