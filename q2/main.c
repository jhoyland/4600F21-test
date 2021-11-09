/*

QUESTION 2:

	write a function which will calculate the sin or cos using the series expansion. The user of the function should be able to specify the the number of terms to calculate.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SERIES_COS 0
#define SERIES_SIN 1

/*
 The series function works for either sin or cos. In each case each successive term is calculated by multiplying the previous term by - x^2 / (m*(m-1))

 x^2: because each term is power of 2 higher than the previous term.
 m(m-1): the counter m increases by 2 for each term starting at 1 for sin or 0 for cos to give either odd or even numbers. m(m-1) multiplies the denominator by the new value of AND one less to give the correct factorial. This saves having to actually have a factorial function.
 - : the minus sign makes sure the sign of each term alternates
*/

double trig_taylor(double x, int n, int trig_function)
{
	double r,t,m;

  /* Set the first term to 1 or x */

	if(trig_function == SERIES_COS)
		t = 1;  // Cosine
	else
		t = x;  // Sin

	r = t;
	m = trig_function;  // m starts at 1 for sin and 0 for cos giving either even or odd numbers

	for(int i=1;i<n;i++)
	{
		m += 2;
		t *= - x * x / (m * (m-1)); // Calculate the new term from the old one
		r += t;

	}

	return r;
}

double series_sin(double x, int n)
{
  return trig_taylor(x,n,SERIES_SIN);
}

double series_cos(double x, int n)
{
  return trig_taylor(x,n,SERIES_COS);
}

int main(int argc, char** argv)
{

  double x = 0.5 * M_PI;

  int n = 14;

  char* p;

  if(argc>1)
  {
    x = strtod(argv[1],&p);
    if(argc>2)
      n = strtol(argv[2],&p,10);
  }

  if(n<1) n = 1;

  double sm = sin(x);
  double cm = cos(x);

  double st,ct;

  printf("\nmath.h sin of %f = %f",x,sm);
  printf("\nmath.h cos of %f = %f",x,cm);

  printf("\n Series solutions: \nTERMS\tSIN\t\tCOS");
  for(int j = 1; j<=n; j++)
  {
    st = series_sin(x,j);
    ct = series_cos(x,j);
    printf("\n%d\t%9.7f\t%9.7f",j,st,ct);
  }


  return 0;
}
