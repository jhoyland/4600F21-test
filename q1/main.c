/*

QUESTION 1:
write a function which will return the roots of a quadriatic including complex roots, it should take in the coefficients A,B and C  and should return both roots it should be able to cope with both real and complex roots and if given A = 0 should return the root of the linear equation.

write a main function to use your function to find the roots of several polynomials, printing out the roots including if they are complex numbers.

you may have your function in the main.c file or create and link a separate file as you wish

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  Solutions of quadratic:
  A x^2 + B c + C =0

  Coefficients sent as:
  c[0] = C
  c[1] = B
  c[2] = A

  returns x1 & x2 roots

  x1[0] = real part
  x1[1] = imag part
*/
void quadratic_roots(double * c, double * x1, double * x2)
{
  // Set imaginary parts to zero
	x1[1] = 0;
	x2[1] = 0;

  // If squared coefficients are zero we have a linear equation. Set both real parts
  // to the solution

	if(c[2] == 0)
	{
		x1[0] = x2[0] = - c[0] / c[1];

		return;
	}

  // Set the real parts to -B / 2A
	x1[0] = x2[0] = - 0.5 * c[1] / c[2];

  // Calculate the descriminant
	double descriminant = c[1] * c[1] - 4.0 * c[0] * c[2];

  // Calculate the sqrt( descriminant ) / 2A  using the absolute value of the
	double term = 0.5 * sqrt(fabs(descriminant)) / c[2];

  // If the descriminant is positive (real root) - add term to the real part
  // if the descriminant is negative (complex root) - term is the imaginary part
	if(descriminant >= 0)
	{
		x1[0] += term;
		x2[0] -= term;
	}
	else
	{
		x1[1] = term;
		x2[1] = -term;
	}


}

// A little function for printing complex numbers

void print_complex(double* x)
{
  printf("%0.5f ",x[0]);

  if(x[1]<0)
    printf("-");
  else
    printf("+");

  printf(" i %0.5f",fabs(x[1]));
}

void print_quadratic(double* c)
{
  printf("%0.4f x^2 ",c[2]);
  if(c[1]>=0) printf("+");
  printf("%0.4f x ",c[1]);
  if(c[0]>=0) printf("+");
  printf("%0.4f",c[0]);
}

int main(int argc, char** argv)
{
    double coeff[3];

    double x1[2];
    double x2[2];

    coeff[0] = -0.5;
    coeff[1] = 5.3;
    coeff[2] = 7;

    print_quadratic(coeff);

    quadratic_roots(coeff,x1,x2);

    printf("\nx1 = ");
    print_complex(x1);
    printf("\nx2 = ");
    print_complex(x2);

    printf("\n\n");

    coeff[0] = 2;
    coeff[1] = 1;
    coeff[2] = 7;

    print_quadratic(coeff);

    quadratic_roots(coeff,x1,x2);

    printf("\nx1 = ");
    print_complex(x1);
    printf("\nx2 = ");
    print_complex(x2);

        printf("\n\n");

    coeff[0] = 5;
    coeff[1] = 4;
    coeff[2] = 0;

    print_quadratic(coeff);

    quadratic_roots(coeff,x1,x2);

    printf("\nx1 = ");
    print_complex(x1);
    printf("\nx2 = ");
    print_complex(x2);

  return 0;
}
