#include<stdio.h>

int main()
{
	srand(time(0));
	int number=rand()%100+1;
	int count=-0;
	int a=0;
	printf("���Ѿ������һ��1-100֮�������");
	do{
		printf("��²����1��100�����Ƕ���");
		scanf("%d",&a);
		count++;
		if(a>number){
			printf("��µ�������");
			 
		}else if(a<number){
			printf("��µ���С��");	
		}
	} while(a!=number);
		printf("��¶���\n"); 
	
}
