#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*

QUESTION 2:

	write a function which will calculate the sin or cos using the series expansion. The user of the function should be able to specify 
	the number of terms to calculate.
*/

double factorioCalc(double number)
{
	if(number > 1)return number * factorioCalc(number-1);
	else return 1.0;
}

double sinCalc(double x, int terms)
{
	double answer = 0.0;
	int expNum = 3;
	
	for(int i = 0; i < terms; i++)
	{
		if(i == 0)
		{
			answer += x;
		}

		else
		{
			answer += pow(-1,i) * pow(x, 2*i+1) / factorioCalc(2*i+1);
		}
	}

	return answer;
}

double cosCalc(double x, int terms)
{
	double answer = 0.0;
	int expNum = 2;
	
	for(int i = 0; i < terms; i++)
	{
		if(i == 0)
		{
			answer += 1.0;
		}

		else
		{
			answer += pow(-1,i) * pow(x, 2*i) / factorioCalc(2*i);
		}
	}

	return answer;
}

int main(int argc, char** argv)
{
	double x = 2.9*M_PI;
	int terms = 50;

	double ans = sinCalc(x, terms);
	printf("The answer is %0.3f\n\n", ans);

	ans = cosCalc(x, terms);
	printf("The answer is %0.3f\n", ans);


  return 0;
}
