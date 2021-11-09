/*

QUESTION 2:

	write a function which will calculate the sin or
	\cos using the series expansion. The user of the function should be
	 able to specify the the number of terms to calculate.
*/

// ****************** MARK: 8/10



#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*JAMES: Again the function should generally return the value of sin or cosine.
printf functions inside a function like this are to be avoided: it means
the function can only really be used in a program designed for running in a
terminal window.*/

void expandcos(double x,int i)
{
double y = 0;
int s;
int n;
int m =-1;
int fact[i];
fact[0]=1;
for(s=1;s<=i;s++)  /*JAMES: This is quite a nice way to do the factorials since
in this application you do actually want all of them*/
{
	fact[s] = s*fact[s-1];
	//printf("s = %i factorial = %i\n",s, fact[s]);
}
/*JAMES: You've hardcoded the number of terms here meaning that if i is not 20
the function will not work as intended */
for(s=0;s<20;s++)
 {
 	if(s % 2 == 0) // JAMES: Since you are skipping every other, you could put s+=2 instead of s++ in the for statement
 	{
 	m = m* -1;
 	n=fact[s];
 	y=m*pow(x,s)/n; // not switching from negative to positive
 	printf("s = %i y = %f\n",s, y);
    }
 	else
 	{
		/* JAMES:you don't need the else section if it's empty */
 	}

//printf("cos(%f) = %f\n",x,y);
}
printf("cos(%0.2f) = %0.2f\n",x,y);
}

void expandsin(double x, int i)
{
double y=0;
int s;
int n;
int m = -1;
double fact[i];
fact[0]=1;
for(s=1;s<=i;s++)
{
	fact[s] = s*fact[s-1];
	//printf("s = %i factorial = %i\n",s, fact[s]);
}
for(s=1;s<i;s++)
 {
 	if(s % 2 == 0)
 	{

    }
 	else
 	{
 	m = m* -1;
	n=fact[s];
 	y=y+m*pow(x,s)/n;
 	}

//printf("cos(%f) = %f\n",x,y);
}
printf("sin(%0.2f) = %0.2f\n",x,y);
}


int main(int argc, char** argv)
{
expandcos(3.14,20);
expandsin(3.14,20);

  return 0;
}
