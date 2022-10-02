#include<stdio.h>
 
int main()
{
	int price=0;
	int bill=0;
	printf("请输入金额：");
	scanf("%d",&price);
	printf("请输入票面：");
	scanf("%d",&bill);
	if(price<=bill){
		printf("应该找您：%d\n",bill-price);
	}else{
		printf("您给的钱不够哦。"); 
	}
	return 0;
}
