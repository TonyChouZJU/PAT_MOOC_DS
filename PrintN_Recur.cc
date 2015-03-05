#include<stdio.h>
#include<time.h>

void
PrintN(int N)
{
	int i;
	for(i = 0; i!=N; ++i)
		printf("%d\n",i);
}

int main()
{
	int N;
	time_t p_begin,p_end;			//define the pointer pointing to time_t
	scanf("%d",&N);
	p_begin = time((time_t*)NULL);
	PrintN(N);
	p_end = time((time_t*)NULL);
	printf("Now	:%ld\n",p_end-p_begin);

}
