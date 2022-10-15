#include<stdio.h>

int max(int a,int b)
{
	int ret;
	if(a>b){
		ret=a;
	} else {
		ret=b;
	}
	return ret;
 } 
 
 int main()
 {
 	int a,b,c; 
 	scanf("%d %d",&a,&b);
 	c=max(a,b);
 	c=max(c,100);
 	printf("%d\n",max(a,b));
 	return 0;
 }
