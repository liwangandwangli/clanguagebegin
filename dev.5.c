#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%f %f %f",&a,&b,&c);
	int max=0;
	if (a>b) {
		if (a>c) {
			max=a;
		} else {max=c;
		}
	} else {
		if (b>c) {
			max=b;
		} else {
			max=c;
		}
	}
	printf("the max is %f\n",max);
	return 0;
}

