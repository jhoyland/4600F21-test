/*

QUESTION 1:
write a function which will return the roots of a quadriatic including complex roots, it should take in the coefficients A,B and C  and should
return both roots it should be able to cope with both real and complex roots and if given A = 0 should return the root of the linear equation.

write a main function to use your function to find the roots of several polynomials, printing out the roots including if they are complex numbers.

you may have your function in the main.c file or create and link a separate file as you wish

*/
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>


/*
JAMES: The function was supposed to return the roots. It was also supposed to cope with the
the special case of a linear root if a = 0.
*/

void quadratic(double a, double b, double c)
{
double x1;
double x2;
double complex y1;
double complex y2;

/*JAMES: What happens if 4*a*c == b*b? */

/*JAMES: So this will work fine, but there is an efficiency problem here:
You calculate b*b-4*a*c multiple times (in your tests and when assigning the roots.) It would
be much more efficient if you calculated this once and put the value in a local variable.
*/

if(4*a*c < b*b)
 {
	x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
	x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
	printf("x1 = %f\n",x1);
	printf("x2 = %f\n",x2);
 }
 if(4*a*c > b*b)
  {
   y1=-b/(2*a)+sqrt(4*a*c-b*b)/(2*a)*I;
   y2=-b/(2*a)-sqrt(4*a*c-b*b)/(2*a)*I;
  	printf("x1=%f+%fi\n",creal(y1),cimag(y1));
  	printf("x2=%f%fi\n",creal(y2),cimag(y2));
  }

}

int main(int argc, char** argv)
{
  quadratic(2,3,5);
  return 0;
}
