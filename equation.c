#include <stdio.h>
#include <math.h>
#include <float.h>

#define NO_ROOT       0
#define ONE_ROOT      1
#define TWO_ROOTS     2
#define ENDLESS_ROOTS 3

#define IsZero(x)     (fabs(x) <= DBL_EPSILON)
#define IsMoreZero(x) (x > DBL_EPSILON)
#define IsLessZero(x) (x < -DBL_EPSILON)


int SolveEquation (double a, double b, double c, double *x1, double *x2)
{
	if (IsZero (a))
	{
		//linear equation
		if (IsZero (b))
		{
			//constant
			if (IsZero (c))
			{
				//equation 0=0
				return ENDLESS_ROOTS;
			}
			else
			{
				//equation c=0, c!=0
				return NO_ROOT;
			}
		}
		else
		{
			//equation bx+c=0, b!=0
			*x1 = -c / b;
			return ONE_ROOT;
		}
	}
	else
	{
		//quadratic equation
		double d = b*b - (4*a*c);
		
		if (IsZero (d))
		{
			*x1 = -b / (2*a);
			return ONE_ROOT;
		}
		
		if (IsMoreZero (d))
		{
			double sqrt_d;
			sqrt_d = sqrt (d);
			*x1 = (-b - sqrt_d) / (2*a);
			*x2 = (-b + sqrt_d) / (2*a);
			return TWO_ROOTS;
		}
		
		if (IsLessZero (d))
		{
			return NO_ROOT;
		}
	}
	return -1; //never happens
}

int main (int argc, char *argv[])
{
	double a, b, c, x1, x2;
	
	puts ("Type the quadratic equation coefficients (a, b, c): ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	
	switch (SolveEquation (a, b, c, &x1, &x2))
	{
		case NO_ROOT:
			puts ("this equation has no roots");
			break;
		case ONE_ROOT:
			printf ("this equation has 1 root: x = %lf\n", x1);
			break;
		case TWO_ROOTS:
			printf ("this equation has 2 roots: x1 = %lf x2 = %lf\n", x1, x2);
			break;
		case ENDLESS_ROOTS:
			puts ("this equation has infinitely many roots");
			break;
	}
	return 0;
}
