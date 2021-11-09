/*

QUESTION 2:

	write a function which will calculate the sin or cos using the series expansion. The user of the function should be able to specify the the number of terms to calculate.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double seriesExpansion(double x, int nterms, int mode);
double factorial(int x);


int main(int argc, char** argv)
{
	double value = 0.0;
	value = seriesExpansion(3.14159, 4, 0); //sin(pi) 4 terms
	//printf("hello\n");
	printf("%g\n", value);

  return 0;
}


double seriesExpansion(double x, int nterms, int mode) //number of terms. mode 0 for sin, 1 for cos
{
	double positive = 0.0;
	double negative = 0.0;
	double expansion = 0.0;
	double fact = 0.0;
	int i=0;
	int j=0;
	if(mode == 0)
	{
		//when nterms is even, num of positive and negative terms are same.
		//when nterms is odd,  num of positive is one more than negative.
		//sinx

		// JAMES: Nice solution!
		for(j=1; j<nterms*2; j=j+4) // (x^1), -x^3, (x^5), -x^7
		{
			fact = factorial(j);
			positive += pow(x,j)/fact;
		}
		for(i=3; i<=nterms*2; i=i+4) // x^1, (-x^3), x^5, (-x^7)
		{
			fact = factorial(i);
			negative += -pow(x,i)/fact;
		}

	}
	if(mode == 1)
	{
		//cosx
		for(j=0; j<nterms*2-3; j=j+4) // (x^0), -x^2, (x^4), -x^6
		{
			fact = factorial(j);
			positive += pow(x,j)/fact;
		}
		for(i=2; i<nterms*2; i=i+4) // x^0, (-x^2), x^4, (-x^6)
		{
			fact = factorial(i);
			negative += -pow(x,i)/fact;
		}

	}
	expansion = positive + negative;
	return expansion;
}

double factorial(int x)
{
	double fact = 1.0;
	int i=0;
	for(i=1; i<=x; i++)
	{
		fact = fact * i;
	}
	return fact;
}
