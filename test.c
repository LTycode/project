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
	//��������
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Initboard(board, ROW, COL);
	//��������
	Displayboard(board, ROW, COL);
	while (1)
	{
		//�������
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�ж��Ƿ�Ӯ
		ret=Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
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
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int input=0;
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("��");
			game();
			break;
		case 0:
			printf("�˳��ɹ�\n");
			break;
		default :
			printf("ѡ�����������ѡ��>:\n");
			break;
		}


	} while (input);
	return 0;
}