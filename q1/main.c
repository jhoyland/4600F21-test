#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

QUESTION 1:
write a function which will return the roots of a quadriatic including complex roots, it should take in the coefficients A,B and C  and should return both roots it should be able to cope with both real and complex roots and if given A = 0 should return the root of the linear equation.

write a main function to use your function to find the roots of several polynomials, printing out the roots including if they are complex numbers.

you may have your function in the main.c file or create and link a separate file as you wish

*/


/*
JAMES: Generally good job. However, your solution of sending status information in the
output array is not elegant. Mixing the returned data with the status in this way makes
the interface to the function not very intuitive for someone trying to use your function
A better way would have been to keep output for just the root values and have your
function return an integer to say what kind of root it found - e.g. 0 for linear
1 for real, 2  for complex.

*/

void findRoots(double A, double B, double C, double* output)
{
	double root1 = 0.0, root1C = 0.0, root2 = 0.0, root2C = 0.0;

	for(int i = 0; i < 6; i++)
	{
		output[i] = 0.0;
	}

	if(A != 0)
	{
		if((B*B - 4*A*C) < 0)
		{
			output[4] = 1.0;
			double num1 = (-B) / (2 * A);
			double num2 = -1 * (B*B - 4*A*C); // JAMES: You can just write -(B*B etc.. no need for the -1*

			root1 = (-B) / (2 * A);
			output[0] = root1;

			root1C = sqrt(num2) / (2 * A);
			output[1] = root1C;

			output[2] = root1;

			root2C = -1 * (sqrt(num2) / (2 * A));
			output[3] = root2C;
		}

		else
		{
			double num1 = (-B) / (2 * A);
			double num2 = sqrt(B*B - 4*A*C) / (2 * A);

			root1 = num1 + num2;
			output[0] = root1;

			root2 = num1 - num2;
			output[2] = root2;
		}
	}

	else
	{
		output[5] = 1.0;
		root1 = -C/B;
		output[0] = root1;
	}
}

int main(int argc, char** argv)
{
	double A = 1.0;
	double B = 2.0;
	double C = 6.0;
	double output[6];

	findRoots(A, B, C, output);

	if(output[5] == 1.0)
	{
		printf("The root of your linear equation is%f\n", output[0]);
	}

	else
	{
		if(output[4] == 1.0)
		{
			printf("The roots of your quadriatic function are complex\nRoot 1 is %0.3f + %0.3fi\nRoot 2 is %0.3f + %0.3fi\n",output[0], output[1], output[2], output[3]);
		}

		else
		{
			printf("The roots of your quadriatic function are real\nRoot 1 is %0.3f \nRoot 2 is %0.3f\n",output[0], output[2]);
		}
	}



  return 0;
}
