#include<stdio.h>
 
int main()
{
	int price=0;
	int bill=0;
	printf("�������");
	scanf("%d",&price);
	printf("������Ʊ�棺");
	scanf("%d",&bill);
	if(price<=bill){
		printf("Ӧ��������%d\n",bill-price);
	}else{
		printf("������Ǯ����Ŷ��"); 
	}
	return 0;
}
