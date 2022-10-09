#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("**************************\n");
	printf("****1.play     0.exit ****\n");
	printf("**************************\n");
}
void game()
{
	char ret = 0;
	//创建数组
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	Initboard(board, ROW, COL);
	//创建棋盘
	Displayboard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//判断是否赢
		ret=Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret=Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int input=0;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("玩");
			game();
			break;
		case 0:
			printf("退出成功\n");
			break;
		default :
			printf("选择错误，请重新选择>:\n");
			break;
		}


	} while (input);
	return 0;
}