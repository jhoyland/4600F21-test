/*

QUESTION 2:

	write a function which will calculate the sin or cos using the series expansion. The user of the function should be able to specify the the number of terms to calculate.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// JAMES: Good work! The only improvement I could suggest:
// Think about how each term could be calculatd from the previous one - this will
// save some time in calculating the factorial


//calcualtes factorial of a given number
double fact(int i){
	double j=2.0; // smallest value that can be given to this function is 2 (1st term in cos expansion)
	double value=1.0;
	while (j<=i){ //multiplies (2)*(3)*(4)*...*(i-2)*(i-1)*(i)
		value=value*j;
		j=j+1;
	}
	return(value);
}

//calculates individual terms of the expansion starting with 1st (0th already known)
double term(float x, int i){
	double numer=pow(x,i); //raises x to power
	double denom=fact(i); // calss and stores result of factorial function
	return (numer/denom);
}

//calculates the values of the entire sine expansion
double sin_expansion(double x, int n){
	int i=1; //the values of 0th terms need-not to be calculated w/ expressions
	double answer=x; // expansion always begin with x
	while (i<n){
		if (i%2==1){
			answer=answer-term(x,i*2+1); // every odd term is negative (starting at 0th)
		}
		else{
			answer=answer+term(x,i*2+1); // every even term is positive (starting at 0th)
		}
		i=i+1;
	}
	return answer;
}

//calculates the values of the entire cosine expansion
double cos_expansion(double x, int n){
	int i=1; //the values of 0th terms need-not to be calculated w/ expressions
	double answer=1; // expansion always begin with 1
	while (i<n){
		if (i%2==1){
			answer=answer-term(x,i*2); // every odd term is negative (starting at 0th)
		}
		else{
			answer=answer+term(x,i*2); // every even term is positive (starting at 0th)
		}
		i=i+1;
	}
	return answer;
}

int main(int argc, char** argv)
{

	double x=10.0; // value of x to for sin & cos
	int n=30; //number of terms in the expansion

	double expans_sin= sin_expansion(x,n); //calling and storing the expansion of sin at n terms for given x
	double expans_cos= cos_expansion(x,n); //calling and storing the expansion of cos at n terms for given x
	double true_sin= sin(x); //true value of sin for comparrison
	double true_cos= cos(x); //true value of cos for comparrison

	printf("\n\n\nexpansion of sin(%lf) at %i terms  : %lf",x,n,expans_sin);
	printf("\nactual value of sin(%lf) function : %lf\n",x,true_sin);
	printf("\nexpansion of cos(%lf) at %i terms  : %lf",x,n,expans_cos);
	printf("\nactual value of cos(%lf) function : %lf\n\n\n",x,true_cos);
	return 0;
}
