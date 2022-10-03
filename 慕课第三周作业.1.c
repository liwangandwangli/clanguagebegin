#include<stdio.h>
int main()
{
	int time=0;
	printf("请输入BJT：");
	scanf("%d",&time);
	if(time<800){
	printf("世界协调时UTC:%d",2400-time)	;	
	}else{printf("世界协调时UTC：%d",time-800);
	}
	return 0;
	
}
