/*

QUESTION 1:
write a function which will return the roots of a quadriatic including complex roots, it should take in the coefficients A,B and C  and should return both roots it should be able to cope with both real and complex roots and if given A = 0 should return the root of the linear equation.

write a main function to use your function to find the roots of several polynomials, printing out the roots including if they are complex numbers.

you may have your function in the main.c file or create and link a separate file as you wish

*/

// ******************** MARK 10/10

// JAMES:  Good work!


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function that
void roots_func(float a, float b, float c, float * roots){

	//Case when coefficients make a linear function
	if (a==0) {
		roots[0]=-c/b;
	}

	//Case when coefficients make a quadratic function
	else{
		float b_=-b; //-b term
		float sqrt_=b*b-4.0*a*c; //value under the square root
		float denom=2.0*a;// denominator

		//case when value under square root is negative => imaginary roots
		if (sqrt_<0){
			roots[1]=sqrt(-sqrt_)/denom;//coefficient for imaginary part
			roots[0]=b_/denom;//real part
			roots[2]=2.0; //indicator of the case

		}
		else{//case when thee quadratic roots are real
			roots[0]=(b_+sqrt(sqrt_))/denom; //root #1
			roots[1]=(b_-sqrt(sqrt_))/denom; //root #2
			roots[2]=1.0; //indicator of the case
		}
	}
}

int main(int argc, char** argv)
{
	//Declaration of coefficients for the quadratic
	float a=5.0;
	float b=6.0;
	float c=5.0;

	//Array that will store the type of answer and appropriate roots
	float roots[3];

	//Calling function to perform necessary calculations
	roots_func(a,b,c,roots);

	//Print of answer for linear equation
	if (roots[2]==0){
		printf ("root of the equation     %fx + %f = 0     is: ",b,c);
		printf ("\n\t%f",roots[0]);
	}

	//Print of answer for quadratic equation with real roots;
	if (roots[2]==1.0){
		printf ("roots of the equation     %fx^2 + %fx + %f =0     are: ",a,b,c);
		printf ("\n\t%f",roots[0]);
		printf ("\n\t%f",roots[1]);
	}

	//Print of answer for quadratic equation with imaginary roots;
	if (roots[2]==2.0){
		printf ("roots of the equation     %fx^2 + %fx + %f = 0     are: ",a,b,c);
		printf ("\n\t%f + %f(i)",roots[0],roots[1]);
		printf ("\n\t%f - %f(i)",roots[0],roots[1]);
	}
	return 0;
}
