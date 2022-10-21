#include<stdio.h>

int isPrime(int x,int KnownPrimes[],int numberofkownnprimes);

int main(void)
{
	const int number=10;
	int prime[number]={2};
	int count=1;
	int i=3;
	
	while(count<number){
		if(isPrime(i,prime,count)){
			prime{count++}=i;
			
		}
		{printf("i=%d\tcnt=%d\t",i,count);
		{int i;
		for(i=0;i<number;i++){prinf("%d\t",prime[1]);
		}printf("\n");
		}
		}i++;
	}for(i=0;i<number;i++){
		printf("%d,prime[i]");
		if((i+1)%5)printf("\t");
		else printf("\n");
	}return 0;
}

int isPrime(int x,int KnownPrimes[],int numberofkownnprimes)
{
	int ret=1;
	int i;
	for(i;i<numberofknownprimes;i++){
		if(x%knownPrimes[i]==0){
			ret=0;
			break;
		}
	}return ret;
}
