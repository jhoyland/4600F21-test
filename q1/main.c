/*

QUESTION 1:
write a function which will return the roots of a quadriatic including complex roots, it should take in the coefficients A,B and C  and should return both roots it should be able to cope with both real and complex roots and if given A = 0 should return the root of the linear equation.

write a main function to use your function to find the roots of several polynomials, printing out the roots including if they are complex numbers.

you may have your function in the main.c file or create and link a separate file as you wish

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void quadratic(double A, double B, double C, double *roots);


int main(int argc, char** argv)
{
	double A = 1.0;
	double B = 2.0;
	double C = 0.0; //x = 0, x = -2
	double roots[2];

	quadratic(A, B, C, roots);

	for(int i = 0; i<2; i++)
	{
		printf("x = %g\n", roots[i]);
	}


  return 0;
}

void quadratic(double A, double B, double C, double *roots)
{
	//-b+-sqrt(b^2-4ac)/2a
	//find the determinant first to determine what solutions are there.
	double determinant = (B*B)-(4*A*C);

	if(determinant > 0) //two real solutions
	{
		for(int i=0; i<2;i++)
		{
			if(i==0)
			{
				roots[i] = (-B+sqrt(determinant))/2.0/A;
				//printf("got here");
			}
			if(i==1)
			{
				roots[i] = (-B - sqrt(determinant))/2.0/A;

			}
		}
	}
	if(determinant == 0) //one real solution (this works)
	{
		for(int i = 0; i<2;i++)
		{
			roots[i] = -B/2.0/A;
		}
	}

	// JAMES: To return the complex solution you must return both
	// real and imaginary parts separately.

	// JAMES: Also needed the linear solution if A = 0

	if(determinant < 0) //complex solution, put in i
	{
		for(int i = 0; i<2; i++)
		{
			roots[i] = -B + sqrt(-(B*B)-(4*A*C))/(2.0*A);
		}
	}

}
