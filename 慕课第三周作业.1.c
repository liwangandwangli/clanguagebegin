#include<stdio.h>
int main()
{
	int time=0;
	printf("������BJT��");
	scanf("%d",&time);
	if(time<800){
	printf("����Э��ʱUTC:%d",2400-time)	;	
	}else{printf("����Э��ʱUTC��%d",time-800);
	}
	return 0;
	
}
