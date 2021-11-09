/*

QUESTION 2:

	write a function which will calculate the sin or cos using the series expansion. The user of the function should be able to specify the the number of terms to calculate.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double factorial(int num)								//function to calculate the factorial
{
	double result = 1;

	if (num !=0)
	{
		for (int i=1;i <= num; i++)

		{
			result = result * i;
		}
	}
	return result;

}

double cosExpansion(double x, int terms)
{
	double result = 0;

// JAMES: this is where your infinite loop is coming in:
// if you want to increment i by 2 each step you must put
// i+=2 .  i+2 does not change i, just returns its current value plus 2.
// so your i doesn't change from cycle to cycle and so never reaches 'terms'

	for (int i=1; i < terms; i+2)
	{
		result = result + pow(-1,i-1)*pow(x,i-1)/factorial(i-1);
	}

	return result;
}

double sinExpansion(double x, int terms)
{
	double result = x;
	for (int i=1; i < terms; i+2)
	{
		result = result + pow(-1,i)*pow(x,i)/factorial(i);
	}

	return result;
}


int main(int argc, char** argv)
{
	int terms = 0;
	double x = 1/2; // JAMES: Careful, this will likely calculate 1/2 as integer division and
	// so set x to 0. Either write 1.0 / 2.0 or better still just 0.5

	double cosResult = 0;
	double sinResult = 0;

	printf("Cos and Sin series expansion, how many terms would you like? ");
	fflush(stdout);
	scanf("%d",&terms);

	cosResult = cosExpansion(x,terms);    //for some reason the program keeps getting stuck here an will not move on
	sinResult = sinExpansion(x,terms);

	printf("\nCos espansion is = %g", cosResult);
	printf("\nSin expansion is = %g", sinResult);


  return 0;
}
