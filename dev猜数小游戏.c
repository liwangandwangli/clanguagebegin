#include<stdio.h>

int main()
{
	srand(time(0));
	int number=rand()%100+1;
	int count=-0;
	int a=0;
	printf("我已经想好了一个1-100之间的数。");
	do{
		printf("请猜猜这个1到100的数是多少");
		scanf("%d",&a);
		count++;
		if(a>number){
			printf("你猜的数大了");
			 
		}else if(a<number){
			printf("你猜的数小了");	
		}
	} while(a!=number);
		printf("你猜对了\n"); 
	
}
