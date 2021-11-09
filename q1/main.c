/*

QUESTION 1:
write a function which will return the roots of a quadriatic including complex roots, it should take in the coefficients A,B and C  and should return both roots it should be able to cope with both real and complex roots and if given A = 0 should return the root of the linear equation.

write a main function to use your function to find the roots of several polynomials, printing out the roots including if they are complex numbers.

you may have your function in the main.c file or create and link a separate file as you wish

*/

// ******************** MARK: 9/10

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*JAMES: Good generally it's prefeable though to keep the printf statements
out of the function. It allows the function to be used in a wider variety of
contexts.*/

double Root(double* X, double A, double B, double C)
{
	double x1, x2, x;
	double imgcheck;
	double img1, img2;
	//solve for simplest case first if possible  JAMES: Good!
	if(A == 0)
	{
		x = -(C/B);
		printf("\nThe root of the quadratic is %5.2f \n",x);
		printf("There is no secondary root.\n");
		X[0] = x;
		return 0;
	}
	else
	{
		//check for imaginary by way of square root, if negative then complex solution
		imgcheck = pow(B,2) - (4*A*C);
		//case for non-imaginary solutions
		if(imgcheck >= 0)
		{
			x1 = (-B + sqrt(imgcheck))/(2*A);
			x2 = (-B - sqrt(imgcheck))/(2*A);
			printf("\nThe roots of the quadratic equation are real and are %5.2f and %5.2f \n",x1,x2);
			X[0] = x1;
			X[1] = x2;
			return 0;
		}
		//the case for imaginary solutions
		else
		{
			x1 = (-B /(2*A));
			x2 = (-B /(2*A));
			img1 = (sqrt(-1*imgcheck)/(2*A));
			img2 = (sqrt(-1*imgcheck)/(2*A));
			printf("\nThe roots of this quadratic equation are imaginary and are: \n %5.2f + i%5.2f and %5.2f - i%5.2f \n",x1,img1,x2,img2);
			img2 = -(sqrt(-1*imgcheck)/(2*A));
			X[0] = x1;
			X[1] = img1;
			X[2] = x2;
			X[3] = img2;

			/*
			JAMES: Good, the only change I might have made is to have the real parts x1,x2 be at the same
			location in the 'X' array whether returning real or complex - so X[0] = x1 and X[2] = x2
			with then X[1] and X[3] both equalling zero for the real root case. It keeps it more consistent
			between cases.
			*/

			return 0;
		}
	}

}

int main(int argc, char** argv)
{
	//test the function
	//first, test simplest case:
	double A = 0.0;
	double B = 2.0;
	double C = 4.0;
	printf("The quadratic equation is %5.2fx^2 + %5.2fx + %5.2f",A,B,C);
	double X[20];  // JAMES: Is there a reason you made it 20? - your function only uses 4 elements.
	// the function already does the printing for me.
	Root(X,A,B,C);
	printf("The function returns %5.2f \n\n",X[0]);


	//then, real roots
	A = 8.0;
	B = 20.0;
	C = 3.0;
	double X1,X2;
	printf("The quadratic equation is %5.2fx^2 + %5.2fx + %5.2f",A,B,C);
	Root(X,A,B,C);
	printf("The function returns %5.2f, %5.2f \n\n",X[0],X[1]);

	//then, imaginary roots
	A = 5.0;
	B = 6.0;
	C = 7.0;
	double X3,X4,X5,X6;
	printf("The quadratic equation is %5.2fx^2 + %5.2fx + %5.2f",A,B,C);
	Root(X,A,B,C);
	printf("The function returns %5.2f, %5.2f, %5.2f, %5.2f \n\n",X[0],X[1],X[2],X[3]);
	fflush(stdout);
	return 0;
}
