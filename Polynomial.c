#include<stdio.h>
#include<time.h>
#include<math.h>

time_t start,stop; 
double duration;
#define MAXN 10			/*多项式的最大项数，即多项式的阶数+1*/
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);
int main()
{
	int i;
	double a[MAXN];
	for(i = 0; i != MAXN; ++i) a[i]=(double)i;

	start = time((time_t*)NULL);
	f1(MAXN-1, a, 1.1);
	stop = time((time_t*)NULL);
	duration = (double)(stop-start);
	printf("duration = %6.2e\n",duration);

	start = time((time_t*)NULL);
	f2(MAXN-1, a, 1.1);
	stop = time((time_t*)NULL);
	duration = ((double)(stop-start));
	printf("duration = %6.2e\n",duration);
	return 0;
} 

double
f1(int n, double a[], double x)
{
	double f=0;
	int i;
	for(i =0; i != n+1; ++i)
		f = f + a[i]*pow(x,i); 
	return f;
}

double
f2(int n, double a[], double x)
{
	double f=a[n];
	int i;
	for(i = n; i != 0; --i)
		f = a[i-1] + f*x;
		
	return f;
}

