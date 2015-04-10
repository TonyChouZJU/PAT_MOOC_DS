#include<stdio.h>
#include<stdlib.h>

int main(){
	double a=0;
	a = 5.0/0;
	int i =0;
	i = printf("%lf\n",a%10);
	printf("%d",i);

	return 0;
}
