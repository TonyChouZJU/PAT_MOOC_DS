#include<stdio.h>

int main()
{
	int a = -1;
	char s[20];
	int m,n;
	m =10;
	n = 6;
	printf("d:%d u:%u o:%o x:%x f:%f\n",a,a,a,a,(float)a );
	scanf("%s",s);
	printf("%s\n",s);
	printf("%*.*s\n",m,n,s);
	return 0;
}

