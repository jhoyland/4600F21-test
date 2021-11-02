/*

QUESTION 2:

	write a function which will calculate the sin or 
	\cos using the series expansion. The user of the function should be
	 able to specify the the number of terms to calculate.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void expandcos(double x,int i)
{
double y = 0;
int s;
int n;
int m =-1;
int fact[i];
fact[0]=1;
for(s=1;s<=i;s++)
{
	fact[s] = s*fact[s-1];
	//printf("s = %i factorial = %i\n",s, fact[s]); 
}
for(s=0;s<20;s++)
 {
 	if(s % 2 == 0)
 	{
 	m = m* -1;
 	n=fact[s];
 	y=m*pow(x,s)/n; // not switching from negative to positive 
 	printf("s = %i y = %f\n",s, y);
    }
 	else
 	{

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
