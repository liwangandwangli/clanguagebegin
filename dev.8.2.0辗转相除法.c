#include<stdio.h>

int main()
{
	int a,b;
	int t; 
	scanf("%d %d",&a,&b);
	int ariga=a;
	int origb=b;
	while(b!=0){
	t=a%b;
	a=b;
	b=t;
	}
	printf("%d��%d�����Լ����%d\n",ariga,origb,a);
	
	return 0;
 } 
