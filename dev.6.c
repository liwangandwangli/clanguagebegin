#include<stdio.h>
int main()
{
	const int PASS=60;
	int score;
	
	printf("������ɼ���");
	scanf("%d",&score);
	
	printf("������ĳɼ���%d.\n",score);
	if(score<PASS)
	printf("���ź���������ɼ�û�кϸ�");
	else {
	printf("ף���㣬�ϸ��ˣ�");
	printf("�ټ�\n");
	return 0;}
}
