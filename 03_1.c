#include<stdio.h>
#include<stdlib.h>

double a3,a2,a1,a0;
double a,b;
double mid;
double gen;
double
compute(double x)
{
	return ((a3*x+a2)*x+a1)*x+a0;

}
int main()
{
	scanf("%lf%lf%lf%lf",&a3,&a2,&a1,&a0);
	scanf("%lf%lf",&a,&b);
	
	while(fabs(b-a)>0.0001)
	{
		if(compute(a)==0)
		{
			b=a;break;
		}
		if(compute(b)==0)
		{
			a=b;break;
		}
		if(compute((a+b)/2)==0)
			//gen = (a+b)/2;		
			break;
		else {if(compute((a+b)/2)*compute(b)>0)
			b = (a+b)/2;
			else
			a = (a+b)/2;}
	//	printf("a:%f %f;b:%f %f;a+b/2%f %f\n",a,compute(a),b,compute(b),(a+b)/2,compute((a+b)/2));
	}	
	printf("%.2lf",(a+b)/2);
	return 0;
}
