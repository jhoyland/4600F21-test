/*

QUESTION 1:
write a function which will return the roots of a quadriatic including complex roots, it should take in the coefficients A,B and C  and should return both roots it should be able to cope with both real and complex roots and if given A = 0 should return the root of the linear equation.

write a main function to use your function to find the roots of several polynomials, printing out the roots including if they are complex numbers.

you may have your function in the main.c file or create and link a separate file as you wish

*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void findRoots(double A, double B, double C, double *x)
{

  if (A==0)
  {
    x[0] = -C/B;
  }
  else
  {
    double firstPart = B*B - 4*A*C;
    if (firstPart > 0)
    {
      x[0] = (-B + sqrt(firstPart))/(2*A);
      x[1] = (-B - sqrt(firstPart))/(2*A);
    }
    else
    {
      x[0] = -B /(2*A);
      x[1] = sqrt(-firstPart);
      x[2] = 1;
    }

  }

}

int main(int argc, char** argv)
{
  double A[5] = {-4,-4,-8,-6,-56};
  double B[5] = {-5,-5,-34,25,2};
  double C[5] = {-9,-9,8,9,10};


  for(int i = 0; i < 5;i++ )
  {
    double x[3]={0,0,0};
    findRoots(A[i],B[i],C[i],x);

    if (x[1]==0)
    {
      printf("x = %g \n", x[0]);
    }
    else if (x[2]==0)
    {
      printf("x = %g and %g \n", x[0], x[1]);
    }
    else
    {
    printf("x = %g + %gi and %g - %gi \n", x[0], x[1], x[0], x[1]);
    }
  }







  return 0;
}
